#include "imagen.h"
#include "utilidades.h"
#include "texto.h"

List <texto> ficheros;

bool Seleccion_peso ( List <texto> &f, List <texto> &f1 ){
	int l,l1;
	l=f.Get_P();
	l1=f1.Get_P();
	return (l<l1);
}

void Seleccion_beneficio ( List <texto> &f ){

}

void Seleccion_relacion ( List <texto> &f ){

}



int main(int argc, char *argv[]){

	if (argc<6 ){
		cout<<"Los parametros son:"<<endl;
  	cout<<"1.- Ejecutable "<<endl;
  	cout<<"2.- La imagen donde ocultarr"<<endl;
  	cout<<"3.- El fichero .txt"<<endl;
  	cout<<"4.- Carpeta donde se encuentran los ficheros"<<endl;
  	cout<<"5.- Un numero entre el 1 al 3"<<endl;
  	cout<<"6.- C para completos y P para parciales"<<endl;
  	return 0;
	}
	
	ficheros.sort(Seleccion_peso);
	

}
