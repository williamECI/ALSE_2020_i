

#ifndef _ESTACION_METEO_H
#define _ESTACION_METEO_H

#include "estacion_interface.h"
#include "DB_local.h"
#include "DB_remota.h"
#include "Muestreador.h"
#include <ctime>
#include <string>
#include <iostream>
#include <QTimer>



#define INTERVAL_M 5
#define NUM_MUESTRAS_M 12
#define NUM_MUESTRAS_H 60
#define INTERVAL_DIA 24

class Estacion_meteo : public QObject
{

    Q_OBJECT

public:
    Estacion_meteo (std::time_t fecha,int hora, int minuto);
    Estacion_meteo ();
    bool iniciar_toma_datos();
    bool deterner_toma_datos();
    bool reporteDiario();
    bool abrirGUI(Dato d, int dia);
    bool cerrarGUI();


private:
   Estacion_interface interface;

   Muestreo muestra;
   DB_local *db_local;
   DB_remota *db_remota;

   std::time_t _fecha;
   int _dia;
   int _hora;
   int _minuto;
   QTimer *timer1;
   QTimer *timer2;
   std::string _nombre;
   std::string _ubicacion;
   std::string _usrname;
   std::string _password;

   int _num_datos;


private slots:
   void alarma_5_segundos(void);
   void alarma_24_horas(void);


};
#endif
