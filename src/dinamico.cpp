#include "imagen.h"
#include "utilidades.h"
#include "texto.h"
#include <list>
#include <stdlib.h>


ostream & operator<<(ostream & s, const vector <texto> &f){
	//s << fin << endl;
	s <<std::setw(50)<<std::left<< "Ruta" 
			<<std::setw(10)<<std::left<<"Beneficio"
			<<std::setw(10)<<std::left<<"Peso"
			<<endl;
	for (int i = 0; i < f.size(); ++i)
	{
		s << f[i] << endl;
	}
	
	return s;

}
void cargarDatosFicheros(char *rutaFichero,char *dir,vector<texto> &lista){
	lista.resize(0);
	ifstream fi (rutaFichero);

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
		texto t=texto(f, atoi(b.c_str()), atof(p.c_str()));
		lista.push_back(t);
	}
}


void Algoritmo_Memoria_Dinamica (vector<Texto> &solucion, vector<Texto> obj, int capacidad){
	solucion.resize(0);
	//por si se hace fraccionado lo pongo float
	vector<vector<float> > V(obj.size()+1, vector<float>(capacidad) +1);
	//inicializamos la matriz
	for (int i = 0; i < V.size(); ++i){
		//Primera columna 0 de capacidad
		V[i][0]=0;
	}
	for (int i = 0; i < V[0].size(); ++i){
		//Primera fila 0 objetos =0
		V[0][i]=0;
	}

		
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			/* code */
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
	espacio=imagen.num_filas()*imagen.num_cols()-1;

	cargarDatosFicheros(argv[2],argv[3],ficheros);
	
	cout<<"Imagen en la que ocultar: "<<argv[1]<<endl;
	cout<<"Ficheros:"<<endl;
	cout << ficheros << endl;

	cout<<"\n##########################################################################\n";
	cout<<"Capacidad total: "<<espacio<<endl;
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
	*/

	Algoritmo_Voraz(opcion);
	cout << solucion << endl;

	//operator<<(cout,ficheros);
	//cout << ficheros ;
	return 0;

}
