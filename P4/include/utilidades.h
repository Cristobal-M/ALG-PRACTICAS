#ifndef __UTILIDADES__H
#define __UTILIDADES__H
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "variaciones.h"
using namespace std;

void leeLetras(char *fichero, vector<char> &salida, map<char,int> &puntuaciones);


void leePalabras(char *fichero, set<string> &salida);

void ImprimePalabra(const int* E,const vector<char> &letras,const Variaciones &P);

string componerPalabra(const int* E,const vector<char> &letras,const Variaciones &P);

int validarPalabra(const string palabra, set<string> diccionario);

int puntuacionPalabra (const string &P, const map<char,int> &pun);

int puntuacionSolucion(const int* E,const vector<char> &letras,const Variaciones &P, const map<char,int> &pun)

#endif
