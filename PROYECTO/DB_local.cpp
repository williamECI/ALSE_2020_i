/**
 * Project Untitled
 */

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdlib.h>
#include "DB_local.h"
#include "Dato.h"
#include <stdio.h>
#include <sstream>



bool DB_local::abrir_DB()
{

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;

    rc = sqlite3_open("DB_local.db", &db);
    this->ddb = db;

    if( rc ) {
       fprintf(stderr, " Can't open database: %s\n", sqlite3_errmsg(db));
       return(0);
    } else {
       fprintf(stderr, "Opened database successfully\n");
    }
}


bool DB_local::cerrar_DB()
{
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_close(ddb);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "database close successfully\n");
    }

}


DB_local::DB_local()
{

}

bool DB_local::guardar_dato(Dato &b, const int &hor, const int &min)

{
    abrir_DB();

    stringstream sqlstream;
    int rc;
    char *zErrMsg = 0;

    sqlstream << "INSERT INTO TBL_SENSORES ( Hora, Minuto, Temperatura, Humedad, Velo_viento, Dir_viento, Latitud, Longitud, Altura ) ";
    sqlstream << "VALUES (";
    sqlstream << hor << ", " << min << ", ";
    sqlstream << b.getTemperatura() << ", ";
    sqlstream << (int)b.getHumedad() << ", ";
    sqlstream << b.getVeloviento() << ", ";
    sqlstream << b.getDirviento() << ", ";
    sqlstream << b.getLatitud() << ", ";
    sqlstream << b.getLongitud() << ", ";
    sqlstream << b.getAltura() << " );";

    //std::cout << sqlstream.str() << std::endl;

    string sql ( sqlstream.str() );


    rc = sqlite3_exec(ddb, sql.c_str(), NULL, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    cerrar_DB();

}

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}

static int callback_gd(void *data, int argc, char **argv, char **azColName){
   Dato *gd = (Dato*) data;
   fprintf(stderr, "%s: ", (const char*)data);


   gd->setTemperatura(atof(argv[0]));
   gd->setHumedad( (unsigned char) *argv[1] );
   gd->setVeloviento(atof(argv[2]));
   gd->setDirviento(atoi(argv[3]));
   gd->setLatitud(atof(argv[4]));
   gd->setLongitud(atof(argv[5]));
   gd->setAltura(atof(argv[6]));


    /*
   std::cout<<"----------PROMEDIO CALLBACK-------------"<<std::endl;
   std::cout<<"Temperatura:      "<<gd->getTemperatura()<<std::endl;
   std::cout<<"Humedad:          "<<gd->getHumedad()<<std::endl;
   std::cout<<"Velocidad Viento: "<<gd->getVeloviento()<<std::endl;
   std::cout<<"Direccion Viento: "<<gd->getDirviento()<<std::endl;
   std::cout<<"Latitud:          "<<gd->getLatitud()<<std::endl;
   std::cout<<"Longitud:         "<<gd->getLongitud()<<std::endl;
   std::cout<<"Altura:           "<<gd->getAltura()<<std::endl;
   std::cout<<"---------------------------------------"<<std::endl;
   std::cout<<" "<<std::endl;
    */


   printf("\n");
   return 0;
}

Dato DB_local::getdato_promedio_hora( const int &h)
{

   stringstream sqlstream;
   int rc;
   Dato gd;
   //const char* data = "Callback function called";
   char *zErrMsg = 0;

   abrir_DB();

   sqlstream << "SELECT   Hora, AVG(Temperatura), AVG(Humedad), AVG(Velo_viento), AVG(Dir_viento), AVG(Latitud), AVG(Longitud), AVG(Altura) FROM TBL_SENSORES  WHERE Hora = " ;
   sqlstream << h << ";" ;

   string sql ( sqlstream.str() );


   rc = sqlite3_exec(ddb, sql.c_str(), callback_gd, (void*) &gd, &zErrMsg);

   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else
      fprintf(stdout, "Operation done successfully\n");


   cerrar_DB();
   return gd;
}





bool DB_local::crear_DB(){


    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    abrir_DB();

    sqlstr = "CREATE TABLE TBL_SENSORES (Hora REAL NOT NULL, Minuto REAL NOT NULL, Temperatura REAL NOT NULL," \
       "Humedad INTEGER NOT NULL, Velo_viento REAL NOT NULL," \
       "Dir_viento REAL NOT NULL, Latitud REAL NOT NULL, Longitud REAL NOT NULL, Altura REAL NOT NULL );";


    rc = sqlite3_exec(ddb, sqlstr.c_str(), callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Table created successfully\n");
    }

    cerrar_DB();



}

bool DB_local::borrar_DB(){

    int rc;
    char *sql;
    char *zErrMsg = 0;

    abrir_DB();

    sql = "DELETE FROM TBL_SENSORES;";


    rc = sqlite3_exec(ddb, sql, NULL, 0, &zErrMsg);


    if( rc != SQLITE_OK ) {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Operation done successfully\n");
    }
}


