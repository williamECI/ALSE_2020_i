#include <QtCore/QTimer>

#ifndef _ESTACION_METEO_H
#define _ESTACION_METEO_H

#include <DB_local.h>
#include <Muestreador.h>
#include <ctime>
#include <string>
#include <iostream>

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
    bool abrirGUI();
    bool cerrarGUI();


private:
   Muestreo muestra;
   DB_local *db_local;
   std::time_t _fecha;
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
