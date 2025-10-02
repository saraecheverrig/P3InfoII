#include "funcionalidades.h"

void menuInicial(){
    /*
    Se hace uso de indexación para la correspondencia de datos entre cedulas, claves y el saldo
    */
    int opcion = 0;
    while (opcion !=3) {
        vector<string> cedulas, claves;
        vector<int> saldos;
        int cantUsuarios = 0 ;
        string *usuarios= new string [5], saldoCodif;       //Número máximo de usuarios (puede ser modificado)
        cantUsuarios = leerUsuarios(usuarios);
        for(int i = 0; i < cantUsuarios ; i++){         //anexo de valores de usuarios a los vectores
            int len = usuarios[i].length();
            cedulas.push_back(usuarios[i].substr(0,10));
            claves.push_back(usuarios[i].substr(11,32));
            saldoCodif = (usuarios[i].substr(44, (len - 44)));
            saldoCodif = bloqueDecodifMet1(saldoCodif);         //Decodificación del saldo y almacenamiento en el vector
            saldos.push_back(stoi(saldoCodif));
        }
        delete[] usuarios;

        cout<< "\nIngrese una opcion"
                "\n1. Administrador."
                "\n2. Usuario."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            validarAdmin(cedulas,claves,saldos);
            modificar(cedulas,claves,saldos);
            break;
        case 2:
            validarUser(cedulas,claves,saldos);
            modificar(cedulas,claves,saldos);
            break;
        case 3:
            system("cls");
            cout << "\nHasta pronto.";
            break;
        default:
            system("cls");
            cout << "\nOpcion erronea.";
            break;
        }
    }
}


void validarAdmin(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos){
    /*
    Paso por referencia de los vectores cedulas, claves y saldos
    leido: contraseña que se encuentra en archivo de texto y se encuentra codificada
*/
    system("cls");
    string leido, ingresado;
    int opcion = 0;
    leido = leer("sudo.txt");
    while (opcion != 2){
        cout <<"\nIngrese una opcion."
                "\n1. Clave."
                "\n2. Salir."
                "\nOpcion: ";
        cin>> opcion;
        switch(opcion){
        case 1:
            cout << "Ingrese la clave: ";
            cin >> ingresado;
            ingresado = cadenaCodifMet1(ingresado);         //Codificación para comprobar que sea válida
            if (ingresado == leido){
                menuAdmin(cedulas, claves, saldos);
                opcion = 2;
            }
            else{
                cout << "Clave erronea\n";
            }
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion invalida";
            break;
        }
    }

}

void validarUser(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos){
    system("cls");
    int opcion = 0;
    string  cedulaIngresada, claveIngresada;
    while (opcion != 2){
        bool validacion = false;
        int indice = 0;
        cout <<"\nIngrese una opcion."
                "\n1. Ingresar usuario y clave."
                "\n2. Salir."
                "\nOpcion: ";
        cin>> opcion;
        switch(opcion){
        case 1:
            while(validacion != true){
                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> cedulaIngresada;              //Si hay tiempo validar que sean caracteres numericos
                if (cedulaIngresada.length() == 10){
                    for (const auto & cedula : cedulas){
                        if (cedula == cedulaIngresada){
                            validacion = true;
                            break;
                        }
                        indice++;
                    }
                    if(validacion != true){
                        cout << "\nNo se ha encontrado un usuario con la cédula ingresada\n";
                    }
                }
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                }
            }
            cout << "\nIngrese la clave (4 digitos numéricos): ";
            cin>> claveIngresada;
            if (claveIngresada.length() == 4){
                claveIngresada = cadenaCodifMet1(claveIngresada);
                if (claveIngresada == claves[indice]){
                    if (saldos[indice] >= 1000){
                        saldos[indice] -= 1000;
                        saldos[indice] = menuUser(saldos[indice]);
                        opcion = 2;
                    }
                    else{
                        cout << "\nNo posee dinero suficiente para acceder\n";
                    }

                }
                else{
                    cout << "\nClave incorrecta\n";
                }
            }
            else{
                cout << "\nClave fuera de rango, recuerde son 4 caracteres numericos\n";
            }

            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion invalida";
            break;
        }
    }

}


void menuAdmin(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos){
    /*
    Paso por referencia de los vectores cedulas, claves y saldos
    */
    system("cls");
    int opcion = 0;
    while(opcion !=3){
        string nueCedula, nueClave;
        int nueSaldo = 0, indice = 0;
        bool validacion = true;

        cout << "\nIngrese una opcion."
                "\n1. Agregar un usuario nuevo."
                "\n2. Consignar valor a cuenta de usuario."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:         //Acciones para ingresar usuario nuevo
            while(validacion != false){
                validacion = false;
                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> nueCedula;
                if (nueCedula.length() == 10){          //Validación de longitud apropiada
                    for (const auto & cedula : cedulas){
                        if (cedula == nueCedula){       //Validación de existencia de la cédula
                            validacion = true;
                            break;
                        }
                    }
                    if(validacion == true){
                        cout << "\nSe ha encontrado un usuario con la cédula ingresada\n";
                    }
                    else{
                        for (const char caracter : nueCedula){      //Validación de que la cedula sean únicamente numericos
                            if(isdigit(caracter));
                            else{
                                cout << "\nIngrese unicamente caracteres numericos";
                                validacion = true;
                                break;
                            }
                        }
                    }
                }
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                    validacion = true;
                }
            }
            cedulas.push_back(nueCedula);
            while(validacion != true){
                cout << "\nIngrese su clave (4 digitos numericos): ";
                cin >> nueClave;
                if (nueClave.length() == 4){            //Validación de longitud
                    for (const char & esNum : nueClave){        //Validación de que los caracteres ingresados sean digitos
                        if (isdigit(esNum));
                        else{
                            validacion = true;
                            break;
                        }
                    }
                    if(validacion == true){
                        cout << "\nClave ingresada erronea, ingrese unicamente caracteres numericos.\n";
                        validacion = false;
                    }
                    else{
                        validacion = true;
                    }
                }
                else{
                    cout << "\nClave fuera de rango (recuerde son 4 digitos numéricos)\n";
                }
            }
            nueClave = cadenaCodifMet1(nueClave);       //Codificación clave ingresada y validada
            claves.push_back(nueClave);
            while(validacion != false){
                string nueSaldoStr;
                cout << "\nIngrese el saldo del usuario: ";
                cin >> nueSaldoStr;
                for (const char dato : nueSaldoStr){
                    if (isdigit(dato));         //Validación de que se ingresen caracteres numericos
                    else{
                        validacion = false;
                        break;
                    }
                }
                if (validacion == false){
                    cout << "\nIngrese unicamente caracteres numericos.\n";
                    validacion = true;
                }
                else{
                    nueSaldo = stoi(nueSaldoStr);
                    if ( nueSaldo >= 0){        //Validación de que se ingrese un salo favorable
                        validacion = false;
                    }
                    else{
                        cout << "\nAsegurese de ingresar un valor de dinero positivo.\n";
                    }
                }
            }
            saldos.push_back(nueSaldo);
            break;
        case 2:         //acciones consignar dinero

            while(validacion != false){
                string cedulaIngresada;

                cout << "\nIngrese la cedula (10 digitos numericos): ";
                cin>> cedulaIngresada;
                if (cedulaIngresada.length() == 10){        //Validación de longitud
                    for (const auto & cedula : cedulas){        //Validación de exitencia de la cedula ingresada
                        if (cedula == cedulaIngresada){
                            validacion = false;
                            break;
                        }
                        indice++;
                    }
                    if(validacion != false){
                        cout << "\nNo se ha encontrado un usuario con la cédula ingresada\n";
                    }
                }
                else{
                    cout << "\nCedula fuera de rango, recuerde son 10 caracteres numericos\n";
                }
            }
            while (validacion != true){
                string saldoAñadir;
                cout << "\nIngrese el saldo que desea añadirle al usuario: ";
                cin>> saldoAñadir;
                for (const char dato : saldoAñadir){
                    if(isdigit(dato));      //Validación de tipo de dato
                    else{
                        validacion = true;
                        break;
                    }
                }
                if (validacion == true){
                    cout << "\nIngrese unicamente valores numericos\n";
                    validacion = false;
                }
                else{
                    nueSaldo = stoi(saldoAñadir);
                    if ( nueSaldo >= 0){        //Validación de saldo favorable
                        validacion = true;
                    }
                    else{
                        cout << "\nAsegurese de ingresar un valor de dinero positivo.\n";
                    }
                }
            }

            saldos[indice] += nueSaldo;
            break;
        case 3:
            system("cls");
            break;
        default:
            system("cls");
            cout << "\nOpcion invalida.\n";
            break;
        }
    }


}


int menuUser(int saldo){
    int opcion = 0, monto = 0;
    bool validacion = false;
    string montoRetirar;
    while (opcion != 3){
        cout <<"\nIngrese una opcion."
                "\n1. Consultar el saldo."
                "\n2. Retirar dinero."
                "\n3. Salir."
                "\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "\nSu saldo actual es: " << saldo <<endl ;
            break;
        case 2:
            validacion = false;
            while (validacion != true){
                cout << "\nIngrese la cantidad de dinero que desea retirar: ";
                cin >> montoRetirar;
                for (const char digito : montoRetirar){
                    if (isalpha(digito)){
                        cout << endl << "Ingrese únicamente dígitos numéricos. \n";
                        validacion = true;
                        break;
                    }
                }
                if (validacion == true){
                    validacion = false;
                }
                else {
                    monto =stoi(montoRetirar);
                    if (monto > saldo){
                        cout << "\nNo posee esa cantidad de dionero en su cuenta.\n";
                    }
                    else validacion = true;
                }
            }

            saldo -= monto;
            break;
        case 3:
            system("cls");
            break;
        default:
            system("cls");
            cout << "\nOpcion invalida.\n";
            break;
        }
    }
    return saldo;
}
