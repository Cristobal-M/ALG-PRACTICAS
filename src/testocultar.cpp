#include "imagen.h"
#include "utilidades.h"

int main(int argc, char *argv[]){

  if (argc<3 ){
  cout<<"Los parametros son:"<<endl;
  cout<<"1.- La imagen donde ocultar "<<endl;
  cout<<"2.- Al menos un fichero a ocultar"<<endl;
  return 0;
 }
 
 int numero = argc-2;
 Imagen I;
 I.LeerImagen(argv[1]);
 
 char **mensajes =new char *[numero];
 for (int i=0;i<numero;i++)
     mensajes[i]=CargaFichero(argv[i+2]);
 
 Ocultar(I,mensajes,numero);
 I.EscribirImagen("ImageMensajes.pgm");
 //Liberamos los mensajes
 for (int i=0;i<numero;i++)
      delete []mensajes[i];
 delete []mensajes;
 
} 

 



   