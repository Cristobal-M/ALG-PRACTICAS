/**
  * @file texto.h
  * @brief Fichero cabecera del TDA texto
	*
  */

#ifndef __VD_H__
#define __VD_H__

#include <cassert>
#include <iostream>

using namespace std;

class texto{
	
	private:
		char *Nombre;
		double Peso;
		int Beneficio;

		void escribe (ostream& out, char *N){ out << N ; }
	
	public:
		//----------CONSTRUCTOR--------------
		texto(char *N, int B, double P){
			Nombre = N;
			Peso = P;
			Beneficio = B;
		}
		//----------DESTRUCTOR---------------
		~texto();
		//-----------------------------------
		//----------OTRAS FUNCIONES----------
		//-----------------------------------
		double Get_P(){ return Peso; }
		
		int Get_B(){ return Beneficio; }
		
		char * Get_N() { return Nombre; }


		
		void Set (char *N, int B, double P) {
			Nombre = N;
			Peso = P;
			Beneficio = B;
		}
		
		void Set_N (char *N) { Nombre = N; }
		
		void Set_P (double P) { Peso = P; }
		
		void Set_B (int B) { Beneficio = B; }

		friend ostream& operator<< (ostream& out,  texto &t){
			t.escribe(out,t.Nombre);
			return out;
		}
};

#endif
