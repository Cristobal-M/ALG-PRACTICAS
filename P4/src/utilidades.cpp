#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "utilidades.h"
using namespace std;

// void leeLetras(char *fichero, vector<Letra> &salida){
//   salida.resize(0);
// 	ifstream fi (rutaFichero);
//
// 	char c[10];
//   char l[1];
//   char p[10];
// 	//Sacamos los tres primeros
// 	fi>>p;
// 	fi>>p;
// 	fi>>p;
// 	while(!fi.eof()){
// 		fi>>l;
// 		fi>>c;
// 		fi>>p;
// 		Letra l(l[0], atoi(c), atof(p));
// 		salida.push_back(l);
// 	}
// }
//uncion que lee el archivo de letras
void leeLetras(char *fichero, vector<char> &salida, map<char,int> &puntuaciones){
  salida.resize(0);
  puntuaciones.clear();
	ifstream fi(fichero, ifstream::in);

	char buffer[100];
  char l[1];
	//Sacamos los tres primeros
	fi>>buffer;
	fi>>buffer;
	fi>>buffer;
	while(!fi.eof()){
		fi>>l;
    fi>>buffer;
    char letra=tolower(l[0]);
    int cant=atoi(buffer);
    //Insertamos las letras tantas veces como indica su cantidad
    for(int i=0;i<cant;i++){
      salida.push_back(letra);
    }
    fi>>buffer;
    puntuaciones[letra]=atoi(buffer);


	}
}

void leePalabras(char *fichero, set<string> &salida){
	ifstream fi (fichero, ifstream::in);

	//Sacamos los tres primeros
	while(!fi.eof()){
    string palabra;
		fi>>palabra;
		salida.insert(palabra);
	}
}

int puntuacionPalabra (const string &P, const map<char,int> &pun){
	int Puntuacion=0;
	for (const char & c : P){
		Puntuacion += pun.at(c);
	}
	return Puntuacion;
}

bool validaPalabra(string palabra, set<string> diccionario){
  
}

void ImprimePalabra(const int* E,const vector<char> &letras,const Variaciones &P){

  Variaciones::const_iterator s= P.begin();


  for (;s!=P.end();++s){

     cout<<letras[E[(*s)-1]];
  }

  cout<<endl;
}
