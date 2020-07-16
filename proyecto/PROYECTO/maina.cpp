#include <iostream>

float vector_s[12];
float vector_m[60];
float vector_h[24];





for (int h = 0; h < 24; h++){

    for (int m = 0; m < 60; m++){

        for (int s = 0; s < 12; s++){         // promedio de los segundos.
            int p_s = 0
            p_s += vector_s[s];
        }

        p_s = p_s / 12;
        contador_m++;
        vector_m[m] = p_s;                    // asignar el promedio a el vector de minutos.

        if (m = 59){
            for (int m = 0; s < 60; m++){    // promedio de los minutos.
                int p_m = 0
                p_m += vector_m[m];
            }

            p_m = p_m / 60;

            vector_h[h] = p_m;               // asignar el promedio a el vector de horas.

        }

    }

}



