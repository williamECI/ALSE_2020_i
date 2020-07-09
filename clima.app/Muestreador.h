#ifndef _MUESTREO_H
#define _MUESTREO_H

#include <iostream>
#include "Dato.h"

using namespace std;

class Muestreador {
public:
    bool tomarDato();
    std::Dato promedio();
    Dato vector[12];
    void setTamanio (int t) {_tamanio = t; };
    int getTamanio () {return _tamanio; };



private:
    int _tamanio;




};

#endif
