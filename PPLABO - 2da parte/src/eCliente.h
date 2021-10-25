/*
 * eCliente.h
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <limits.h>
#include <ctype.h>


#define LLENO 0
#define VACIO_CLIENTE 1
#define TAM_CLIENTE 10

typedef struct
{
	int idCliente;
	int idLocalidad;
	char nombreEmpresa[30];
	char direccion[30];
	char cuit[13];
	int isEmpty;
}eCliente;

/**
 * @fn void eCliente_Menu(int*, int, int)
 * @brief Muestra el menu de opciones al usuario y pide que ingrese una opcion
 * @param opcion puntero a direccion de memoria donde apunta opcion
 * @param min opcion minima
 * @param max opcion maxima
 */
void MenuPrincipal(int* opcion, int min, int max);

/**
 * @fn int eCliente_BuscarPorID(eCliente[], int, int)
 * @brief Busca por id
 * @param listaCliente array de Cliente
 * @param tamCliente tamaño de array Cliente
 * @param idBuscar id a buscar
 * @return -1: si no encontro el id | La posicion en el array: si lo encontro
 */
int eCliente_BuscarPorID(eCliente listaCliente[], int tamCliente, int idBuscar);

/**
 * @fn int eCliente_InicializarIsEmpty(eCliente[], int)
 * @brief Inicializa el campo is empty en VACIO (1).
 * @param listaGen array de cliente
 * @param tamCliente tam del array cliente
 * @return 0: si alguno de los parametros recibido es erroneo | 1: si pudo inicializar
 */
int eCliente_InicializarIsEmpty(eCliente listaCliente[], int tamCliente);

/**
 * @fn int eCliente_BuscarLibre(eCliente[], int)
 * @brief Busca en el array si hay un espacio libre y retorna su indice
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @return -1: Si no encontro espacio libre | La posicion en el array: si lo encontro
 */
int eCliente_BuscarLibre(eCliente listaCliente[], int tamCliente);

/**
 * @fn void eCliente_Titulo(eCliente[], int)
 * @brief Encabezado para lista de clientes
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array cliente
 */
void eCliente_Titulo(eCliente listaCliente[], int tamCliente);

void acomodarTexto(char texto[]);

int eCliente_ContarCargados(eCliente listaCliente[], int tamCliente);

#endif /* ECLIENTE_H_ */
