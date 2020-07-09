
#include "Muestreador.h"
#include "Dato.h"
#include <iostream>
/*
bool Dato::tomarDato(){
    if (h = 0 && l){
        
    }
    
    else{
        
    }
}
*/
Dato Muestreador::promedio ( Dato vector[12] ) {
    Dato dato_promedio;

    for (int i = 0; i < 12; i++){

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

