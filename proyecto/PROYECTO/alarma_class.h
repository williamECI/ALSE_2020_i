#ifndef ALARMA_CLASS_H
#define ALARMA_CLASS_H

#include <QObject>
#include <QTimer>
#include <iostream>

class Alarma:public QObject{
    Q_OBJECT


public:
    bool activar_Alarma ();
    void conexion( QTimer &t){connect(&t, SIGNAL( timeout() ), this, SLOT( alarma() ) );}

public slots:
    void alarma(){ std::cout << "Tiempo finalizado" << std::endl;}
};

#endif // ALARMA_CLASS_H


