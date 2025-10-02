#include <iostream>
#include "funciones.h"

using namespace std;


int main(){

    menu();

    cout << endl << cadenaCodifMet1("1354");      //Comprobar la codificación con la cadena que se ingrese como parámetro
    modificar(cadenaCodifMet1("1100101101101111011011110110111101101111"));    //Se va a solicitar el nombre del archivo donde se quiere ver reflejada la codificación pruebaCodificado

    return 0;
}
