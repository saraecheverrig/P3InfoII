#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void menu();

void ejercicio1();
void ejercicio2();


string decimalBinario(int caracter);
string leer();
void modificar(string contenido);
string contenidoEnBinario(string contenido);
string bloqueMet1(int cantUnos, int cantCeros, string bloque);
string bloqueMet2(string bloque);
string bloqueDecodifMet1(string bin, int numBloques, int bloque);
string bloqueDecodifMet2(string bloqueCodif);

int binarioADecimal(string);
int potencia(int, int);



string cadenaCodifMet1(string cadena);

#endif // FUNCIONES_H
