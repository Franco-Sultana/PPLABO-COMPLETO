/*
 * Informes.c
 *
 *  Created on: 24 oct. 2021
 *      Author: F2019
 */

#include "Informes.h"
void Info_DarDeAltaCliente(eCliente miCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad)
{
	switch(eCliente_Alta(miCliente, tamCliente, id, listaLocalidad, tamLocalidad))
	{
	case 1:
		printf("Se dio de alta correctamente\n -Id generado para este cliente: %d\n", *id - 1);
	break;
	case 0:
		printf("(0)No hay espacio para cargar mas clientes\n");
	break;
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -2:
		printf("(X)Se canceló el alta\n");
	break;
	}
}

void Info_ModificarCliente(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	switch(eCliente_Modificacion(listaCliente, tamCliente, listaLocalidad, tamLocalidad))

	{
	case 1:
		printf("Se modifico correctamente\n");
	break;
	case 0:
		printf("(-)Aun no hay Cliente cargados\n");
	break;
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -2:
		printf("(X)Se cancelo la modificacion\n");
	break;
	}
}


void Info_DarDeBajaCliente(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocaldiad)
{
	switch(eCliente_Baja(listaCliente, tamCliente, listaLocalidad, tamLocaldiad))
	{
	case 1:
		printf("Se dio de baja correctamente\n");
	break;
	case 0:
		printf("(-)Aun no hay Cliente cargados\n");
	break;
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -2:
		printf("(X)Se canceló la baja\n");
	break;
	}
}

void Info_CrearPedidoPedido(ePedido miPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocaldiad)
{
	switch(ePedido_CrearPedido(miPedido, tamPedido, listaCliente, tamCliente, id, listaLocalidad, tamLocaldiad))
	{
	case 1:
		printf("Se creo el pedido correctamente\n");
	break;
	case 2:
		printf("(0)No hay espacio para cargar mas pedidos\n");
	break;
	case 0:
		printf("(-)Aun no hay clientes cargados\n");
	break;
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -2:
		printf("(X)Se canceló la creacion del pedido\n");
	break;
	}
}

void Info_ProcesarResiduosPedido(ePedido listaPedido[], int tamPedido)
{
	switch(ePedido_ProcesarResiduos(listaPedido, tamPedido))
	{
	case 1:
		printf("Se completo el pedido\n");
	break;
	case 2:
		printf("(0)No hay espacio para cargar mas Pedido\n");
	break;
	case 0:
		printf("(-)Aun no hay predidos pendientes\n");
	break;
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -2:
		printf("(X)Se canceló el procesar residuos\n");
	break;
	}
}

void Info_ListarClientesPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocaldiad)
{
	switch(eCliente_ListadoPendientes(listaPedido, tamPedido, listaCliente, tamCliente, listaLocalidad, tamLocaldiad))
	{
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case 0:
		printf("(-)Aun no hay pedidos pendientes\n");
	break;
	}
}


void Info_ListarPedidosPendientesConCliente(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	switch(ePedido_ListadoPendientesConCliente(listaPedido, tamPedido, listaCliente, tamCliente))
	{
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case 0:
		printf("(-)Aun no hay pedidos pendientes\n");
	break;
	}
}

void Info_ListarPedidosCompletados(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	switch(ePedido_MostrarProcesados(listaPedido, tamPedido, listaCliente, tamCliente))
	{
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case 0:
		printf("(-)Aun no hay pedidos completados");
	break;
	}
}

/*void Info_MostrarCantidadPorLocalidad(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	switch(ePedido_MostrarPendientesPorLocalidad(listaPedido, tamPedido, listaCliente, tamCliente, listaLocalidad, tamLocalidad))
	{
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case 0:
		printf("(-)Aun no hay pedidos pendientes en esta localidad\n");
	break;
	}
}
*/
void Info_MostrarPromedioKilosPP(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	switch(ePedido_CalcularPromedio(listaPedido, tamPedido, listaCliente, tamCliente))
	{
	case -1:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case 0:
		printf("(-)Aun no hay clientes cargados\n");
	break;
	}
}

