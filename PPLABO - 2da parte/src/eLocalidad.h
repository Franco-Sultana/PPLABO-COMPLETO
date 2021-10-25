/*
 * eLocalidad.h
 *
 *  Created on: 25 oct. 2021
 *      Author: F2019
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <limits.h>
#include <ctype.h>

#define LLENO 0
#define VACIO 1
#define TAM_LOCALIDAD 5

typedef struct
{
	int idLocalidad;
	char descripcion[30];
	int isEmpty;
}eLocalidad;



/**
 * @fn int eLocalidad_BuscarPorID(eLocalidad[], int, int) Busca por id
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño de array Localidad
 * @param idBuscar id a buscar
 * @return -1: si no encontro el id | La posicion en el array: si lo encontro
 */
int eLocalidad_BuscarPorID(eLocalidad listaLocalidad[], int tamLocalidad, int idBuscar);

/**
 * @fn int eLocalidad_RetornarIdPorIndice(eLocalidad[], int, int) retorna el id que esta en el indice pasado
 * @param listaLocalidad array de Localidad
 * @param indice posicion del array a buscar el id
 * @param tamLocalidad tamaño del array Localidad
 * @return -1: si no encontro un Localidad en el indice pasado | id: si lo encontro
 */
int eLocalidad_RetornarIdPorIndice(eLocalidad listaLocalidad[], int indice, int tamLocalidad);


/**
 * @fn int eLocalidad_ContarCargados(eLocalidad[], int) cuenta cuantos Localidad hay cargados
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño del array Localidad
 * @return 0: si no hay Localidad cargados | el contador cargado: si hay Localidad cargados
 */
int eLocalidad_ContarCargados(eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eLocalidad_ObterIdDelIndex(eLocalidad[], int)
 * @brief obtiene el id del indice que ingrese el usuario
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño del array Localidad
 * @return el id del Localidad cargado en el indice que ingreso el usuario
 */
int eLocalidad_ObterIdDelIndex(eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eLocalidad_ReordenarArray(eLocalidad[], int)
 * @brief reordena el array cuando se da de baja un Localidad
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño del array Localidad
 * @return 0: si no puedo reordenar | 1: si pudo
 */
int eLocalidad_ReordenarArray(eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eLocalidad_InicializarIsEmpty(eLocalidad[], int)
 * @brief inicializa el campo isEmpty del array Localidad en VACIO
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño del array Localidad
 * @return 0: si no pudo inicializar | 1: si pudo
 */
int eLocalidad_Harcodear(eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eLocalidad_BuscarLibre(eLocalidad[], int)
 * @brief buscar y retorna el indice del Localidad que este con el campo isEmpty en VACIO
 * @param listaLocalidad array de Localidad
 * @param tamLocalidad tamaño del array Localidad
 * @return -1: si no encontro espacio disponible | un indice del array: si encontro espacio
 */
int eLocalidad_BuscarLibre(eLocalidad listaLocalidad[], int tamLocalidad);


void eLocalidad_MostrarUno(eLocalidad unLocalidad);

int eLocalidad_Listado(eLocalidad listaLocalidad[], int tamLocalidad);

int eLocalidad_MostrarListaNumerada(eLocalidad listaLocalidad[], int tam);

void eLocalidad_Titulo(eLocalidad listaLocalidad[], int tamLocalidad, char msj1[], char msj2[]);

void Info_ListarLocalidad(eLocalidad listaLocalidad[], int tamLocalidad);

#endif /* ELOCALIDAD_H_ */
