#include "Muestreador.h"
#include "Dato.h"
#include <iostream>

bool Dato::tomarDato(){
    if (h = 0 && v = 0 && d = 0 && la = 0 && lo = 0 && a = 0){
        return false;
    }

    else{
        return true;
    }
}


Dato::Dato promedio( vector ){

    Dato::Dato dato_promedio;

    int l = sizeof ( vector )/sizeof( *vector );

    for (int i = 0; i < l; i++){

        dato_promedio.setAltura() += vector[i].getAltura() ;
        dato_promedio.setHumedad() += vector[i].getHumedad() ;
        dato_promedio.setDirviento() += vector[i].getDirviento() ;
        dato_promedio.setLatitud()+= vector[i].getLatitud() ;
        dato_promedio.setLongitud()+= vector[i].getLongitud() ;
        dato_promedio.setTemperatura() += vector[i].getTemperatura() ;
        dato_promedio.setVeloviento(); += vector[i].getVeloviento() ;
    }


}
