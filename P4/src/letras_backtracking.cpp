
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

void ImprimeCadena(const string &c,const Variaciones &P){

  Variaciones::const_iterator s= P.begin();


  for (;s!=P.end();++s){

     cout<<c[(*s)-1];
  }

  cout<<endl;
}

void ImprimePalabra(const int* E,const vector<char> &letras,const Variaciones &P){

  Variaciones::const_iterator s= P.begin();


  for (;s!=P.end();++s){

     cout<<letras[E[(*s)-1]];
  }

  cout<<endl;
}

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
  int *letrasElegidas=new int[nLetras];
  vector<char> letras;
  map<char,int> puntuaciones;
  set<string> diccionario;
  //Lellemos las letras y puntuaciones de cada una
  leeLetras(argv[2], letras, puntuaciones);
  leePalabras(argv[1], diccionario);
  //Elegimos de forma aleaotia las letras
  cout<<"Las letras son: ";
  for(int i = 0; i < nLetras; i++){
      letrasElegidas[i] = rand() % letras.size();
      cout<<letras[letrasElegidas[i]];
  }
  cout<<endl<<"Dime tu solucion: ";
  string solucionUsuario;
  cin>>solucionUsuario;
  std::set<string>::iterator dicEnd=diccionario.end();
  std::set<string>::iterator it=diccionario.find(solucionUsuario);
  if(it!=dicEnd){
    cout<<"Tu solucion tiene una longitud de: "<<solucionUsuario.length()<<endl;
  }
  else{
    cout<<"Tu solucion no esta en el diccionario "<<endl;
    exit(1);
  }
  Variaciones Deep(nLetras); //Recorre todas las posibilidades en profundidad
  int cnt2=1;
  do{
    cout<<cnt2<<"-->";
    ImprimePalabra(letrasElegidas, letras,Deep);
    cnt2++;
  }while(Deep.GeneraSiguienteProfundidad());
exit(1);

/*

//////////////////////////////////////////////////////////////////////////////
  string cad;
  do{
  cout<<"Dime una palabra:";
  cin>>cad;
  }while (cad.size()<=0);

  cout<<"Recorrido en Profundidad:"<<endl;
    Variaciones Deep(cad.size()); //Recorre todas las posibilidades en profundidad
    int cnt2=1;
    do{
      cout<<cnt2<<"-->";
      ImprimeCadena(cad,Deep);
      cnt2++;
    }while(Deep.GeneraSiguienteProfundidad());

  cout<<"**************************************"<<endl;
  cout<<"Recorrido en Anchura:"<<endl;
    Variaciones Weight(cad.size()); //Recorre todas las posibilidades en anchura
    cnt2=1;
    do{
      cout<<cnt2<<"-->";
      ImprimeCadena(cad,Weight);
      cnt2++;
    }while(Weight.GeneraSiguienteAnchura());


    //Probando la modificacion del saltar de un nivel a otro
    if (cad.size()>=3){
     Variaciones Salta(cad.size());
    //Avanzamos en tres niveles

     Salta.GeneraSiguienteProfundidad();
     Salta.GeneraSiguienteProfundidad();

    cout<<"Valor actual de la cadena por la que vamos:"<<endl;

     ImprimeCadena(cad,Salta);

     cout<<endl<<"Nivel actual "<<Salta.Nivel()<<endl;

    //Retrocedemos dos niveles y generamos el siguiente en Anchura
     cout<<"Saltamos al nivel 2: ";
     Salta.PutNivel(2);
     ImprimeCadena(cad,Salta);
     cout<<endl;


     if (Salta.GeneraSiguienteAnchura()){
        cout<<"Siguiente en anchura: ";
        ImprimeCadena(cad,Salta);
	cout<<endl;
     }

      //Y el siguiente en profundidad
     if (Salta.GeneraSiguienteProfundidad()){
       cout<<"Siguiente en profundidad: ";
       ImprimeCadena(cad,Salta);
       cout<<endl;
     }
    //Dar marcha atrás: backtracking para podar toda la rama y seguir por la siguiente rama
     if (Salta.Backtracking()){
	cout<<"La cadena al hacer backtracking es :"; ImprimeCadena(cad,Salta);cout<<endl;
     }
     else{
       cout<< "No se puede hacer backtracking"<<endl;
     }
    }
    //Probamos iniciar una variacion con una variacion concreta y obtener los hijos de esta
    vector<unsigned int> vput(5,0);

    vput[0]=1;vput[1]=3;



    Variaciones Otra(vput,2);

    vector<vector<unsigned int> >hijos=Otra.GeneraHijos();
    cout<<"Los hijos de 1,3:"<<endl;

    for (unsigned int i=0;i<hijos.size();i++){
      for (unsigned int j=0;j<=Otra.Nivel();j++)
	  cout<<hijos[i][j]<< " ";
      cout<<endl;
    }

*/



}
