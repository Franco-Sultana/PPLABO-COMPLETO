/*
 * utn.h
 *
 *  Created on: 2 jul. 2021
 *      Author: F2019
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * input.h
 *
 *  Created on: 18 abr. 2021
 *      Author: F2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_BUFFER 2000
/**
 * @fn int myGets(char*, int longitud)
 * @brief Lee de stdin hasta encontrar '\n' o hasta se haya copiado en cadena un maximo de caracteres (longitud-1)
 *
 * @param cadena  Puntero a espacio de memoria donde se va a copiar la cadena
 * @param longitud  Define tamaño de la cadena
 * @return Retorna 0 si pudo leer la cadena, y -1 si no
 */
int myGets(char* cadena, int longitud);
//****************** ENTEROS ******************//
	/**
	 * @fn int getInt(int* pResultado)
	 * @brief Obtiene un numero entero
	 *
	 * @param pResultado  Puntero a espacio de memoria donde se va a copiar pResultado
	 * @return Retorna 0 si pudo obtener el numero, y -1 si no
	 */
	int getInt(int* pResultado);

	/**
	 * @fn int esNumerica(char*, int)
	 * @brief Es la que analiza que el numero ingresado sea solo entero
	 *
	 * @param cadena  Cadena de caracteres a analizar
	 * @param limite  Maximo al que a cadena puede llegar
	 * @return Retorna 1 si es un número, y 0 si no
	 */
	int esNumerica(char* cadena, int limite);

/**
 * @fn int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
 * @brief Pide un numero al usuario, y despues de verificarlo lo devuelve
 *
 * @param pResultado  Puntero a espacio de memoria donde se va a copiar pResultado
 * @param mensaje  Mensaje que pide un numero
 * @param mensajeError  Mensaje que se muestra si hubo un error
 * @param minimo  Numero minimo que puede ingresar e usuario
 * @param maximo  Numero maximo que puede ingresar e usuario
 * @param reintentos  Es la cantidad de intentos que va a tener el usuario para equivocarse
 * @return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getEnteroConReintentos(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * @fn int utn_getEnteroSinReintentos(int*, char*, char*, int, int)
 * @brief Pide un numero con rango, pero sin reintentos. Despues de verificarlo lo devuelve
 *
 * @param pResultado  Puntero a espacio de memoria donde se va a copiar pResultado
 * @param mensaje  Mensaje que pide un numero
 * @param mensajeError  Mensaje que se muestra si hubo un error
 * @param minimo  Numero minimo que puede ingresar e usuario
 * @param maximo  Numero maximo que puede ingresar e usuario
 * @return 0 si se obtuvo el numero, -1 si no
 */
int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

//***************** FLOTANTES *****************//
	/**
	 * @fn int esNumeroConDecimal(char*, int)
	 * @brief Verifica que el numero ingresado por cadena es flotante
	 *
	 * @param cadena  Cadena de caracteres a analizar
	 * @param limite  Define el tamaño de la cadena
	 * @return 1 si el numero ingresado es correcto, 0 si no
	 */
	int esNumeroConDecimal(char* cadena, int limite);

	/**
	 * @fn int getFloat(float*)
	 * @brief Obtiene un numero flotante
	 *
	 * @param pResultado Puntero a espacio de memoria donde se va a copiar el flotante
	 * @return 0 si pudo obtener el flotante, -1 si no
	 */
	int getFloat(float* pResultado);

/**
 * @fn int utn_getFlotante(float*, char*, char*, float, float, int)
 * @brief Pide un flotante al usuario y lo muestra luego de haberlo verificado
 *
 * @param pResultado Puntero a espacio de memoria donde se va a copiar el flotante
 * @param mensaje mensaje que pide un numero
 * @param mensajeError muestra un mensaje de error en caso de que el numero sea incorrecto
 * @param minimo El numero minimo que puede ingresar el usuario
 * @param maximo El numero maximo que puede ingresar el usuario
 * @param reintentos numero de intentos que tiene el usuario para equivocarse
 * @return 0 si se obtuvo el numero y -1 si no
 */

int utn_getFlotanteReintentos(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
 * @fn int utn_getFlotanteSinReintentos(float*, char*, char*, int, int)
 * @brief Pide un flotante al usuario con rango pero sin reintentos y lo muestra luego de haberlo verificado
 *
 * @param pResultado Puntero a espacio de memoria donde se va a copiar el flotante
 * @param mensaje mensaje que pide un numero
 * @param mensajeError muestra un mensaje de error en caso de que el numero sea incorrecto
 * @param minimo  El numero minimo que puede ingresar el usuario
 * @param maximo El numero maximo que puede ingresar el usuario
 * @return  0 si se obtuvo el numero y -1 si no
 */
int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);


//******** OTRAS FUNCIONES CON NUMEROS *******//
/**
 * @fn int utn_getFecha(int*, int*, int*, char*, int, int)
 * @brief Pide una fecha con los dias de meses validados
 *
 * @param pResultadoMes puntero a espacio de memoria donde se va a copiar el mes
 * @param pResultadoDia puntero a espacio de memoria donde se va a copiar el dia
 * @param pResultadoAnio puntero a espacio de memoria donde se va a copiar el año
 * @param mensajeError muestra un mensaje de error en caso de que el numero sea incorrecto
 * @param anioMin el año minimo que puede ingresar el usuario
 * @param aniMax el año maximo que puede ingresar el usuario
 * @return 1 si se obtuvo la fecha completa y -1 si no
 */
int utn_getFecha(int* pResultadoMes, int* pResultadoDia, int* pResultadoAnio, char* mensajeError, int anioMin, int aniMax);

//***************** CARACTERES*****************//
	/**
	 * @fn int esCaracter(char*, int)
	 * @brief valida si lo que se ingresó es un caracter válido
	 *
	 * @param caracter caracter a analizar
	 * @param limite maximo al que el caracter puede llegar
	 * @return 1 si el caracter es válido, 0 si no
	 */
	int esCaracter(char* caracter, int limite);

	/**
	 * @fn int getChar(char*, int)
	 * @brief obtiene un caracter
	 *
	 * @param pResultado puntero a espacio de memoria donde se va a copiar el caracter
	 * @param longitud largo del caracter del cual no quiero pasarme
	 * @return
	 */
	int getChar(char* pResultado, int longitud);

/**
 * @fn int utn_getRespuestaSiNo(char*)
 * @brief Pide solo 's' o 'n' para respuestas
 *
 * @param mensaje se muestra para mostrar una pregunta de "si" o "no"
 * @return -1 si no se pudo ejecutar, 1 si la respuesta fue "si", 0 si la respuesta fue "no"
 */
int utn_getRespuestaSiNo(/*char* pResultado,*/ char* mensaje);

/**
 * @fn int utn_getCaracter(char*, char*, char*, int)
 * @brief Pide un caracter cualquiera
 *
 * @param pResultado puntero a espacio de memoria donde se va a copiar el caracter
 * @param mensaje se muestra para pedir un caracter
 * @param mensajeError se muestra en caso de que el caracter sea incorrecto
 * @param longitud largo del caracter del cual no me quiero pasar
 * @return
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError);

//************* CADENA CARACTERES**************//

	/**
	 * @fn int getNombre(char*, int)
	 * @brief Obtiene un nombre
	 *
	 * @param pResultado puntero a espacio de memoria donde se va a copiar el nombre
	 * @param longitud largo de la cadena el cual no quiero pasarme
	 * @return 0 si obtuvo el nombre, -1 si no
	 */
	int getNombre(char* pResultado, int longitud);

	/**
	 * @fn int esUnNombre(char*, int)
	 * @brief Verifica que lo que se ingresó sea un nombre válido
	 *
	 * @param pResultado puntero a espacio de memoria donde se va a copiar el nombre
	 * @param limite largo de la cadena el cual no quiero pasarme
	 * @return 1 si el nombre es valido, 0 si no
	 */
	int esUnNombre(char* pResultado, int limite);

/**
 * @fn int utn_getNombre(char*, char*, char*, int)
 * @brief Pide un nombre, y luego de ser validado lo guarda
 *
 * @param pResultado  puntero a espacio de memoria donde se va a copiar el nombre
 * @param mensaje mensaje para pedir el ingreso de un nombre
 * @param mensajeError se muestra en caso de que el nombre sea incorrecto
 * @param longitud largo de la cadena el cual no quiero pasarme
 * @return 1 si pudo obtener el nombre, 0 si no
 */
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int longitud);




	/**
	 * @fn int getTexto(char*, int)
	 * @brief Obtiene un texto
	 *
	 * @param pResultado puntero a espacio de memoria donde se va a copiar el texto
	 * @param longitud largo de la cadena el cual no quiero pasarme
	 * @return 0 si pudo obtener el texto, -1 si no
	 */
	int getTexto(char* pResultado, int longitud);

	/**
	 * @fn int getTexto(char*, int)
	 * @brief Verifica que el texto ingresado sea válido
	 *
	 * @param pResultado puntero a espacio de memoria donde se va a copiar el texto
	 * @param longitud
	 * @return 1 si el texto es válido, 0 si no
	 */
	int esTexto(char* cadena, int limite);

/**
 * @fn int utn_getTexto(char*, char*, char*, int)
 * @brief pide un texto y luego de ser validado lo guarda
 *
 * @param pResultado puntero a espacio de memoria donde se va a copiar el texto
 * @param mensaje para pedir el ingreso de un texto
 * @param mensajeError se muestra en caso de que el texto sea incorrecto
 * @param longitud largo de la cadena el cual no quiero pasarme
 * @return 1 si pudo obtener el nombre, 0 si no
 */
int utn_getTexto(char* pResultado, char* mensaje, char* mensajeError, int longitud);


/**
 * @fn int esCuit(char*, int) Valida que el cuit ingresado sea correcto
 * @param cadena puntero a la direccion de memoria del cuit
 * @param longitud longitud de la cadena
 * @return 1: si el cuit es erroneo | 0: si el cuit es correcto
 */
int esCuit(char* cadena, int longitud);

/**
 * @fn int getCuit(char*, int) copia el cuit que ingresa el usuario en el puntero resultado
 * @param pResultado puntero a direccion de memoria donde se va a guardar el cuit
 * @param longitud largo de la cadena de cuit
 * @return 0: si no pudo copiar ekl cuit |  1: si pudo
 */
int getCuit(char* pResultado, int longitud);

/**
 * @fn int utn_getCuit(char*, char*, char*, int) Pide un cuit al usuario y luego de ser vaidado lo guarda
 * @param cuit puntero a direccion de memoria donde se va a guardar el cuit
 * @param mensaje mensaje que le pide al usuario el ingreso de cuit
 * @param mensajeError mesaje que se muestra en caso de que el usuario meta un cuit erroneo
 * @param longitud largo de la cadena cuit
 * @return 0: si el cuit es erroneo | 1 si pudo cargar el cuit
 */
int utn_getCuit(char* cuit, char* mensaje, char* mensajeError, int longitud);


#endif /* UTN_H_ */
