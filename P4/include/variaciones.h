#ifndef __PERMU__H
#define __PERMU__H
#include <vector>
#include <iostream>
using namespace std;
/**
   @brief T.D.A. Variacion
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Variaciones de m sobre n, sobre un dominio de enteros
   genera secuencias de valores no repetidos de longitud n con los m elementos.
   Esta secuencia se corresponde con una variación de m sobre n
    Ejemplo m=4 (1,2,3,4) n=2 Son las variaciones de 4 elementos sobre 2 que son:
    1 2 
    1 3 
    1 4 
    2 1 
    3 1
    4 1
    2 3
    2 4
    3 2
    4 2
    3 4
    4 3
    
   
   Para poder usar el tipo de dato Variaciones se debe incluir el fichero
   
   <tt>\#include variaciones.h</tt>
   
   @author Rosa Mª Rodríguez Sánchez
   @date 20 de Abril de 2015
*/



class Variaciones{
  private:
     vector<unsigned int>  datos; //< objeto para almacenar la variacion
     unsigned int m; 
     unsigned int n; // mantiene la profundidad por la que vamos
     
     
    /** @brief Genera la siguiente variacion hasta el nivel del momento
    *   @param nivel: el nivel por el que va la generacion dela variacion
    
    */  
     void GenerarSiguiente( int nivel);

    /** @brief Comprueba si la secuencia dada hasta el nivel es prefijo de una variacion
     * @param nivel: el nivel por el que va la generacion de la variacion
     
     * @return true si la secuencia actual de datos hasta nivel es una posible variacion
     *         false en caso contrario
     * 
     */      
     bool PosibleVariacion(int nivel);
     
     
    /** @brief Comprueba si la secuencia, ya con n elementos  dada es una variacion
     * @param nivel: el nivel por el que va la generacion dela variacion
     * @return true si la secuencia actual de datos es variacion
     *         false en caso contrario
     * 
     */      
     bool EsVariacion( int nivel);
     
    
     /** @brief Comprueba si la secuencia, de longitud nivel, se le puede poner valores diferentes en la                    posicion nivel (hermanos en el arbol de soluciones).
     * @return true si se puede generar un prefijo de variacion de longitud nivel
     *         false en caso contrario
     * 
     */      
     bool MasHermanos( int nivel);
     
     
     /** @brief Mira si this es un prefijo de v
      * @return true si this es prefijo de v y false en caso contrario
      * */
     
     bool Espadre(Variaciones &v);
     
   public:
    
    /** @brief Constructor por defecto.
    * @note inicializa datos con su contructor y nivel lo pone a 0
    */ 
    Variaciones(){ }
   
   /** @brief Constructor con parametros de variaciones 
    * @param v: el vector con que se inicializa la variacion. 
    * @param nn: el nivel al que se inializa la variacion
    */ 
   
    Variaciones(vector<unsigned int> &v,int nn){
       datos = v;
       n=nn;
       m=v.size();
    }   
   
   
   /** @brief Constructor con parametros de variaciones m 
    * @param m: elementos totales con los que se puede formar la variacion
    * @note inicializa datos con capacidad m y todos los valores inicializados a 0. el nivel se inicia a 1
    * 
    */ 
   
    Variaciones(unsigned int m );
   
    /** @brief Devuelve el numero de variaciones almacenadas en el objeto

    */ 
    unsigned int NumeroVariacionesPosibles()const;
   
  
    /** @brief Genera la siguiente variacion a la ultima y modifica esta. La siguiente en anchura
     **/
    bool GeneraSiguienteAnchura();
    
    
    /** @brief Genera la siguiente variacion a la ultima y modifica esta. La siguiente en  profundidad
     **/
    bool GeneraSiguienteProfundidad();
    
   
    /** @brief Modifica el parametro que indica la longitud de la variacion 
     *  @param nuevonivel: valor con el que se modifica n
     **/ 
    void PutNivel(unsigned int nuevonivel){
      if (nuevonivel<n){
      for (unsigned int i=nuevonivel;i<n;i++)
	 datos[i]=0;
      
       n=nuevonivel;
      } 
    }  
    
    /** @brief Buscan en algunos de los niveles anteriores una posible secuencia
     * @return true: si la encuentra, false en caso contrario
     */
    bool Backtracking();
    
    
    /** @brief Devuelve el nivel por donde va
     */
    
    unsigned int Nivel (){
      return n;
    }  
    /** @brief Devuelve los valores de la variacion
     */
    
    vector<unsigned int> GetVariacion(){
      return datos;
    }
    /** Obtiener todas las permutaciones descendientes de nodo por el que va**/
    
    vector<vector<unsigned int> > GeneraHijos();
    
    
    
   /** @brief Clase iterator Recorre las variaciones almacenadas**/
   
   
    class iterator{
    private:
       vector<unsigned int> ::iterator it;
       vector<unsigned int> ::iterator fin;
    public:
        iterator (){ }
        iterator & operator++(){
	
	     ++it;
	    return *this;
	}
	
	iterator & operator --(){
	   --it;
	  return *this;
	}
	
	bool operator ==(const iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const iterator & i)const{
	   return (i.it!=it);
	}  
	
	const unsigned int & operator*()const {
	   return *it;
	}
	friend class Variaciones;
    };
    
    
    
    class const_iterator{
    private:
       vector<unsigned int>::const_iterator it;
        vector<unsigned int> ::const_iterator fin;
    public:
        const_iterator (){ }
        
        const_iterator & operator++(){
	    
	     ++it;
	    return *this;
	}
	
	const_iterator & operator --(){
	  
	  --it;
	  return *this;
	}
	
	bool operator ==(const const_iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const const_iterator & i)const {
	   return (i.it!=it);
	}  
	
	const unsigned int & operator*()const {
	   return *it;
	}
	friend class Variaciones;
    };
    
    
    
    
    
    /** Metodos para iniciar y ver donde termina los iteradores de variaciones**/
    
    iterator begin(){
	iterator i;
	
	i.it=datos.begin();
	if (n<m)
	  i.fin= datos.begin()+n;
	else 
	  i.fin = datos.end();
	return i;
    }
    
    iterator end(){
        iterator i;
	if (n<m)
	  i.fin= datos.begin()+n;
	else 
	  i.fin = datos.end();
	i.it=i.fin;
	return i;
    }
    
    
    const_iterator begin()const{
	const_iterator i;
	i.it=datos.begin();
	if (n<m)
	  i.fin= datos.begin()+n;
	else 
	  i.fin = datos.end();
	return i;
    }
    
    const_iterator end()const{
        const_iterator i;
	if (n<m)
	  i.fin= datos.begin()+n;
	else 
	  i.fin = datos.end();
	i.it=i.fin;
	return i;
    }
};
#endif
	
	
	