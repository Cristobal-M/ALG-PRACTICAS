#ifndef __UTILIDADES__H
#define __UTILIDADES__H
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void leeLetras(char *fichero, vector<char> &salida, map<char,int> &puntuaciones);


void leePalabras(char *fichero, set<string> &salida);

#endif
