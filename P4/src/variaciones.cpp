
#include "variaciones.h"

void Imprimeaux(vector<unsigned int> & v,int n){
  for ( int i=0;i<n;i++)
    cout<<v[i]<< " ";
  cout<<endl;
} 


void Variaciones::GenerarSiguiente(int nivel){
 
  datos[nivel]=datos[nivel]+1;
   
}

bool Variaciones::PosibleVariacion(int nivel){
  //miramos si hay valores repetidos
  for (int i=0;i<nivel;i++)
    if (datos[nivel]==datos[i])
      return false;
    
  // si no hay valores repetidos comprobamos que nivel sigue siendo valido  
  return  nivel<(int)n-1;
}

bool Variaciones::EsVariacion( int nivel){
  for ( int i=0;i<nivel;i++)
    if (datos[nivel]==datos[i])
      return false;
  return nivel==(int)n-1 ;
}


bool Variaciones::MasHermanos(  int nivel){
   return nivel>=0 && datos[nivel]<m;  
}  


Variaciones::Variaciones(unsigned int mm){
  m=mm; n=1;
  //reservamos espacio para m aunque realmente nos haga falta n, por si en el futuro 
  // se amplia a una variacion de mayor tamaño.
  datos=vector<unsigned int>(m,0);
  GeneraSiguienteAnchura(); 
}  



unsigned int Variaciones::NumeroVariacionesPosibles()const{
  
  unsigned int suma=0;
  
  for (unsigned int k=1; k<=m;k++){
    int total =1;
    for (unsigned int i=k;i<=m;i++)
       total*=i;
    suma+=total;
  
  }  
	
  
  return suma;
}  



bool Variaciones::GeneraSiguienteAnchura(){
  
  int nivel=(int)n-1;
  
   while (nivel>=0  && !MasHermanos(nivel)  ){
 
	      datos[nivel]=0; 
              nivel=nivel-1;
   }
   if (nivel<0){
    if (n<m){
      n=n+1;
      nivel=0;
    }
    else
    return false;
   }
  
  do{
       GenerarSiguiente(nivel); 
       
       if (EsVariacion(nivel)){
	  //Imprimeaux(datos,n);
	  return true;
       }	
       if ( PosibleVariacion(nivel)) 
           nivel=nivel+1;
       else{
          while (nivel>=0  && !MasHermanos(nivel)  ){
	      datos[nivel]=0; 
              nivel=nivel-1;
         }
         if (nivel<0){
	    if (n<m){
	      n=n+1;
	      nivel=0;
	    }
	 }   
	      
         
       } 
      
       
   }while (nivel>=0 );   
   return false;
}   




bool Variaciones::GeneraSiguienteProfundidad(){
  
 
  int nivel;
  if (n<m){ //avanzamos al siguiente nivel en profundidad
    n=n+1;
    nivel = n-1;
  }  
  else{ // si no existe siguiente nivel en profundidad
    nivel = m-1; // miramos si existe algun hermano en ese nivel
    while (nivel>=0  && !MasHermanos(nivel)  ){
	      datos[nivel]=0; 
              nivel=nivel-1;
	      n=n-1;
         }  
     if (nivel<0) return false; // no existe mas posibilidades
  }  
      
  do{
       GenerarSiguiente(nivel); //ponemos el valor en el nivel
       
       if (EsVariacion(nivel)){ // es una posibilidad valida
	  //Imprimeaux(datos,n);//si
	  return true;
       }	
       if ( PosibleVariacion(nivel)){ //no es una posibilidad valida
	 
           nivel=nivel+1; // avanzamos en profundidad
	   n=n+1;
       }
       else{
          while (nivel>=0  && !MasHermanos(nivel)  ){ //no existen mas hermanos en ese nivel
	      datos[nivel]=0; //backtraking
              nivel=nivel-1;
	      n=n-1;
         }
         
       } 
       
   }while (nivel>=0 );   
   return false;
}

bool Variaciones::Espadre(Variaciones &v){
  if (n>=v.n) return false;
    
  for (unsigned int i=0;i<n;i++)
   if  (datos[i]!=v.datos[i]) return false;
  return true;
}  
  
  
vector<vector<unsigned int> > Variaciones::GeneraHijos(){
   vector< vector<unsigned int> > out;
    
      Variaciones vaux = *this;
      if (vaux.GeneraSiguienteProfundidad()){
        unsigned int level = vaux.Nivel();
	bool seguir=true;
	
	while(seguir && level==n+1 && Espadre(vaux)) {
	 out.push_back(vaux.GetVariacion());
	 
	 seguir=vaux.GeneraSiguienteAnchura();
	 if (seguir){
           for (unsigned int i=0;i<n;i++)
	    
	   level = vaux.Nivel();
	}
      }
      }
      return out;
}      
	
bool Variaciones::Backtracking(){
      int nivel; 
      if (n==1) return false;
      else{
	 
	 nivel = n-1;
	 while (nivel>=0  && !MasHermanos(nivel)  ){
	      datos[nivel]=0; 
              nivel=nivel-1;
	      n=n-1;
         }  
         if (nivel<0) return false;
	 
      }	 
       do{
       GenerarSiguiente(nivel); //ponemos el valor en el nivel
       
       if (EsVariacion(nivel)){ // es una posibilidad valida
	  //Imprimeaux(datos,n);//si
	  return true;
       }	
       if ( PosibleVariacion(nivel)){ //no es una posibilidad valida
	 
           nivel=nivel+1; // avanzamos en profundidad
	   n=n+1;
       }
       else{
          while (nivel>=0  && !MasHermanos(nivel)  ){ //no existen mas hermanos en ese nivel
	      datos[nivel]=0; //backtraking
              nivel=nivel-1;
	      n=n-1;
         }
         
       } 
       
        }while (nivel>=0 );   
     return false;
      
    }        
