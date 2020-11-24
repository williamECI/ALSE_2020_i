#include "Estacion_meteo.h"
#include "Muestreador.h"
#include "Dato.h"
#include "DB_local.h"
#include "estacion_interface.h"
#include <iostream>

Estacion_meteo::Estacion_meteo(time_t fecha, int hora, int minuto)
{    
    this->_nombre = "Estación meteorológica ECI";
    this->_ubicacion = "";
    this->_usrname = "EMB1ECI";
    this->_password = "EM1B_ECI@2020";

    this->_num_datos = 0;
    this->_dia = 0;
    this->_fecha = fecha;
    this->_hora = hora;
    this->_minuto = minuto;

    db_local = new DB_local();
    db_remota = new DB_remota();

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

    timer1->setInterval(208);//5
    timer2->setInterval(3600000);//110505

    db_local->borrar_DB();
    db_local->abrir_DB();
    db_local->crear_DB();

    db_remota->create_table();

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

bool Estacion_meteo::abrirGUI(Dato d,int dia)
{
    this->interface.escribir_GUI(dia, d.getTemperatura(),d.getHumedad(),d.getVeloviento(),d.getDirviento(),d.getLatitud(),d.getLongitud(),d.getAltura());
    interface.show();

    return true;
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
        db_local->guardar_dato(promedio_minuto,this->_hora,this->_minuto);
        muestra.setIndice(0);
        this->_minuto++;
        if (this->_minuto == 60) {
            this->_minuto = 0;
            this->_hora++;
            if (this->_hora == 24){
                this->_hora   = 0;
            }
        }
        std::cout<<"Se guardo un dato: "<<this->_num_datos<<"  "<<this->_hora<<":"<<this->_minuto<<std::endl;
        // /*
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<"Temperatura:      "<<promedio_minuto.getTemperatura()<<std::endl;
        std::cout<<"Humedad:          "<<(int)promedio_minuto.getHumedad()<<std::endl;
        std::cout<<"Velocidad Viento: "<<promedio_minuto.getVeloviento()<<std::endl;
        std::cout<<"Direccion Viento: "<<promedio_minuto.getDirviento()<<std::endl;
        std::cout<<"Latitud:          "<<promedio_minuto.getLatitud()<<std::endl;
        std::cout<<"Longitud:         "<<promedio_minuto.getLongitud()<<std::endl;
        std::cout<<"Altura:           "<<promedio_minuto.getAltura()<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<" "<<std::endl;
        //*/

    }
    timer1->start();
}

void Estacion_meteo::alarma_24_horas()
{
    int hora = this->_hora;
    timer1->stop();
    Dato promedio_hora;
    this->_dia++;
     for (int j = 1 ; j <= INTERVAL_DIA ; j++){

         promedio_hora = db_local->getdato_promedio_hora(hora);
         db_remota->guardar_dato(promedio_hora,hora);
         if (hora == 23){
             hora   = 0;
         }
         hora++;
         std::cout<<""<<std::endl;
         std::cout<<"Promedio de la hora: "<<j<<std::endl;
         // /*
         std::cout<<"---------------------------------------"<<std::endl;
         std::cout<<"Temperatura:      "<<promedio_hora.getTemperatura()<<std::endl;
         std::cout<<"Humedad:          "<<(int)promedio_hora.getHumedad()<<std::endl;
         std::cout<<"Velocidad Viento: "<<promedio_hora.getVeloviento()<<std::endl;
         std::cout<<"Direccion Viento: "<<promedio_hora.getDirviento()<<std::endl;
         std::cout<<"Latitud:          "<<promedio_hora.getLatitud()<<std::endl;
         std::cout<<"Longitud:         "<<promedio_hora.getLongitud()<<std::endl;
         std::cout<<"Altura:           "<<promedio_hora.getAltura()<<std::endl;
         std::cout<<"---------------------------------------"<<std::endl;
         std::cout<<" "<<std::endl;
         // *

     }

     abrirGUI(promedio_hora,this->_dia);
     db_local->borrar_DB();
     this->_num_datos = 0;
     timer1->start();
     timer2->start();

}



