#ifndef __UTILIDADES__H
#define __UTILIDADES__H
#include <fstream>
#include <iostream>
using namespace std;

void leeLetras(char *fichero, vector<Letra> &salida, map<char,int> &puntuaciones);


void leePalabras(char *fichero, set<string> &salida);

#endif
