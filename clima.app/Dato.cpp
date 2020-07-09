#include <iostream>
#include "Dato.h"

using namespace std;

Dato::Dato(float t , unsigned char h, float v , int d, double la, double lo, double a ){
    _temperatura = t;
    _humedad = h;
    _veloviento = v;
    _dirviento = d;
    _latitud = la;
    _longitud = lo;
    _altura = a;
}

ostream& operator<<(ostream& stream, Dato& dato) {
    stream  << "temperatura: " << dato.getTemperatura() << "   humedad: " << dato.getHumedad() <<
               "   velocidad del viento: " << dato.getVeloviento() << "   direción de viento: " << dato.getDirviento() <<
               "   latitud: " << dato.getLatitud() << "  longitud: " << dato.getLongitud() << "   altura: " <<
               dato.getAltura();

    return stream;
}
