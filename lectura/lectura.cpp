#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

void lectura();
int main(){
    lectura();
    return 0;
}

void lectura(){
     ifstream archivo;
     string texto;
     archivo.open("entrada.txt",ios::in);
     int  i = 0;
 //    string vector[] = {"uno", "dos", "tres","cuatro", "cinco"};
     string vector[10];

     while (!archivo.eof()){
     getline(archivo,texto);
     cout << texto << endl;
     vector[i]=texto;
     i++;

     }
     int v;
     for (v=0; v<(i-1); v++){
//         cout << "el valor #" << vector[v] << endl;
         cout << "el valor # "<< v << " es:  " << vector[v] << endl;
}

}



