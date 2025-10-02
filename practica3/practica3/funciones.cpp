#include "funciones.h"



string  decimalBinario(int entero){
    /*
Función que retorna en forma de string el equivalente en binario de un entero que se ingrese
en este caso se ingresa un caracter de tipo char
*/
    unsigned int i = 0;
    string binario = "";
    short int arreglo[8] = {};  // 8 debido a que es la cantidad de bits contenida en 1 byte
    while (entero != 1){        //ciclo while para generar la conversión de entero a binario
        if ((entero%2) == 1){
            arreglo[7-i] = 1;
            entero = (entero - 1) /2;
        }
        else{
            arreglo[7-i] = 0;
            entero /= 2;
        }
        i ++;
    }
    arreglo[7-i] = 1;

    for (int j = 0; j<8; j++){
        binario += to_string(arreglo[j]);
    }

    return binario;
}


string leer(){
    string lineas, temp, nombreEntrada;
    ifstream archivo;         //Instancia de la clase iftream (lectura) para representar el archivo
    bool estado = false;
    while (estado == false){
        try{
            cout << "Ingrese el nombre del archivo a leer: ";
            cin >>nombreEntrada;
            archivo.open(nombreEntrada, ios::in);  //Abrir el archivo para lectura
            if (!archivo.is_open()) {
                throw 1;   //Exit the program with an error code         evaluar try / except
            }

            //Leer por linea
            while (! archivo.eof()){            //Mientras que no me encuentre con el final del archivo
                getline(archivo,temp,'\n');   //Obtener una linea
                lineas += temp;
            }
            archivo.close();    //Cerrar el archivo
            throw 2;
        }   catch(int num){
            if (num == 1){
                //system("cls");
                cout<< "Nombre erroneo, intente de nuevo."<< endl;
            }
            else if(num ==2){
                estado = true;
            }
        }
    }
    return lineas;
}

void modificar(string contenido){
    string nombreSalida, formato;
    bool estado = false;
    int len = 0;
    while (estado == false){
        cout << endl<< "Ingrese el nombre del archivo donde se guardará la información: ";
        cin >>nombreSalida;
        len = nombreSalida.length();
        for (int i = 4; i > 0; i --){           //4 a 0 para tomar las últimas 4 posiciones ".txt"
            formato += nombreSalida[len -i];
        }
        if (formato == ".txt"){
            ofstream archivo2(nombreSalida);
            archivo2 << contenido;
            estado = true;
        }
        else{
            cout << endl<< "Formato erroneo, ingrese un .txt";
        }
    }
}


string contenidoEnBinario(string contenido){
    /*
Función que se encarga de retornar como una cadena str el equivalente en binario de cada
elemento perteneciente a la cadena inicial
El str retornado será lineal, es decir, no tendrá caracteres separadores entre si, se comprenderá
que por cada 8 caracteres contiguos, esto representará un byte / caracter de la cadena
*/
    short int len = contenido.length();
    string binario = "";
    for (int i = 0; i < len; i++){
        binario += decimalBinario(contenido[i]);
    }
    return binario;
}



string bloqueMet1(int cantUnos, int cantCeros, string bloque){
    string bloqueCodificado;
    int tamañoBloque = bloque.length();
    if (cantCeros > cantUnos){
        for (int i = 0; i< tamañoBloque; i++){
            if ((i % 2) == 0){
                bloqueCodificado += bloque[i];
            }
            else
                bloqueCodificado += bloque[i] == '1' ? '0' : '1';       //Invertir el valor usando operador ternario
        }
    }
    else if(cantCeros < cantUnos){
        for (int i = 0, j = 1; i < tamañoBloque; i++){
            if (j == 3){                //3 para modificar cada que se pasen 2 posiciones y se ubique en la tercera
                bloqueCodificado += bloque[i] == '1' ? '0' : '1';
                j = 1;
            }
            else{
                bloqueCodificado += bloque[i];
                j++;
            }
        }
    }
    else{
        for (int i = 0; i< tamañoBloque; i++){
            bloqueCodificado += bloque[i] == '1' ? '0' : '1';
        }
    }
    return bloqueCodificado;
}

string bloqueMet2(string bloque){
    string bloqueCodificado;
    int tamañoBloque = bloque.length();
    bloqueCodificado += bloque[tamañoBloque- 1];        //Última posición pasa a ser la primera
    for (int i = 0; i < (tamañoBloque - 1) ; i++){
        bloqueCodificado += bloque[i];
    }
    return bloqueCodificado;
}

string bloqueDecodifMet1(string bin, int numBloques, int bloque){
    int cantCeros = 0, cantUnos = 0;
    string bloqueOrg, decodificado;
    for (int bloqueNum = 0; bloqueNum< numBloques; bloqueNum++){        //bloqueNum: bloque Número...
        string bloqueCodif = "";
        for (int j = (bloque*bloqueNum); j< (bloque*(bloqueNum+1)); j++){       //bloque*bloqueNum: el primer índice a tomar de la cadena
            bloqueCodif += bin[j];
        }
        bloqueOrg = bloqueMet1(cantUnos, cantCeros, bloqueCodif);
        cantCeros = 0, cantUnos = 0;
        decodificado += bloqueOrg;
        for (int indice = 0; indice < bloque; indice++){        //Conteo de 1 y 0 de la cadena
            if (bloqueOrg[indice]== '1')
                cantUnos += 1;
            else
                cantCeros += 1;
        }
    }
    return decodificado;
}

string bloqueDecodifMet2(string bloqueCodif){
    string bloqueOrg;
    int tamañoBloque = bloqueCodif.length();
    for (int indice = 1; indice < tamañoBloque; indice++){
        bloqueOrg += bloqueCodif[indice];
    }
    bloqueOrg += bloqueCodif[0];
    return bloqueOrg;
}


int binarioADecimal(string arreglo){
    int total = 0;
    for (int i = 0; i <8; i++){
        if(arreglo[i]=='1'){
            total += potencia(2,7-i);
        }
    }
    return total;
}

int potencia(int num, int potencia){
    int potenciaTotal = 1;
    for (int j = 0; j < potencia ; j++){
        potenciaTotal *= num;
    }
    return potenciaTotal;
}




string cadenaCodifMet1(string bin){
    int cantCeros = 0, cantUnos = 0, bloque = 4;
    string bloqueOrg, decodificado, decodificadoLetras;
    int numBloques = bin.length()/bloque;
    for (int bloqueNum = 0; bloqueNum< numBloques; bloqueNum++){        //bloqueNum: bloque Número...
        string bloqueCodif = "";
        for (int j = (bloque*bloqueNum); j< (bloque*(bloqueNum+1)); j++){       //bloque*bloqueNum: el primer índice a tomar de la cadena
            bloqueCodif += bin[j];
        }
        bloqueOrg = bloqueMet1(cantUnos, cantCeros, bloqueCodif);
        cantCeros = 0, cantUnos = 0;
        decodificado += bloqueOrg;
        for (int indice = 0; indice < bloque; indice++){        //Conteo de 1 y 0 de la cadena
            if (bloqueOrg[indice]== '1')
                cantUnos += 1;
            else
                cantCeros += 1;
        }
    }
    int cantBytes = decodificado.length() / 8;

    for (int byte = 0; byte < cantBytes; byte++){
        string binario = "";
        for (int indice = (8*byte); indice < 8*(byte+1);indice++ ){
            binario+= decodificado[indice];
        }
        char letra = binarioADecimal(binario);
        decodificadoLetras += letra;
    }
    return decodificadoLetras;
}
