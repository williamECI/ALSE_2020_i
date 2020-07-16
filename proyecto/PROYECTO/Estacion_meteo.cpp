#include "Estacion_meteo.h"
#include "Muestreador.h"
#include "alarma_class.h"
#include "Dato.h"
#include "DB_local.h"

#include <iostream>

Estacion_meteo::Estacion_meteo(time_t fecha, int hora, int minuto)
{
    this->_num_datos = 0;

    this->_fecha = fecha;
    this->_hora = hora;
    this->_minuto = minuto;

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),this, SLOT(alarma_5_segundos()));
    connect(timer2, SIGNAL(timeout()),this, SLOT(alarma_24_horas()));

}

Estacion_meteo::Estacion_meteo()
{

}

bool Estacion_meteo::iniciar_toma_datos()
{

    timer1->setInterval(3.47222222222222222222);
    timer2->setInterval(1000*60);

    //timer1->setInterval(1000*INTERVAL_M);
    //timer2->setInterval(1000*INTERVAL_M*NUM_MUESTRAS_M*NUM_MUESTRAS_H*INTERVAL_DIA);
    timer1->start();
    timer2->start();

    return true;
}

bool Estacion_meteo::deterner_toma_datos()
{

}

bool Estacion_meteo::reporteDiario()
{

}

bool Estacion_meteo::abrirGUI()
{

}

bool Estacion_meteo::cerrarGUI()
{

}

void Estacion_meteo::alarma_5_segundos()
{


    Dato promedio_minuto;
    muestra.tomarDato();
    if (muestra.getIndice() == NUM_MUESTRAS_M){
        this->_num_datos++;
        promedio_minuto = muestra.promedio();
        muestra.setIndice(0);
        this->_minuto++;
        if (this->_minuto == 60) {
            this->_minuto = 0;
            this->_hora++;
            if (this->_hora == 25 || this->_minuto == 60){
                this->_minuto = 0;
                this->_hora   = 0;
            }
        }
        std::cout<<"Se  guardo un dato: "<<this->_num_datos<<"  "<<this->_hora<<":"<<this->_minuto<<std::endl;
        // /*
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<"Temperatura:      "<<promedio_minuto.getTemperatura()<<std::endl;
        std::cout<<"Humedad:          "<<promedio_minuto.getHumedad()<<std::endl;
        std::cout<<"Velocidad Viento: "<<promedio_minuto.getVeloviento()<<std::endl;
        std::cout<<"Direccion Viento: "<<promedio_minuto.getDirviento()<<std::endl;
        std::cout<<"Latitud:          "<<promedio_minuto.getLatitud()<<std::endl;
        std::cout<<"Longitud:         "<<promedio_minuto.getLongitud()<<std::endl;
        std::cout<<"Altura:           "<<promedio_minuto.getAltura()<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<" "<<std::endl;

        //DB_local c;
       // c.guardar_dato(promedio_minuto, 1, 2);




        //*/

    }


    timer1->start();
}

void Estacion_meteo::alarma_24_horas()
{
    timer1->stop();

    Dato promedio_hora;

     float t = 0.,v = 0.;
     int dv = 0;
     double lo = 0,la = 0,a = 0;

     for (int j = 1 ; j <= INTERVAL_DIA ; j++){
         for (int i = 1 ; i <= NUM_MUESTRAS_H ; i++){
             //promedio_hora = db_local->getdato_minuto(this->_hora,this->_minuto);
             a  += promedio_hora.getAltura() ;
             dv += promedio_hora.getDirviento();
             la += promedio_hora.getLatitud();
             lo += promedio_hora.getLongitud();
             t  += promedio_hora.getTemperatura();
             v  += promedio_hora.getVeloviento();
             std::cout<<" Temperatura: "<<t<<"  Ciclo: "<<i<<std::endl;
             this->_minuto++;
             if (this->_minuto == 59) {
                 this->_minuto = 0;
                 this->_hora++;
             }

         }
         promedio_hora.setAltura(a/NUM_MUESTRAS_H);
         promedio_hora.setDirviento(dv/NUM_MUESTRAS_H);
         promedio_hora.setLatitud(la/NUM_MUESTRAS_H);
         promedio_hora.setLongitud(lo/NUM_MUESTRAS_H);
         promedio_hora.setTemperatura(t/NUM_MUESTRAS_H);
         promedio_hora.setVeloviento(v/NUM_MUESTRAS_H);

         std::cout<<"GUARDAR EN BASE DE DATOS REMOTA  "<<j;
         std::cout<<" Temperatura: "<<promedio_hora.getTemperatura()<<std::endl;

         promedio_hora.setAltura(0);
         promedio_hora.setDirviento(0);
         promedio_hora.setHumedad(0);
         promedio_hora.setLatitud(0);
         promedio_hora.setLongitud(0);
         promedio_hora.setTemperatura(0.);
         promedio_hora.setVeloviento(0.);
     }
     //timer1->start();
     //timer2->start();


}

