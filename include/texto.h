/**
  * @file texto.h
  * @brief Fichero cabecera del TDA texto
	*
  */

#ifndef __VD_H__
#define __VD_H__

#include <cassert>

class texto{
	
	private:
		char *Nombre;
		double Peso;
		int Beneficio;
	
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
	
};

#endif
