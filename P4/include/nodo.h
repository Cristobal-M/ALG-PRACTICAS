#ifndef __NODO__H
#define __NODO__H
#include <vector>
#include <iostream>
#include "variaciones.h"
using namespace std;
class Nodo{
private:
  vector<unsigned int> variacion;
  int CS, CI, nivel;
  vector<char> *letrasElegidas;
  map<char,int> *puntuaciones;

  void calcularCotas(){
    CS=0;
    CI=0;
    vector<char> letrasRestantes(*letrasElegidas);

    for (unsigned i=0;i<variacion.size();i++){
      int ind=variacion[i]-1;
      if(ind>=0){
        char letra=letrasElegidas->at(ind);
        CI+=puntuaciones->at(letra);
        letrasRestantes.erase(letrasRestantes.begin()+ind);
      }
    }
    letrasRestantes.sort(letrasRestantes.begin(), letrasRestantes.end());
    CS=CI;
    //n-nivel del Nodo
    for (unsigned i=0;i<letrasElegidas.size()-nivel;i++){
      char letra=letrasRestantes.back();
      letrasRestantes.pop_back();
      CS+=puntuaciones->at(letra);
    }
  }
public:
  Nodo(){};
  Nodo(vector<unsigned int> v, vector<char>* lE, map<char,int> *p, int n){
    variacion=v;
    letrasElegidas=lE;
    puntuaciones=p;
    nivel=n;
  }
  vector<int> get(){
    return variacion;
  }
  int getNivel(){
    return nivel;
  }
  int getCS(){ return CS;}
  int getCI(){ return CI;}
  int getBen(){ return CI;}
  string getPalabra(){
    string salida="";
    for (unsigned i=0;i<variacion.size();i++){
      int ind=variacion[i]-1;
      if(ind>=0){
        char letra=letrasElegidas->at(ind);
        salida.push_back(letra);
      }
    }
    return salida;
  }
}
#endif
