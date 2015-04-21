#ifndef __UTILIDADES__H
#define __UTILIDADES__H
#include <fstream>
#include <iostream>
#include "imagen.h"
#include <cstring>
using namespace std;

unsigned long int Longitud(ifstream &f);
  

/** @brief Carga en memoria un fichero de disco
 *  @param nombre: el nombre del fichero en disco
 *  @param tam_file. Si tam_file es -1 se lee todo el fichero sino el numero que indica. tam_file se modifica al numero de caracteres leidos mas el '\0'al final
 * @return el vector con los datos del fichero. termina en '\0'
 */

char * CargaFichero (const char *nombre);
  

/** @brief Salva un mensaje a disco 
 *  @param datos: vector con el mesaja a ser guardado.
 *  @param nombre: el nombre del fichero a crear en disco
 */


void SaveFichero (const char *datos,const char *nombre);

/** @brief Oculta un numero de mensajes en la imagen
 *  @param I: imagen donde ocultar los datos
 *  @param mensajes: vector con los mensajes a ocultar
 *  @param numero : numero de mensajes a ocultar
 * */

void Ocultar(Imagen &I,char** mensajes,unsigned int numero);





/** @brief Revela los mensajes de una imagen en disco
 *  @param I: imagen donde esta la informacion oculta
 *  @param numero: contendra el numero de mensajes revelados. ES MODFIICADO
 *  @return un vector de cadenas de caracteres con los diferentes mensajes
 * */


char ** Revelar(const Imagen &I,unsigned int &numero );
#endif