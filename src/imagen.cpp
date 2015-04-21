#include "imagen.h"
void Imagen::Borrar(){
  for (int i=0;i<nf;i++)
    delete[]data[i];
  delete []data;
}
/*********************************/
void Imagen::Copiar(const Imagen &I){
    
   nf = I.nf;
  nc = I.nc;
  data = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    data[i]=new Pixel [nc];
    for (int j=0;j<nc;j++){
	data[i][j]=I.data[i][j];
    }
  }  
	
}  
/*********************************/
Imagen::Imagen(){
  data=0;
  nf=nc=0;
}

/*********************************/
Imagen::Imagen(int f,int c){
  nf = f;
  nc = c;
  data = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    data[i]=new Pixel[nc];
    for (int j=0;j<nc;j++){
	data[i][j]=255;
	
    }
  }  


}
/*********************************/
Imagen & Imagen::operator=(const Imagen & I){
   if (this!=&I){
	Borrar();
	Copiar(I);
   }
   return * this;
}   
/*********************************/
Imagen::~Imagen(){
  Borrar();
}

/*********************************/
Pixel & Imagen::operator()(int i,int j){
  assert(i>=0 && i<nf && j>=0 && j<nc*3);
  return data[i][j];
}
/*********************************/
const Pixel & Imagen::operator()(int i,int j)const{
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return data[i][j];
}

/*********************************/
void Imagen::EscribirImagen(const char * nombre){
      unsigned char * aux = new unsigned char [nf*nc];
    
      
      int total = nf*nc;
      for (int i=0;i<total;i++){
	    int posi = i /(nc);
	   int posj = (i%(nc));
	
	    aux[i]=data[posi][posj];
	    
	    
	     
	 }    
	
      if (!EscribirImagenPGM (nombre, aux,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
      }	  
      delete[]aux;
        
}  
/*********************************/
void Imagen::LeerImagen(const char * nombre){
      int f,c;
      unsigned char * aux ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f*c];
      LeerImagenPGM (nombre, f,c,aux);
      
      
      Imagen I(f,c);
      int total = f*c;
      for (int i=0;i<total;i++){
	   int posi = i /(c);
	   int posj = (i%(c));
	   I.data[posi][posj]=aux[i];
      }    
	  
      *this = I;   
      
      delete []aux;
      
}	
