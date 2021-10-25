/*
 * Informes.h
 *
 *  Created on: 24 oct. 2021
 *      Author: F2019
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Nexo.h"

/**
 * @fn void Info_DarDeAltaCliente(eCliente[], int, int*)
 * @brief Informa lo que paso con la funcion de dar de alta
 * @param miCliente array de cliente
 * @param tamCliente tamaño de array cliente
 * @param id puntero a direccion de memoria del id autoincremental de cliente
 */
void Info_DarDeAltaCliente(eCliente miCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn void Info_ModificarCliente(eCliente[], int)
 * @brief Mustra al usuario lo que paso con la funcion de modificar
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 */
void Info_ModificarCliente(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);


/**
 * @fn void Info_DarDeBajaCliente(eCliente[], int)
 * @brief Muestra al usuario lo que paso con la funcion de baja
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 */
void Info_DarDeBajaCliente(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocaldiad);


/**
 * @fn void Info_CrearPedidoPedido(ePedido[], int, eCliente[], int, int*)
 * @brief Informa lo que paso con la funcion de crear pedido
 * @param miPedido array de pedido
 * @param tamPedido tamaño del array pedido
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @param id puntero a direccion de memoria del id autoincremental de pedido
 */
void Info_CrearPedidoPedido(ePedido miPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocaldiad);

/**
 * @fn void Info_ProcesarResiduosPedido(ePedido[], int)
 * @brief muestra lo que pasó con la funcion de procesar residuos
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 */
void Info_ProcesarResiduosPedido(ePedido listaPedido[], int tamPedido);

/**
 * @fn void Info_ListarClientesPendientes(ePedido[], int, eCliente[], int)
 * @brief muestra lo que paso con la funcion de mostrar clientes con cantidad de pedidos PENDIENTES
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 */
void Info_ListarClientesPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocaldiad);

/**
 * @fn void Info_ListarPedidosPendientesConCliente(ePedido[], int, eCliente[], int)
 * @brief encabezado para lista de pedidos en estado PENDIENTE con datos de su cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array cliente
 * @param tamCliente tamaño del array cliente
 */

void Info_ListarPedidosPendientesConCliente(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

/**
 * @fn void Info_ListarPedidosCompletados(ePedido[], int, eCliente[], int)
 * @brief muestra lo que pasó con la funcion de mostrar los pedidos completados con datos de su cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 */
void Info_ListarPedidosCompletados(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

/**
 * @fn void Info_MostrarCantidadPorLocalidad(ePedido[], int, eCliente[], int)
 * @brief Mustra lo que pasó con la funcion de mostrar pedidos PENDIENTES  localidad
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array cliente
 */
void Info_MostrarCantidadPorLocalidad(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn void Info_MostrarPromedioKilosPP(ePedido[], int, eCliente[], int)
 * @brief muetra lo que paso con la funcion de calcular y mostrar el promedio de PP
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 */
void Info_MostrarPromedioKilosPP(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

#endif /* INFORMES_H_ */
