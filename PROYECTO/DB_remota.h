/**
 * Project Untitled
 */


#ifndef _DB_REMOTA_H
#define _DB_REMOTA_H

#include <iostream>
#include <mysql/mysql.h>
#include "DB_remota.h"
#include "Dato.h"

using namespace std;

class DB_remota{

    public:

        DB_remota();
        bool conectar_DB();
        bool desconectar_DB();
        bool guardar_dato(Dato d, int h);
        bool create_table();
        bool delete_table();

    private:

        MYSQL *connection, mysql;

};

#endif //_DB_REMOTA_H

