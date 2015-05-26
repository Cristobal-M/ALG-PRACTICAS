/**
 * @file imagen.h
 */
#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;
typedef unsigned char  Pixel;
/** @brief TDA Imagen. Es una matriz de nxm filas, columnas de pixeles.
 * 
 * */

class Imagen{
  private:
    Pixel  ** data;//< espacio para almacenar los pixeles de la imagen
    int nf,nc; //< numero de filas y columnas
    /** 
     * @brief Elimina la memoria asignada a la matriz
     */
    void Borrar();
    /**
     * @brief Copia una imagen en otra.
     */
    void Copiar(const Imagen &I);
  public:
    /**
     * @brief Constructor por defecto
     */
   Imagen();
    /**
     * @brief Constructor por parametros. Reserva espacio para una imageen con un determinado nuemro de filas 
     * y columnas. Todos los pixeles se inician a blanco.
     * @param f: numero de filas
     * @param c: numero de columnas
     */
   Imagen(int f,int c);
   /**
     * @brief Constructor de copia
     * @param I: imagen a ser copiada
    */
   Imagen(const Imagen & I);
    /**
     * @brief Asignacion
     * @param I: imagen que se asigna
    */
   Imagen & operator=(const Imagen & I);
    /**
     * @brief Destructor
    */
   ~Imagen();
   
   //set y get
   /** @brief Permite acceder al pixel en la fila i columna j
    *  @param i: fila
    *  @param j: columna
    *  @return el pixel en la posicion i,j
    */
   Pixel & operator ()(int i,int j);
   
   const Pixel & operator ()(int i,int j)const;
   
   /**@brief Escribe una imagen en disco
    * @param: nombre del fichero en disco. 
    * @post: El formato de la imagen es pgm
    * */

   void EscribirImagen(const char * nombre);
   
   /**@brief Carga una imagen en memoria
    * @param: nombre del ficheor en disco. 
    * @pre: el formato de imagen debe ser pgm
    * */
   void LeerImagen (const char *nombre);
   
   
   /**@brief Obtiene el numero de filas y columnas de la imagen
    * */
   int num_filas()const{return nf;}
   int num_cols()const{return nc;}
   
};   
   
#endif