/**
 * Project Untitled
 */


#ifndef _DB_LOCAL_H
#define _DB_LOCAL_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdlib.h>
#include "DB_local.h"
#include "Dato.h"


using namespace std;

class DB_local{

    public:
        static int callback(void *data, int argc, char **argv, char **azColName);
        bool guardar_dato(Dato d, int h, int m);
        bool abrir_DB();
        bool cerrar_DB();
        bool ejecutar_DB();
        bool crear_DB(char n_DB);
        bool borrar_dato(Dato d);
        Dato getdato_minuto(int h, int m);
        Dato getdato(int h, int m, int s);
        Dato getPromedio(int h);
    private:

        string path;
};

#endif //_DB_LOCAL_H
