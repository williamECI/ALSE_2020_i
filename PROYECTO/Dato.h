#ifndef _DATO_H
#define _DATO_H

#include <iostream>


using namespace std;

class Dato{
public:

    Dato (float t, unsigned char h , float v , int d , double la , double lo , double a  );
    Dato();

    void setTemperatura (float t){_temperatura = t;}
    float getTemperatura () { return _temperatura; }

    void setHumedad (unsigned char h) { _humedad = h; }
    unsigned char getHumedad () { return _humedad; }

    void setVeloviento (float v) { _veloviento = v; }
    float getVeloviento () { return _veloviento; }

    void setDirviento (int d) { _dirviento = d; }
    int getDirviento () { return _dirviento; }

    void setLatitud (double la) { _latitud = la; }
    double getLatitud () { return _latitud; }

    void setLongitud (double lo) { _longitud = lo; }
    double getLongitud () { return _longitud; }

    void setAltura (double a) { _altura = a; }
    double getAltura () { return _altura; }

    friend ostream& operator<<(ostream& stream, Dato& dato);

private:

    float _temperatura;
    unsigned char _humedad;
    float _veloviento;
    int _dirviento;
    double _latitud;
    double _longitud;
    double _altura;

};


#endif
