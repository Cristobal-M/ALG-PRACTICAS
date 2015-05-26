#include "utilidades.h"
/****************************************************/
unsigned long int Longitud(ifstream &f){
   f.seekg(0,ios::end);
   unsigned long int t= f.tellg();
   f.seekg(0,ios::beg);
   
   return t;
} 

/****************************************************/
char * CargaFichero (const char *nombre){
  ifstream f (nombre,ios::binary);
  
  if (!f) {
   cout<<"No puedo abrir el fichero "<<endl;
   return 0;
  }
  unsigned long int tam = Longitud(f);
  char * datos = new char[tam+1];
  f.read(reinterpret_cast< char*>(datos),tam);
  datos[tam]='\0';
  return datos;
}  

/****************************************************/
void SaveFichero (const char *datos,const char *nombre){
  ofstream f (nombre,ios::binary);
  
  if (!f) {
   cout<<"No puedo crear el fichero "<<endl;
   return;
  }
  unsigned long int tam = strlen(datos);
  f.write(reinterpret_cast<const char*>(datos),tam);
  
  
}  

/****************************************************/
 unsigned char GetBit(unsigned char dato, int n){
  unsigned char mask = 1<<n;
  if (dato & mask) return 1;
  else return 0;
}

/****************************************************/
void PonerBit(unsigned char &dato,int pos,unsigned char  b){
  
  unsigned char bit = GetBit(dato,pos); 
  if ((b ^ bit)==1){ //son diferentes
        
	 unsigned char mask = 1<<pos;
	 if (bit)
	   dato = dato & ~mask;
	 else
	    dato = dato |mask;
	    
  }
}  
/****************************************************/
void Ocultar(Imagen &I,char** mensajes,unsigned int numero){
 string escrito_real;
 unsigned long int posi=0;
 //Escribimos el numero de mensajes en la imagen
 //Para ello usamos un 8bits
 
 int cols = I.num_cols();
 unsigned long int dim = I.num_filas()*I.num_cols();
 
 for (int j=7;j>=0 && posi<dim;j--){
	unsigned char bit=GetBit((unsigned char)numero,j);
	
	int f = (posi/cols);
	int c = (posi%cols);
        PonerBit(I(f,c),0,bit);
	posi++;
 }
 
 
 for (unsigned int nm=0;nm<numero && posi<dim;nm++){
  int len=strlen(mensajes[nm])+1;
 
  for (int i=0;i<len && posi<dim ;i++){
      for (int j=7;j>=0 && posi<dim;j--){
	int f = (posi/cols);
	int c = (posi%cols);
	unsigned char bit=GetBit(mensajes[nm][i],j);
	
        PonerBit(I(f,c),0,bit);
	posi++;
      }
      escrito_real.push_back(mensajes[nm][i]);
  }    
 }  
 //cout<<"Posi "<<posi<<"escrito_real :"<<escrito_real<<endl;
      
}  
/****************************************************/
char ** Revelar(const Imagen &I,unsigned int &numero ){
 unsigned char byte_read=0;
 
 bool salir=false;
 unsigned long int  posi=0;
 
 int cols = I.num_cols();
 unsigned long int dim = I.num_filas()*I.num_cols();
 numero =0;
 unsigned char k=0;
 posi=0;
 for ( int i=7;i>=0&& posi<dim;i--){
	  int f = (posi/cols);
	  int c = (posi%cols);
	  unsigned char bit = GetBit(I(f,c),0);
	  
	  PonerBit(k,i,bit);
	  posi++;
 }
 numero=k;
 
 char ** mensajes = new char *[numero];
 string m;
 for (unsigned int nm=0;nm<numero && posi<dim;++nm){
   m=""; salir=false;
   while (posi<dim && !salir){
      byte_read=0;
      for (int i=7;i>=0&& posi<dim;i--){
	  int f = (posi/cols);
	  int c = (posi%cols);
	  unsigned char bit = GetBit(I(f,c),0);
	  PonerBit(byte_read,i,bit);
	  posi++;
      } 	  
	
	
      m.push_back(byte_read);
      if (byte_read==0) salir=true;
   }
   mensajes[nm]=new char[m.size()+1];
   strcpy(mensajes[nm],m.c_str());
  
 }
 
 return mensajes;
 
 
}  
	