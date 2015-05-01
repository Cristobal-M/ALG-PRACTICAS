/**
  * @file texto.h
  * @brief Fichero cabecera del TDA texto
	*
  */

#ifndef __VD_H__
#define __VD_H__

#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

class texto{
	
	private:
		string Nombre;
		double Peso;
		int Beneficio;

		void escribe (ostream& out){ 
			out <<std::setw(50)<<std::left<< Nombre 
			<<std::setw(10)<<std::left<<Beneficio
			<<std::setw(10)<<std::left<<Peso; 
		}
	
	public:
		//----------CONSTRUCTOR--------------
		texto(){
		}
		texto(string N, int B, double P){
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
		
		string Get_N() { return Nombre; }


		
		void Set (string N, int B, double P) {
			Nombre = N;
			Peso = P;
			Beneficio = B;
		}
		
		void Set_N (char *N) { Nombre = N; }
		
		void Set_P (double P) { Peso = P; }
		
		void Set_B (int B) { Beneficio = B; }

		friend ostream& operator<< (ostream& out,  texto &t){
			t.escribe(out);
			return out;
		}
		friend ostream& operator<< (ostream& out, const texto &t){
			out <<std::setw(50)<<std::left<< t.Nombre 
			<<std::setw(10)<<std::left<<t.Beneficio
			<<std::setw(10)<<std::left<<t.Peso; 
			return out;
		}
};

#endif
