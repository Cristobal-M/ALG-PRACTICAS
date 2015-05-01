#include "imagen.h"
#include "utilidades.h"
#include "texto.h"
#include <list>
#include <stdlib.h>


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
Imagen imagen;
int espacio;

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

void Algoritmo_Voraz (){


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
	espacio=imagen.num_filas()*imagen.num_cols()-1;

	cargarDatosFicheros(argv[2],argv[3],ficheros);
	cout<<"Ficheros:"<<endl;
	cout << ficheros << endl;
	cout<<endl;
	int opcion = atoi (argv[4]);
	/*
	char *joder("Quijote.txt");
	char *puta("Makefile");
	char *jode("mergesort.cpp");
	char *put("areas2010.txt");
	char *p("jcr_eng_man_2010_ini.txt");
	
	char joder[]="Quijote.txt";
	char puta[]="Makefile";
	char jode[]="mergesort.cpp";
	char put[]="areas2010.txt";
	char p[]="jcr_eng_man_2010_ini.txt";

	texto Prueba(joder, 10, 1220);
	texto Prueba2(puta, 10, 859);
	texto Prueba3 (jode, 100, 5990);
	texto Prueba4(put, 200, 4293);
	texto Prueba5(p, 250, 2968);

	ficheros.push_back (Prueba);
	ficheros.push_back (Prueba3);
	ficheros.push_back (Prueba4);
	ficheros.push_back (Prueba5);
	ficheros.push_back (Prueba2);


	char *fi=CargaFichero(argv[2]);
	cout << fi << endl;
	*/
	//########################################################################	
	//Ordenamos la lista dependiendo a lo que se pita por la linea de comandos
	//########################################################################
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
	
	cout << ficheros << endl;

	//operator<<(cout,ficheros);
	//cout << ficheros ;
	return 0;

}
