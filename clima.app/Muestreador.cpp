
#include "Muestreador.h"
#include "Dato.h"
#include <iostream>
/*
bool Dato::tomarDato(){
    if (h = 0 && l = 0 && t = 0 && v = 0 && d = 0 && la = 0 && lo = 0 && a = 0 ){
       return false;
        
    }
    
    else{
        return true;
        
    }
}
*/

Dato Muestreador::promedio ( ) {
    Dato dato_promedio;

    for (int i = 0; i < 12; i++){
        this->_datos[i].getAltura()

        float tp += ( vector[i].getTemperatura() / 12 );
        dato_promedio.setTemperatura(tp);

        unsigned chat hp += ( vector[i].getHumedad() / 12 );
        dato_promedio.setHumedad(hp);

        float vp += ( vector[i].getVeloviento() / 12 );
        dato_promedio.setVeloviento(vp);

        int dp += ( vector[i].getDirviento() / 12 );
        dato_promedio.setDirviento(dp);

        double lap += ( vector[i].getLatitud() / 12 );
        dato_promedio.setLatitud(lap);

        double lop += ( vector[i].getLongitud() / 12 );
        dato_promedio.setLongitud(lop);

        double ap += ( vector[i].getAltura() / 12 );
        dato_promedio.setAltura(ap);
        }

    return dato_promedio;


}

