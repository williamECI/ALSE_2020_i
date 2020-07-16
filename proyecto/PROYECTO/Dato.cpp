#include <iostream>
#include "Dato.h"

Dato::Dato(float t , unsigned char h , float v , int d , double la , double lo , double a  ){
    _temperatura = t;
    _humedad = h;
    _veloviento = v;
    _dirviento = d;
    _latitud = la;
    _longitud = lo;
    _altura = a;
}

Dato::Dato(){
    _temperatura = 0.;
    _humedad = 0;
    _veloviento = 0.;
    _dirviento = 0;
    _latitud = 0;
    _longitud = 0;
    _altura = 0;
}



ostream& operator<<(ostream& stream, Dato& dato) {
    stream  << "temperatura: " << dato.getTemperatura() << "   humedad: " << dato.getHumedad() <<
               "   velocidad del viento: " << dato.getVeloviento() << "   direción de viento: " << dato.getDirviento() <<
               "   latitud: " << dato.getLatitud() << "  longitud: " << dato.getLongitud() << "   altura: " <<
               dato.getAltura();

    return stream;
}

