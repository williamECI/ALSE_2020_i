#ifndef _MUESTREO_H
#define _MUESTREO_H

#include <iostream>
#include "Dato.h"

class Muestreo {
public:
    bool tomarDato();
    Dato::Dato promedio();
    Dato::Dato vector[12];

private:
    int _tamaño;
    Dato::Dato vector[12];



}
#endif
