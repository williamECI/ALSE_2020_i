/**
 * Project Untitled
 */

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdlib.h>
#include "DB_local.h"
#include "Dato.h"


static int DB_local::callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
bool DB_local::guardar_dato(Dato d, int h, int m)
{
    abrir_DB();

    ejecutar_DB();
    cerrar_DB();
}
bool DB_local::abrir_DB()
{
    sqlite3 *ddb;
    int rc;
    rc = sqlite3_open("DB_local.db", &ddb);

    if( rc ) {
        fprintf(stderr, "No es posible abrir la base de datos: %s\n", sqlite3_errmsg(ddb));
        return (0);
    }
    else {
        return (1);
    }
}
bool DB_local::cerrar_DB()
{
    sqlite3 *ddb;
    sqlite3_close(ddb);
    return ;
}
bool DB_local::ejecutar_DB()
{
    callback();
    sqlite3 *ddb;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    rc = sqlite3_exec(ddb, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
       fprintf(stderr, "No es posible ejecutar la base de datos: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
       return (0);
    }
    else {
        return (1);
    }
}
bool DB_local::crear_DB()
{

}
bool DB_local::borrar_dato(Dato d)
{
    char *sql;
    abrir_DB();
    sql = "DELETE from user where **********; " \
          "SELECT * from **********";
    ejecutar_DB();
    cerrar_DB();
    return ;
}
Dato DB_local::getdato_minuto(int h, int m)
{

}
Dato DB_local::getdato(int h, int m, int s)
{

}
Dato DB_local::getPromedio(int h)
{

}
