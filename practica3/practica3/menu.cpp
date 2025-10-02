#include "funciones.h"

void menu(){
    int opcion = 0;
    while (opcion != 3){
        cout<< endl<< "Ingrese una opcion:"
                "\n1. Ejercicio 1."
                "\n2. Ejercicio 2."
                "\n3. Salir"
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            system("cls");
            cout<< endl<< "Hasta pronto";
            break;
        default:
            system("cls");
            cout<< "Opcion invalida.";
        }
    }

    return;
}
