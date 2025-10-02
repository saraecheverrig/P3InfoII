#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void menuInicial();


string decimalBinario(int caracter);
string leer(string nombreEntrada);
int leerUsuarios(string usuarios[]);

void modificar(vector <string> cedulas,vector <string> claves, vector <int> saldos);
string contenidoEnBinario(string contenido);
string cadenaCodifMet1(string cadena);
string bloqueMet1(int cantUnos, int cantCeros, string bloque);
string bloqueDecodifMet1(string bin);


int binarioADecimal(string);
int potencia(int, int);

#endif // FUNCIONES_H
