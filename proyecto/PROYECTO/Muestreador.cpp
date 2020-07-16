#include "Muestreador.h"
#include "Dato.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
Muestreo::Muestreo(){
    _indice = 0;
}

bool Muestreo::tomarDato()
{

    Dato d(this->sensor_temperatura(),this->sensor_humedad(),this->sensor_vel_viento(),this->sensor_dir_viento()
           ,this->GPS_latitud(),this->GPS_longitud(),this->GPS_altura());
    
    if(_indice < NUM_MUESTRAS_M ){
        _datos[_indice] = d;
    }
    _indice++;
    
}

Dato Muestreo::promedio()
{
   Dato pr;
   float t= 0.,v = 0.;
   int dv =0;
   double lo= 0.,la= 0.,a = 0.;

   for (int i = 0; i < NUM_MUESTRAS_M ; i++){

       a  += _datos[i].getAltura();
       dv += _datos[i].getDirviento();
       la += _datos[i].getLatitud();
       lo += _datos[i].getLongitud();
       t  += _datos[i].getTemperatura();
       v  += _datos[i].getVeloviento();
   }
   pr.setAltura(a/NUM_MUESTRAS_M);
   pr.setDirviento(dv/NUM_MUESTRAS_M);
   pr.setLatitud(la/NUM_MUESTRAS_M);
   pr.setLongitud(lo/NUM_MUESTRAS_M);
   pr.setTemperatura(t/NUM_MUESTRAS_M);
   pr.setVeloviento(v/NUM_MUESTRAS_M);

   return pr;
}

float Muestreo::sensor_temperatura()
{
    srand(time(NULL));
    float t = 0. + rand() / (1. - 63.);
    //float t = -89.2 + rand() / (-88.2 - 63);
    return t;
}

float Muestreo::sensor_vel_viento()
{
    float v = 0. + rand() / (1. - 372.);
    //float v = 0 + rand() / (1 - 372);
    return v;
}

int Muestreo::sensor_dir_viento()
{
    int dv = 0 + rand() % (1 - 360);
    return dv;
}

unsigned char Muestreo::sensor_humedad()
{
    unsigned char h = 0 + rand() % (1 - 100);
    return h;
}

double Muestreo::GPS_latitud()
{
    double la = -90.0+ rand() / (-89.0- 90.0);
    //double la = -90.0000000 + rand() / (-89.9999999 - 90.0000000);
    return la;
}

double Muestreo::GPS_longitud()
{
    double lo = -180.0 + rand() / (-179.0+ 180.0);
    //double lo = -180.0000000 + rand() / (-179.9999999+ 180.0000000);
    return lo;
}

double Muestreo::GPS_altura()
{
    double a = 0. + rand() / (1. + 8848.00);
    //double a = -417 + rand() / (-416.99 + 8848.00);
    return a;
}






