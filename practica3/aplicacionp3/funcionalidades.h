#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H
#include "funciones.h"


void validarAdmin(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos);

void validarUser(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos);


void menuAdmin(vector<string> &cedulas, vector<string> &claves, vector<int> &saldos);

int menuUser(int saldos);



#endif // FUNCIONALIDADES_H
