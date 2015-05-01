#include "imagen.h"
#include "utilidades.h"
#include "texto.h"
#include <list>
#include <stdlib.h>
#include <climits>

ostream & operator<<(ostream & s, const list <texto> &f){
	//s << fin << endl;
	s <<std::setw(50)<<std::left<< "Ruta" 
			<<std::setw(10)<<std::left<<"Beneficio"
			<<std::setw(10)<<std::left<<"Peso"
			<<endl; 
	list <texto> f2=f;
	while(!f2.empty()){
		s << f2.front() << endl;
		f2.pop_front();
	}
	
	return s;

}
void cargarDatosFicheros(char *rutaFichero,char *dir,list<texto> &lista){
	lista.resize(0);
	ifstream fi (rutaFichero);
	/*
	char *f=new char[100];
	char *b=new char[100];
	char *p=new char[100];
	*/
	string f,b,p;
	string directorio(dir);
	//Sacamos los tres primeros
	fi>>p;
	fi>>p;
	fi>>p;
	while(!fi.eof()){
		fi>>f;
		fi>>b;
		fi>>p;
		f=directorio+f;
		texto *t=new texto(f, atoi(b.c_str()), atof(p.c_str()));
		lista.push_back(*t);
	}
}
//########################################################################
//                        Variables globales
//########################################################################
list <texto> ficheros;
list <texto> solucion;
Imagen imagen;
int espacio;
int m =0;
//########################################################################
//                        Ordenacion por Peso
//########################################################################
bool Seleccion_peso ( texto f1, texto f2 ){
	double p1,p2;
	p1=f1.Get_P();
	p2=f2.Get_P();
	return (p1<p2);
}
//########################################################################
//                      Ordenacion por Beneficio
//########################################################################
bool Seleccion_beneficio ( texto f1, texto f2 ){
	int b1,b2;
	b1=f1.Get_B();
	b2=f2.Get_B();
	return (b1>b2);
}
//########################################################################
//               Ordenacion por relacion Beneficio/Peso
//########################################################################
bool Seleccion_relacion ( texto f1, texto f2 ){
	double r1,r2;
	r1=(f1.Get_B()/f1.Get_P());
	r2=(f2.Get_B()/f2.Get_P());
	return (r1>r2);
}
//########################################################################
//               Funcion factible
//########################################################################
bool Factible (texto &S, list<texto> &X ){
	double ocupado=0;
	for (std::list<texto>::iterator it=X.begin(); it != X.end(); ++it){
		ocupado+=(*it).Get_P()+1;
	}
	ocupado+=S.Get_P()+1;
	return (ocupado<=espacio);
}

void Algoritmo_Voraz (int opcion , string capa){
	solucion.resize(0);
	
	switch (opcion){	
		case 1:
			ficheros.sort(Seleccion_peso);
			break;
		case 2:
			ficheros.sort(Seleccion_beneficio);
			break;
		case 3:
			ficheros.sort(Seleccion_relacion);
	}
	for (std::list<texto>::iterator it=ficheros.begin(); it != ficheros.end(); ++it){
		//solucion.push_back(*it);
		if(Factible(*it,solucion)){
			solucion.push_back(*it);
		}else{ 
			if(capa == "P" && m == 0){
				solucion.push_back(*it);
				m++;
			}
		}
	}
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
	//Leemos la imagen
	imagen.LeerImagen(argv[1]);
	//Espacio disponible, recordar que el peso de cada fichero es +1
	espacio=(imagen.num_filas()*imagen.num_cols()/8)-1;

	cargarDatosFicheros(argv[2],argv[3],ficheros);
	
	cout<<"Imagen en la que ocultar: "<<argv[1]<<endl;
	cout<<"Ficheros:"<<endl;
	cout << ficheros << endl;

	cout<<"\n##########################################################################\n";
	cout<<"Capacidad total: "<<espacio<<endl;
	int opcion = atoi (argv[4]);
	string Capa = argv[5];

	Algoritmo_Voraz(opcion,Capa);

	cout << solucion << endl;
	int numero = solucion.size();
	int i=0;
	char **mensaje=new char*[numero];

	for (std::list<texto>::iterator it=solucion.begin(); it != solucion.end(); ++it){
		mensaje[i]= CargaFichero((*it).Get_N().c_str());
		i++;
	}

	Ocultar (imagen, mensaje, numero);
	imagen.EscribirImagen("Voraz.pgm");

	return 0;

}
