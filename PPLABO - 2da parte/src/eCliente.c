/*
 * eCliente.c
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#include "eCliente.h"


void MenuPrincipal(int* opcion, int min, int max)
{
	printf("\n\tMENU CLIENTE\n 0. Salir\n"
							 " 1. Alta\n"
							 " 2. Modificacion\n"
							 " 3. Baja\n"
							 " 4. Crear pedido de recoleccion\n"
							 " 5. Procesar residuos\n"
							 " 6. Imprimir clientes\n"
							 " 7. Imprimir pedidos pendientes\n"
							 " 8. Imprimir pedidos procesados\n"
							 " 9. Pedidos pendientes por localidad\n"
							 " 10. Promedio de kilos de PP por cliente\n"
							 " 11. Clientes con mas pedidos pendientes\n"
							 " 12. Clientes con mas pedidos completos\n"
							 " 13. Clientes con mas pedidos\n");
	utn_getEntero(opcion, "\nIngrese una opcion: ", "(!)Opcion invalida. ", min, max);
}

int eCliente_BuscarPorID(eCliente listaCliente[], int tamCliente, int idBuscar)
{
	int index = -1;
	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO && listaCliente[i].idCliente == idBuscar)
		{
			index = i;
		}
	}
	return index;
}




int eCliente_ContarCargados(eCliente listaCliente[], int tamCliente)
{
	int contador = 0;
	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			contador++;
		}
	}
	return contador;
}




//////////////////////////

int eCliente_InicializarIsEmpty(eCliente listaCliente[], int tamCliente)
{
	int retorno = 0;
	int i;
	if(listaCliente != NULL && tamCliente > 0)
	{
		for(i = 0; i<tamCliente; i++)
		{
			listaCliente[i].isEmpty = VACIO_CLIENTE;
		}
		retorno = 1;
	}
	return retorno;
}

int eCliente_BuscarLibre(eCliente listaCliente[], int tamCliente)
{
	int index = -1;
	int i;
	for(i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == VACIO_CLIENTE)
		{
			index = i;
			break;
		}
	}
	return index;
}




/*int eCliente_MostrarPorID(eCliente listaCliente[], int tamCliente, int idBuscar)
{
	int retorno = 0;
	int i;

	for(i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO && listaCliente[i].idCliente == idBuscar)
		{
			//printf("ID BUSCAR: %d\n\n", idBuscar);

			eCliente_MostrarUno(listaCliente[i]);
			retorno = 1;
			break;
		}
	}
	return retorno;
}*/

