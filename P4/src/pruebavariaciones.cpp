#include <iostream>
#include "variaciones.h"
#include <string> 


void ImprimeCadena(const string &c,const Variaciones &P){
  
  Variaciones::const_iterator s= P.begin();
  
  
  for (;s!=P.end();++s){
  
     cout<<c[(*s)-1];
  }   
  
  cout<<endl;
}

int main(){
  
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
    
    
    
    
    
}  
  
  
   
  
