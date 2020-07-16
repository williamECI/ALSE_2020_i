#include <QCoreApplication>
#include <QTimer>
#include <alarma_class.h>
#include <unistd.h>
#include <iostream>
#include "alarma_class.h"

#define INTER 5


bool Alarma::activar_Alarma()
{
    QCoreApplication a(int argc, char *argv[]);
    QTimer t;
    Alarma al;
    t.setInterval(1000 * INTER);
    al.conexion( t );
    t.start();

    usleep(5000000);

    return true;
}
