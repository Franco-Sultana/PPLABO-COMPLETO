/*
 * ePedido.h
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#ifndef EPEDIDO_H_
#define EPEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "limits.h"
#define VACIO_PEDIDO -1
#define VACIO 1
#define LLENO 0
#define PENDIENTE 0
#define COMPLETADO 1
#define TAM_PEDIDO 100


typedef struct
{
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int idPedido;
	int isEmpty;
}ePesoTipo;

typedef struct
{
	int idPedido;
	int idCliente;
	float kilos;
	ePesoTipo kilosTipos;
	int estado;

}ePedido;

/**
 * @fn void Menu(int*, int, int)
 * @brief Muestra en pantalla el menu de opciones de Pedido y pide al usuario que elija una
 * @param opcion Puntero a la direccion de memoria de la opcion que elige el usuario
 * @param min numero de opcion minimo aceptado
 * @param max numero de opcion maximo aceptado
 */
void MenuPedido(int* opcion, int min, int max);

/**
 * @fn int ePedido_InicializarIsEmpty(ePedido[], int)
 * @brief Inicializa el campo is empty de la estructura Pedido
 * @param listaPedido array de Pedido a inicializar
 * @param tam tamaño del array Pedido
 * @return 1: si pudo inicializar. | 0: si alguno de los parametros vino erroneo
 */
int ePedido_InicializarIsEmpty(ePedido listaPedido[], int tam);


int eTipoPedido_BuscarLibre(ePedido listaTipo[], int tamTipo);
/**
 * @fn int ePedido_BuscarLibre(ePedido[], int)
 * @brief Busca dentro del array de tipo ePedido si hay un campo vacio para poder cargar datos
 * @param listaPedido array de Pedido
 * @param tam tamaño del array Pedido
 * @return -1: si no encontro espacio | La posicion en el array con espacio: si encontro
 */
int ePedido_BuscarLibre(ePedido listaPedido[], int tam);

/**
 * @fn int ePedido_BuscarPorId(ePedido[], int, int)
 * @brief Busca por id
 * @param listaPedido array de Pedido
 * @param tam tamaño del array Pedido
 * @param idBuscar id a buscar
 * @return -1: si no encontro el id | La posicion en el array: si lo encontro
 */
int ePedido_BuscarPorId(ePedido listaPedido[], int tam, int idBuscar, int estado);

/**
 * @fn int ePedido_PedirIdParaAccion(ePedido[], int, char[])
 * @brief Pide al usuario un id para hacer una accion (con cargar pedidos)
 * @param listaPedido array del pedido
 * @param tamPedido tamaño del array pedido
 * @param msjAccion mensaje que se le mostrara al usuario, pidiendo para qué debe ingresar un id
 * @return indice del cliente que tenga el mismo id que ingreso el usuario
 */
int ePedido_PedirIdParaAccion(ePedido listaPedido[], int tamPedido, char msjAccion[]);

/**
 * @fn void ePedido_MostrarUnoPendiente(ePedido)
 * @brief Mustra un pedido pendiente
 * @param unPedido pedido pendiente que se mostrara
 */
void ePedido_MostrarUnoPendiente(ePedido unPedido);

/**
 * @fn int ePedido_ListadoPendientes(ePedido[], int)
 * @brief lista los pedidos que esten en estado PENDIENTE
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedido
 * @return -1: si alguno de los parametros vino erroneo | 0 si no hay pedidos pendientes cargados | 1 si pudo mostrar
 */
int ePedido_ListadoPendientes(ePedido listaPedido[], int tamPedido);

/**
 * @fn void ePedido_TituloPendientes(ePedido[], int)
 * @brief encabezado para lista de pedidos en estado PENDIENTE
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedido
 */
void ePedido_TituloPendientes(ePedido listaPedido[], int tamPedido);

/**
 * @fn void ePedido_TituloCompletados(ePedido[], int)
 * @brief encabezado para lista de pedidos en estado COMPLETADO
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedido
 */
void ePedido_TituloCompletados(ePedido listaPedido[], int tamPedido);

/**
 * @fn ePedido ePedido_CargarPesoPorTipo(ePedido)
 * @brief pide al usuario que ingrese peso por cada tipo de residuos
 * @param unPedido array de pedidos
 * @return auxiliar de pedido con los pesos de cada tipo cargados
 */
ePedido ePedido_CargarPesoPorTipo(ePedido unPedido);

/**
 * @fn int ePedido_ProcesarResiduos(ePedido[], int)
 * @brief pide al usuario cantidad de kilos para poner un pedido en estado COMPLETADO
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @return -1: si alguno de los parametros recibido vino erroneo | 0: si no hay mas espacio | -2 si el usuario cancela el proceso |
 * 			1 si se pudo procesar los residuos
 */
int ePedido_ProcesarResiduos(ePedido listaPedido[], int tamPedido);

#endif /* EPEDIDO_H_ */
