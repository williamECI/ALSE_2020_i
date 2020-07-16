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
#include <sqlite3.h>

using namespace std;

class DB_local{

    public:


        bool guardar_dato(Dato &b, const int &hor, const int &min);
        bool abrir_DB();
        bool cerrar_DB();
        bool crear_DB();
        bool borrar_DB();
        Dato getdato_minuto( const int &h, const int &m);
        Dato getPromedio(int h);

    private:
        sqlite3 *ddb;
        string path;
};

#endif //_DB_LOCAL_H
