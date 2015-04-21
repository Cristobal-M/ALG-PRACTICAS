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
		int Peso;
		int Beneficio;
	
	public:
		//----------CONSTRUCTOR--------------
		texto();
		//----------DESTRUCTOR---------------
		~texto() { delete [] Nombre; }
		//-----------------------------------
		//----------OTRAS FUNCIONES----------
		//-----------------------------------
		int Get_P(){ return Peso; }
		
		int Get_B(){ return Beneficio; }
		
		char& Get_N() { return Nombre; }
		
		void Set (char *N, int P, int B) {
			Nombre = N;
			Peso = P;
			Beneficio = B;
		}
		
		void Set_N (char *N) { Nombre = N; }
		
		void Set_P (int P) { Peso = P; }
		
		void Set_B (int B) { Beneficio = B; }
	
};

#endif
