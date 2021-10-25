/*
 * ePedido.c
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#include "ePedido.h"
void MenuPedido(int* opcion, int min, int max)
{
	printf("\n\t MENU Pedido\n"
		   " 0. Salir\n"
		   " 1. Alta\n"
		   " 2. Baja\n"
		   " 3. Modificacion\n"
		   " 4. Listado\n");
	utn_getEntero(opcion, "Ingrese una opcion: ", "(!)Fuera de rango. ", min, max);
}

int ePedido_InicializarIsEmpty(ePedido listaPedido[], int tam)
{
	int retorno = 0;
	int i;
	if(listaPedido != NULL && tam > 0)
	{
		for(i = 0; i<tam; i++)
		{
			listaPedido[i].estado = VACIO_PEDIDO;
			//listaPedido[i].kilosTipos.isEmpty = VACIO;
		}
		retorno = 1;
	}
	return retorno;
}

int eTipoPedido_BuscarLibre(ePedido listaPedido[], int tamTipo)
{
	int index = -1;
	int i;
	for(i = 0; i<tamTipo; i++)
	{
		if(listaPedido[i].kilosTipos.isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}


int ePedido_BuscarLibre(ePedido listaPedido[], int tam)
{
	int index = -1;
	int i;
	for(i = 0; i<tam; i++)
	{
		if(listaPedido[i].estado == VACIO_PEDIDO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int ePedido_BuscarPorId(ePedido listaPedido[], int tam, int idBuscar, int estado)
{
	int index = -1;
	int i;
	for(i = 0; i<tam; i++)
	{
		if(listaPedido[i].estado == estado && listaPedido[i].idPedido == idBuscar)
		{
			index = i;
		}
	}
	return index;
}

int ePedido_ContarCargados(ePedido listaPedido[], int tamPedido)
{
	int contador = 0;
	for(int i = 0; i<tamPedido; i++)
	{
		contador++;
	}
	return contador;
}

int ePedido_PedirIdParaAccion(ePedido listaPedido[], int tamPedido, char msjAccion[])
{
	int id;
	int index;
	utn_getEntero(&id, msjAccion, "(!)Id invalido. ", 1, INT_MAX);
	index = ePedido_BuscarPorId(listaPedido, tamPedido, id, PENDIENTE);
	while(index == -1)
	{
		ePedido_ListadoPendientes(listaPedido, tamPedido);
		utn_getEntero(&id, "Fuera de rango. Reingrese id: ", "(!)Id invalido. ", 1, INT_MAX);
		index = ePedido_BuscarPorId(listaPedido, tamPedido, id, PENDIENTE);
	}
	return index;
}

void ePedido_MostrarUnoPendiente(ePedido unPedido)
{
	printf("%10d %15f\n",unPedido.idPedido ,unPedido.kilos);
}

int ePedido_ListadoPendientes(ePedido listaPedido[], int tamPedido)
{
	int retorno = -1;
	if(listaPedido != NULL && tamPedido > 0)
	{
		retorno = 0;
		ePedido_TituloPendientes(listaPedido, tamPedido);
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedido[i].estado == PENDIENTE)
			{
				ePedido_MostrarUnoPendiente(listaPedido[i]);
				retorno = 1;
			}
		}
	}
	return retorno;
}

void ePedido_TituloPendientes(ePedido listaPedido[], int tamPedido)
{
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado == PENDIENTE)
		{
			printf("\n%10s %15s\n", "ID PEDIDO", "KILOS TOTALES");
			break;
		}
	}
}

void ePedido_TituloCompletados(ePedido listaPedido[], int tamPedido)
{
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado == COMPLETADO)
		{
			printf("%15s %30s %5s %5s %5s\n", "CUIT","DIRECCION","HDPE","LDPE", "PP");
			break;
		}
	}
}

ePedido ePedido_CargarPesoPorTipo(ePedido unPedido)
{
	ePedido auxPedido = unPedido;
	utn_getFlotante(&auxPedido.kilosTipos.kilosHDPE, "Ingrese peso de HDPE: ", "(!)Peso invalido. ", 0, INT_MAX);
	utn_getFlotante(&auxPedido.kilosTipos.kilosLDPE, "Ingrese peso de LDPE: ", "(!)Peso invalido. ", 0, INT_MAX);
	utn_getFlotante(&auxPedido.kilosTipos.kilosPP, "Ingrese peso de PP: ", "(!)Peso invalido. ", 0, INT_MAX);
	while((auxPedido.kilosTipos.kilosHDPE + auxPedido.kilosTipos.kilosLDPE + auxPedido.kilosTipos.kilosPP) > auxPedido.kilos)
	{
		printf("(!)El peso total sobrepasa el peso adquirido del cliente (%f kilos). Reingrese.\n", auxPedido.kilos);
		utn_getFlotante(&auxPedido.kilosTipos.kilosHDPE, "Ingrese peso de HDPE: ", "(!)Peso invalido. ", 0, INT_MAX);
		utn_getFlotante(&auxPedido.kilosTipos.kilosLDPE, "Ingrese peso de LDPE: ", "(!)Peso invalido. ", 0, INT_MAX);
		utn_getFlotante(&auxPedido.kilosTipos.kilosPP, "Ingrese peso de PP: ", "(!)Peso invalido. ", 0, INT_MAX);
	}
	return auxPedido;
}

int ePedido_ProcesarResiduos(ePedido listaPedido[], int tamPedido)
{
	int retorno = -1;
	int i;
	ePedido auxPedido;
	int banderaCargado = 0;

	if(listaPedido != NULL && tamPedido > 0)
	{
		retorno = 0;
		if(ePedido_ListadoPendientes(listaPedido, tamPedido) == 1)
		{
			banderaCargado = 1;
		}
		if(banderaCargado == 1)
		{
			retorno = 2;
			i = ePedido_PedirIdParaAccion(listaPedido, tamPedido, "Ingrese el id de un pedido para a procesar residuos: ");
			if(listaPedido[i].kilosTipos.isEmpty == VACIO)
			{
				retorno = -2;
				auxPedido = ePedido_CargarPesoPorTipo(listaPedido[i]);
				if(utn_getRespuestaSiNo("Desea procesar los residuos?") == 1)
				{
					retorno = 1;
					listaPedido[i] = auxPedido;
					listaPedido[i].estado = COMPLETADO;
					listaPedido[i].kilosTipos.isEmpty = LLENO;
				}
			}

		}
	}
	return retorno;
}



