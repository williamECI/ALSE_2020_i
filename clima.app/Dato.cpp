#include <iostream>
#include "Dato.h"

Dato::Dato(float t = 0., unsigned char h = 0, float v = 0., int d = 0, double la = 0., double lo = 0., double a = 0. ){
    _temperatura = t;
    _humedad = h;
    _veloviento = v;
    _dirviento = d;
    _latitud = la;
    _longitud = lo;
    _altura = a;
}