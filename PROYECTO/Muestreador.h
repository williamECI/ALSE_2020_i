#ifndef _MUESTREO_H
#define _MUESTREO_H

#include <iostream>
#include <vector>
#include "Dato.h"
#include <stdlib.h>

#define NUM_MUESTRAS_M 12

class Muestreo {
public:
    Muestreo();
    bool tomarDato();
    Dato promedio();
    int getIndice(){return _indice;}
    void setIndice(int i){_indice = i;}

    //SENSORES
    float sensor_temperatura();
    float sensor_vel_viento();
    int sensor_dir_viento();
    unsigned char sensor_humedad();
    double GPS_latitud();
    double GPS_longitud();
    double GPS_altura();


private:
    int _indice ;
    //std::vector<Dato> _datos;
    Dato _datos[NUM_MUESTRAS_M ];

};
#endif
