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


bool DB_local::guardar_dato(Dato &b, const int &hor, const int &min)

{
    abrir_DB();

    stringstream sqlstream;
    int rc;
    char *zErrMsg = 0;

    sqlstream << "INSERT INTO TBL_SENSORES ( Hora, Minuto, Temperatura, Humedad, Velo_viento, Dir_viento, Latitud, Longitud, Altura )";
    sqlstream << "VALUES (";
    sqlstream << hor << ", " << min << ", ";
    sqlstream << b.getTemperatura() << ", ";
    sqlstream << b.getHumedad() << ", ";
    sqlstream << b.getVeloviento() << ", ";
    sqlstream << b.getDirviento() << ", ";
    sqlstream << b.getLatitud() << ", ";
    sqlstream << b.getLongitud() << ", ";
    sqlstream << b.getAltura() << " );";

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


Dato DB_local::getdato_minuto( const int &h,  const int &m)
{

   stringstream sqlstream;
   int rc;
   const char* data = "Callback function called";
   char *zErrMsg = 0;

   abrir_DB();

   sqlstream << "SELECT from TBL_SENSORES WHERE Hora = " << h "AND Minuto = " << m ;

   string sql ( sqlstream.str() );

   rc = sqlite3_exec(ddb, sql.c_str(), callback, (void*)data, &zErrMsg);

   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");

   cerrar_DB();
}
}

bool DB_local::crear_DB(){


    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    abrir_DB();

    sqlstr = "CREATE TABLE TBL_SENSORES2 (Hora REAL PRIMARY KEY NOT NULL, Minuto REAL PRIMARY KEY NOT NULL, Temperatura REAL NOT NULL," \
       "Humedad INTEGER NOT NULL, Velo_viento REAL NOT NULL," \
       "Dir_viento REAL NOT NULL, Latitud REAL NOT NULL, Longitud REAL NOT NULL, Altitud REAL NOT NULL );";

    /* Execute SQL statement */
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
    string sql;
    char *zErrMsg = 0;
    const char* data = "Callback function called";

    abrir_DB();

    sql = "DELETE from TBL_SENSORES WHERE hora !=66; ";


    rc = sqlite3_exec(ddb, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Operation done successfully\n");
    }
}


