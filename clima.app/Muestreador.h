#ifndef _MUESTREO_H
#define _MUESTREO_H

#include <iostream>
#include "Dato.h"

using namespace std;

class Muestreador {
public:
    bool tomarDato();
    Dato promedio();

    //void setTamanio (int t) {_tamanio = t; };
    //int getTamanio () {return _tamanio; };



private:
    Dato _datos[12];
    //int _tamanio;




};

#endif
