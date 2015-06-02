#include <iostream>
#include <vector>
#include <map>
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
    char letra=l[0];
    int cant=atoi(buffer);
    //Insertamos las letras tantas veces como indica su cantidad
    for(int i=0;<cant;i++){
      salida.push_back(letra);
    }
    puntuaciones[letra]=atoi(buffer);
    fi>>buffer;

	}
}

void leePalabras(char *fichero, set<string> &salida){
  salida.resize(0);
	ifstream fi (fichero, ifstream::in);

	//Sacamos los tres primeros
	while(!fi.eof()){
    string palabra;
		fi>>palabra;
		salida.insert(palabra);
	}
}
