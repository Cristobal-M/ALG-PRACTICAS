#include "imagen.h"
#include "utilidades.h"

int main(int argc, char *argv[]){

  if (argc!=3 ){
  cout<<"Los parametros son:"<<endl;
  cout<<"1.- La imagen donde revelar "<<endl;
  cout<<"2.- El directorio donde crear los ficheros con los mensajes revelados"<<endl;
  return 0;
 }
 
 
 Imagen I;
 I.LeerImagen(argv[1]);
 unsigned int numero;
 
 char **mensajes =Revelar(I,numero);
 for (unsigned int i=0;i<numero;i++){
    char tmp[80];
    sprintf(tmp,"%s/fich%i.txt",argv[2],i);
    
    SaveFichero(mensajes[i],tmp);
    //cout<<mensajes[i]<<endl; 
 }
 
 
 //Liberamos los mensajes
 for (unsigned int i=0;i<numero;i++)
      delete []mensajes[i];
 delete []mensajes;
 
} 

 



   