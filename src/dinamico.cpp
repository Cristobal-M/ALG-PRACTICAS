#include "imagen.h"
#include "utilidades.h"
#include "texto.h"
#include <list>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <chrono>
using namespace std::chrono;

ostream & operator<<(ostream & s, const vector <texto> &f){
	//s << fin << endl;
	s <<std::setw(50)<<std::left<< "Ruta" 
			<<std::setw(10)<<std::left<<"Beneficio"
			<<std::setw(10)<<std::left<<"Peso"
			<<endl;
	for (int i = 0; i < (int)f.size(); ++i)
	{
		s << (texto)f.at(i) << endl;
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


void Algoritmo_Memoria_Dinamica (vector<texto> &solucion, vector<texto> objs, int capacidad){
	solucion.resize(0);
	vector<vector<int> > V(objs.size()+1, vector<int>(capacidad+1) );

	//inicializamos la matriz
	for (int i = 0; i < (int)V.size(); ++i){
		//Primera columna 0 de capacidad
		V[i][0]=0;
	}
	for (int i = 0; i < (int)V[0].size(); ++i){
		//Primera fila 0 objetos =0
		V[0][i]=0;
	}

	for (int i = 1; i < (int)V.size(); ++i){
		//+1 -> peso extra por el \0
		int p=objs[i-1].Get_P()+1;
		int b=objs[i-1].Get_B();
		for (int j = 1; j < (int)V[0].size(); ++j){
			int v1,v2;
			//Menos infinito
			v1=v2=-INT_MAX;
			//Si se salen de rango se queda infinito
			if((i-1)>=0)
				v1=V[i-1][j];
			if((i-1)>=0 && (j-p)>=0)
				v2=V[i-1][j-p]+b;
			V[i][j]=std::max(v1,v2);
		}
	}
//cout<<"jajajajajajajjajajajajaja"<<V.size()-1<<endl<<flush;
	//Componemos la solucion
	int j=(int)V[0].size()-1;
	for (int i = (int)V.size()-1; i >= 1; --i){
//		cout<<"jajajajajajajjajajajajaja"<<i<<"ja"<<endl<<flush;
		int p=objs[i-1].Get_P();
		int b=objs[i-1].Get_B();
		if((j-p)>=0 && i-1>=0 && V[i][j]==V[i-1][j-p]+b){
			solucion.push_back(objs[i-1]);
			j=j-p;
		}

		if( (i-1)>=0 && V[i][j]==V[i-1][j])
			j--;
	}
	
}

int main(int argc, char *argv[]){

	if (argc<4 ){
		cout<<"Los parametros son:"<<endl;
  		cout<<"1.- Ejecutable "<<endl;
	  	cout<<"2.- La imagen donde ocultar"<<endl;
  		cout<<"3.- El fichero .txt"<<endl;
  		cout<<"4.- Carpeta donde se encuentran los ficheros"<<endl;
  		return 0;
	}
	Imagen imagen;
	vector<texto> ficheros,solucion;
	//Leemos la imagen
	imagen.LeerImagen(argv[1]);
	//Espacio disponible, recordar que el peso de cada fichero es +1
	int espacio=(imagen.num_filas()*imagen.num_cols()/8)-1;

	cargarDatosFicheros(argv[2],argv[3],ficheros);
	if(argc==4){
		cout<<"Imagen en la que ocultar: "<<argv[1]<<endl;
		cout<<"Ficheros:"<<endl;
		cout << ficheros << endl;
	}
	/*********************************************
	*INICIO DEL ALGORITMO
	*********************************************/
	high_resolution_clock::time_point tAntes, tDespues;
	tAntes = high_resolution_clock::now();
	Algoritmo_Memoria_Dinamica (solucion, ficheros, espacio);
	tDespues = high_resolution_clock::now();
	/*********************************************
	*FIN DEL ALGORITMO
	*********************************************/
	duration<double> transcurrido = duration_cast<duration<double>>(tDespues - tAntes);
	printf("%d %f\n",(int)ficheros.size(),transcurrido.count());

	if(argc==4){
		cout<<"\n##########################################################################\n";
		cout<<"Capacidad total: "<<espacio<<endl;
		cout << solucion << endl;
	}

	int numero = solucion.size();
	char **mensaje=new char*[numero];

	for (unsigned i=0; i < solucion.size(); ++i){
		mensaje[i]= CargaFichero( solucion[i].Get_N().c_str() );
	}

	Ocultar (imagen, mensaje, numero);
	imagen.EscribirImagen("dinamico.pgm");
}
