
#include <iostream>
#include "variaciones.h"
#include "utilidades.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void sintaxis(){
  cerr<<"letras_backtracking spanish letras.txt 8"<<endl;
  cerr<<"El nombre del fichero con el diccionario \
        \nEl nombre del fichero con las letras \
        \nEl numero de letras que se deben generar de forma aleatoria"<<endl;
}

int main(int argc,char **argv){
  if(argc<4){
    sintaxis();
    exit(-1);
  }
  srand(time(NULL));
  int nLetras=atoi(argv[3]);
  vector<char> letrasElegidas;
  vector<char> letras;
  map<char,int> puntuaciones;
  set<string> diccionario;
  //Lellemos las letras y puntuaciones de cada una
  leeLetras(argv[2], letras, puntuaciones);
  leePalabras(argv[1], diccionario);
  //Elegimos de forma aleaotia las letras
  cout<<"Las letras son: ";
  for(int i = 0; i < nLetras; i++){
      letrasElegidas.push_back(letras[rand() % letras.size()]);
      cout<<letrasElegidas[i];
  }
  cout<<endl<<"Dime tu solucion: ";
  string solucionUsuario;
  cin>>solucionUsuario;

/*
  cout<<solucionUsuario.compare(0,2,"tu");
  exit(1);
*/
  std::set<string>::iterator dicEnd=diccionario.end();
  std::set<string>::iterator it=diccionario.find(solucionUsuario);
  if(it!=dicEnd){
    cout<<"Tu solucion tiene una longitud de: "<<solucionUsuario.length()<<endl;
    cout<<"Puntuacion: " << puntuacionPalabra(solucionUsuario,puntuaciones)<<endl;
  }
  else{
    cout<<"Tu solucion no esta en el diccionario "<<endl;
    exit(1);
  }

  int cnt2=1;
  bool continua=true;
  //Variable de la mejor palabra
  string mejorPalabra=solucionUsuario;
  int puntMejorPalabra=puntuacionPalabra(mejorPalabra,puntuaciones);
  Variaciones Deep(nLetras); //Recorre todas las posibilidades en profundidad
  //iniciamos el bucle
  vector<Nodo>LNV;
  int CG=puntuacionPalabra(mejorPalabra,puntuaciones);
  vector<vector<unsigned int> >hijos=Deep.GeneraHijos();
  do{
    for(int i=0;i<hijos.size();i++){
      Nodo nodo(hijos[i], letrasElegidas, puntuaciones, Deep.Nivel());
      if(nodo.getCS()>CG)
        LNV.push_back(nodo);
    }
    hijos.resize(0);
    //Aqui se ordenaria
    Nodo nodo=LNV.back();
    while(LNV.size()>0 && nodo.getCS()<CG){
      LNV.pop_back();
      nodo=LNV.back();
    }
    LNV.pop_back();
    if(nodo.getNivel()==nLetras){
      mejorPalabra=nodo.getPalabra();
      CG=nodo.getCI();
      continua=LNV.size()!=0;
    }
    else{
      Deep=Variaciones(nodo.get(), nodo.getNivel());
      continua=Deep.GeneraSiguienteProfundidad();
      hijos=Deep.GeneraHijos();
    }
  }while(continua);
  cout<<( (solucionUsuario.compare(mejorPalabra)==0 )?"No he encontrado una mejor solucion a: ":"He obtenido la solucion: " )
  <<mejorPalabra<<endl;
  cout<<"Puntuacion: " << puntMejorPalabra<<endl;

  exit(1);

}
