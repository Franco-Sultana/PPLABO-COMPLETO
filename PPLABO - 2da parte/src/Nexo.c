/*
 * Nexo.c
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#include "Nexo.h"

ePedido ePedido_CargarUno(ePedido listaPedido[], int tamPedido,eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	ePedido auxPedido;

	utn_getEntero(&auxPedido.idCliente, "Ingrese el id de un cliente: ", "(!)Id invalido. ", 1, INT_MAX);
	while(eCliente_BuscarPorID(listaCliente, tamCliente, auxPedido.idCliente) == -1)
	{
		eCliente_Listado(listaCliente, tamCliente, listaLocalidad, tamLocalidad);
		utn_getEntero(&auxPedido.idCliente, "Id no encontrado, reingrese: ", "(!)Id invalido. ", 1, INT_MAX);
	}
	utn_getFlotante(&auxPedido.kilos, "Ingrese el total de kilos: ", "(!)Numero invalido. ", 1, INT_MAX);
	return auxPedido;
}

int ePedido_CrearPedido(ePedido miPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = -1;
	int i;
	ePedido auxPedido;
	int banderaCargadosPendientes = 0;
	if(miPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0 && id != NULL)
	{
		retorno = 0;
		if(eCliente_Listado(listaCliente, tamCliente, listaLocalidad, tamLocalidad) == 1)
		{
			banderaCargadosPendientes = 1;
		}
		if(banderaCargadosPendientes == 1)
		{
			retorno = 2;
			i =  ePedido_BuscarLibre(miPedido, tamPedido);
			if(i != -1)
			{
				retorno = -2;
				auxPedido = ePedido_CargarUno(miPedido, tamPedido, listaCliente, tamCliente, listaLocalidad, tamLocalidad);
				if(utn_getRespuestaSiNo("Desea dar de alta?") == 1)
				{
					miPedido[i] = auxPedido;
					miPedido[i].idPedido = *id;
					*id = *id + 1;
					miPedido[i].estado = PENDIENTE;
					miPedido[i].kilosTipos.isEmpty = VACIO;
					printf("ESTADO KILOS 2: %d\n", miPedido[i].kilosTipos.isEmpty);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

void ePedido_MostrarUnoPendienteConCliente(ePedido unPedido, eCliente unCliente)
{
	printf("%15s %30s %20.2f\n", unCliente.cuit, unCliente.direccion, unPedido.kilos);
}

int ePedido_ListadoPendientesConCliente(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	int retorno = 1;
	int j;
	if(listaPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		ePedido_TituloPendientesConCliente(listaPedido, tamPedido);
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedido[i].estado == PENDIENTE)
			{
				j = eCliente_BuscarPorID(listaCliente, tamCliente, listaPedido[i].idCliente);
				if(j != -1)
				{
					ePedido_MostrarUnoPendienteConCliente(listaPedido[i], listaCliente[j]);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

void ePedido_TituloPendientesConCliente(ePedido listaPedido[], int tamPedido)
{
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado != VACIO_PEDIDO)
		{
			printf("\n%15s %30s %20s\n", "CUIT", "DIRECCION", "KILOS A RECOLECTAR");
			break;
		}
	}
}

void eAuxiliar_InicializarPorCliente(eCliente listaCliente[], int tamAux, eAuxiliar auxiliar[])
{
	for(int i = 0; i<tamAux; i++)
	{
		auxiliar[i].id = listaCliente[i].idCliente;
		auxiliar[i].contador = 0;
		auxiliar[i].acumulador = 0;
		auxiliar[i].isEmpty = VACIO;
	}
}

int eAuxiliar_ContarPedidosPorCliente(ePedido listaPedido[], int tamPedido, eAuxiliar auxiliar[], int idBuscar, int index, int estado)
{
	int retorno = 0;
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado == estado && listaPedido[i].idCliente == idBuscar)
		{

			auxiliar[index].contador ++;
			auxiliar[index].isEmpty = LLENO;
			retorno = 1;
		}
	}
	return retorno;

}

int eAuxiliar_ContarPedidosDistintoPorCliente(ePedido listaPedido[], int tamPedido, eAuxiliar auxiliar[], int idBuscar, int index, int estado)
{
	int retorno = 0;
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado != estado && listaPedido[i].idCliente == idBuscar)
		{

			auxiliar[index].contador ++;
			auxiliar[index].isEmpty = LLENO;
			retorno = 1;
		}
	}
	return retorno;

}

void eCliente_MostrarUnoConCantidadPendientes(eCliente unCliente, eAuxiliar auxiliar, eLocalidad unaLocalidad)
{
	printf("%20d %30s %15s %30s %30s %5d\n", auxiliar.contador, unCliente.nombreEmpresa,unCliente.cuit,
			unCliente.direccion, unaLocalidad.descripcion, unCliente.idCliente);
}

int eCliente_ListadoPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = -1;
	int j;
	eAuxiliar listaAux[tamCliente];

	if(listaCliente != NULL && tamPedido > 0)
	{
		retorno = 0;
		eCliente_TituloCantidadPendientes(listaCliente, tamCliente, listaPedido, tamPedido);
		eAuxiliar_InicializarPorCliente(listaCliente, tamCliente, listaAux);
		for(int i = 0; i<tamCliente; i++)
		{
			if(listaCliente[i].isEmpty == LLENO)
			{
				j = eLocalidad_BuscarPorID(listaLocalidad, tamLocalidad, listaCliente[i].idLocalidad);
				if(j != -1)
				{
					if(eAuxiliar_ContarPedidosPorCliente(listaPedido, tamPedido, listaAux, listaCliente[i].idCliente, i, PENDIENTE) == 1)
					{
						eCliente_MostrarUnoConCantidadPendientes(listaCliente[i], listaAux[i], listaLocalidad[i]);
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}

void eCliente_TituloCantidadPendientes(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int j;
	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			j = ePedido_BuscarPorIdCliente(listaPedido, tamPedido, listaCliente[i].idCliente, PENDIENTE);
			if(j != -1)
			{
				printf("\n%20s %30s %15s %30s %30s %5s\n", "CANTIDAD PENDIENTES" ,"EMPRESA", "CUIT", "DIRECCION",
														   "LOCALIDAD", "ID");
				break;
			}
		}
	}
}

int ePedido_BuscarPorIdCliente(ePedido listaPedido[], int tamPedido, int idBuscar, int estado)
{
	int index = -1;
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado == estado && listaPedido[i].idCliente == idBuscar)
		{
			index = i;
		}
	}

	return index;
}


int ePedido_MostrarProcesados(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	int retorno = -1;
	int j;
	if(listaPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		ePedido_TituloCompletados(listaPedido, tamPedido);
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedido[i].estado == COMPLETADO && listaPedido[i].kilosTipos.isEmpty == LLENO)
			{
				j = eCliente_BuscarPorID(listaCliente, tamCliente, listaPedido[i].idCliente);
				if(j != -1)
				{
					eCliente_MostrarUnClientePedidoCompletado(listaCliente[j], listaPedido[i]);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}


void eCliente_MostrarUnClientePedidoCompletado(eCliente unCliente, ePedido unPedido)
{
	printf("%15s %30s %5.2f %5.2f %5.2f\n", unCliente.cuit, unCliente.direccion, unPedido.kilosTipos.kilosHDPE,
											unPedido.kilosTipos.kilosLDPE, unPedido.kilosTipos.kilosPP);
}





void eAuxiliar_InicializarPorPedido(ePedido listaPedido[],eAuxiliar listaAux[], int tamAux)
{
	for(int i = 0; i<tamAux; i++)
	{
		listaAux[i].id = listaPedido[i].idPedido;
		listaAux[i].contador = 0;
		listaAux[i].isEmpty = VACIO;
	}
}

/*int eAuxiliar_ContarPorLocalidad(ePedido listaPedido[], int tamPedido, eAuxiliar listaAux[], int idBuscar, char localidad[], int index, , eLocalidad listaLocalidad[], int tamLocalidad, int idBuscar2)
{
	int retorno = 0;
	for(int i = 0; i<tamPedido; i++)
	{
		for(int j = 0; j<tamLocalidad; j++)
		{
			if(listaPedido[i].estado == PENDIENTE && listaPedido[i].idCliente == idBuscar && listaLocalidad[j].idLocalidad == idBuscar2)
			{
				listaAux[index].contador++;
				listaAux[index].isEmpty = LLENO;
				retorno = 1;
			}
		}
	}
	return retorno;
}*/

/*void eCliente_MostrarUnaCantidadPorLocalidad(char localidad[], eAuxiliar unAux)
{
	printf("Cantidad de pedidos en %s: %d\n", localidad, unAux.contador);
}

int ePedido_MostrarPendientesPorLocalidad(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = -1;
	int  localidad;
	eAuxiliar listaAux[tamLocalidad];
	if(listaPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		eAuxiliar_InicializarPorCliente(listaCliente, tamCliente, listaAux);
		//utn_getTexto(localidad, "Ingrese localidad: ", "(!)Localidad invalida. ", sizeof(localidad));
		eLocalidad_MostrarListaNumerada(listaLocalidad, tamLocalidad);
		localidad = eLocalidad_ObterIdDelIndex(listaLocalidad, tamLocalidad);
		acomodarTexto(localidad);
		for(int i = 0; i<tamCliente; i++)
		{
			if(listaCliente[i].isEmpty == LLENO && listaCliente[i].idLocalidad ==  localidad)
			{
				if(eAuxiliar_ContarPorLocalidad(listaPedido, tamPedido, listaAux, listaAux[i].id, localidad, i, listaLocalidad, tamLocalidad, listaCliente[i].idLocalidad) == 1)
				{
					eCliente_MostrarUnaCantidadPorLocalidad(localidad, listaAux[i]);
					retorno = 1;
				}

			}
		}
	}
	return retorno;
}*/



int ePedido_ContarAcumularPP(ePedido listaPedido[], eAuxiliar listaAux[], int tamPedido, int idBuscar, int index)
{
	int retorno = 0;
	for(int i = 0; i < tamPedido; i++)
	{
		if(listaPedido[i].estado == COMPLETADO && listaPedido[i].idCliente == idBuscar)
		{
			listaAux[index].contador++;
			listaAux[index].acumulador += listaPedido[i].kilosTipos.kilosPP;
			listaAux[index].isEmpty = LLENO;
			retorno = 1;
		}
	}
	return retorno;
}

float ePedido_AcumularKilosPP(ePedido listaPedido[], int tamPedido)
{
	float acumulador = 0;
	for(int i = 0; i<tamPedido; i++)
	{
		if(listaPedido[i].estado == COMPLETADO)
		{
			acumulador += listaPedido[i].kilosTipos.kilosPP;
		}
	}
	return acumulador;
}

int ePedido_CalcularPromedio(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente)
{
	int retorno = -1;
	float kilosTotalesPP;
	int cantidadClientes;
	float promedio;

	if(listaPedido != NULL && tamPedido > 0 && listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		cantidadClientes = eCliente_ContarCargados(listaCliente, tamCliente);
		kilosTotalesPP = ePedido_AcumularKilosPP(listaPedido, tamPedido);
		if(cantidadClientes > 0)
		{
			retorno = 1;
			promedio = kilosTotalesPP / cantidadClientes;
			printf("El promedio es: %.2f\n", promedio);
		}
	}
	return retorno;
}

void ePedido_TituloPromedioPorClientePP(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int j;
	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			j = ePedido_BuscarPorIdCliente(listaPedido, tamPedido, listaCliente[i].idCliente, COMPLETADO);
			if(j != -1)
			{
				printf("%30s %15s\n", "CLIENTE", "PROMEDIO DE PP");
				break;
			}
		}
	}
}

int eCliente_BuscarMayorPorTipo(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, int estado)
{
	int retorno = 0;
	eAuxiliar listaAux[tamCliente];
	int bandera = 0;
	int mayor = INT_MAX;

	eAuxiliar_InicializarPorCliente(listaCliente, tamCliente, listaAux);

	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			eAuxiliar_ContarPedidosPorCliente(listaPedido, tamPedido, listaAux, listaCliente[i].idCliente, i, PENDIENTE);
			if(bandera == 0 || listaAux[i].contador > mayor)
			{
				mayor = listaAux[i].contador;
				bandera = 1;
				retorno = 1;
			}
		}
		if(mayor == listaAux[i].contador && listaCliente[i].isEmpty == LLENO)
		{
			printf("%s   ", listaCliente[i].nombreEmpresa);
		}
	}

	return retorno;
}

int eCliente_BuscarMayorPorTipoDistinto(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, int estado)
{
	int retorno = 0;
	eAuxiliar listaAux[tamCliente];
	int bandera = 0;
	int mayor = INT_MAX;

	eAuxiliar_InicializarPorCliente(listaCliente, tamCliente, listaAux);

	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			eAuxiliar_ContarPedidosDistintoPorCliente(listaPedido, tamPedido, listaAux, listaCliente[i].idCliente, i, VACIO_PEDIDO);
			if(bandera == 0 || listaAux[i].contador > mayor)
			{
				mayor = listaAux[i].contador;
				bandera = 1;
				retorno = 1;
			}
		}
		if(mayor == listaAux[i].contador && listaCliente[i].isEmpty == LLENO)
		{
			printf("%s   ", listaCliente[i].nombreEmpresa);
		}
	}

	return retorno;
}



int eCliente_PedirIdParaAccion(eCliente listaCliente[], int tamCliente, char msjAccion[], eLocalidad listaLocaldiad[], int tamLocalidad)
{
	int id;
	int index;
	utn_getEntero(&id, msjAccion, "(!)Id invalido. ", 1, INT_MAX);
	index = eCliente_BuscarPorID(listaCliente, tamCliente, id);
	while(index == -1)
	{
		eCliente_Listado(listaCliente, tamCliente, listaLocaldiad, tamLocalidad);
		utn_getEntero(&id, "Id no encontrado, reingrese: ", "(!)Id invalido. ", 1, INT_MAX);
		index = eCliente_BuscarPorID(listaCliente, tamCliente, id);
	}
	return index;
}


eCliente eCliente_CargarUno(eLocalidad listaLocalidad[], int tamLocalidad)
{
	eCliente auxCliente;
	utn_getTexto(auxCliente.nombreEmpresa, "Ingrese el nombre de la empresa del cliente: ",
				 "(!)Nombre invalido. ", sizeof(auxCliente.nombreEmpresa));
	utn_getCuit(auxCliente.cuit, "Ingrese cuit (con guiones): ", "(!)Cuit invalido. ", sizeof(auxCliente.cuit));
	utn_getTexto(auxCliente.direccion, "Ingrese direccion del cliente: ",
			     "(!)Direccion invalida. ", sizeof(auxCliente.direccion));
	auxCliente.idLocalidad =  eLocalidad_ObterIdDelIndex(listaLocalidad, tamLocalidad);
	printf("  ID LOCA: %d   ", auxCliente.idLocalidad);
	return auxCliente;
}


int eCliente_Alta(eCliente miCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad)
{

	int retorno = -1;
	int i;

	eCliente auxCliente;

	if(miCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		i =  eCliente_BuscarLibre(miCliente, tamCliente);
		if(i != -1)
		{
			retorno = -2;
			auxCliente = eCliente_CargarUno(listaLocalidad, tamLocalidad);
			if(utn_getRespuestaSiNo("Desea dar de alta?") == 1)
			{
				miCliente[i] = auxCliente;
				miCliente[i].idCliente = *id;
				*id = *id + 1;
				miCliente[i].isEmpty = LLENO;
				retorno = 1;

			}
		}
	}
	return retorno;
}


eCliente eCliente_ModificarUno(eCliente unCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	eCliente auxiliar = unCliente;
	int opcion;
	do
	{
		printf("\n\tMENU MODIFICAR\n 0. Salir del menu\n 1. Direccion\n 2. Localidad\n");
		utn_getEntero(&opcion, "Ingrese una opcion: ",
				"(!)Opcion invalida. ", 0, 2);
		switch(opcion)
		{
		case 0:
		if(utn_getRespuestaSiNo("Desea salir del menu modificar?")==1)
		{
			opcion = -1;
		}
		break;
		case 1:
			utn_getTexto(auxiliar.direccion, "Ingrese la direccion del cliente a modificar: ",
						"(!)Direccion invalida. ", sizeof(auxiliar.direccion));
		break;
		case 2:
			eLocalidad_MostrarListaNumerada(listaLocalidad, tamLocalidad);
			auxiliar.idLocalidad =  eLocalidad_ObterIdDelIndex(listaLocalidad, tamLocalidad);
			/*utn_getTexto(auxiliar.localidad, "Ingrese la localidad del cliente a modificar: ",
						"(!)Localidad invalida. ", sizeof(auxiliar.localidad));*/
		break;
		}
	}while(opcion != -1);
	return auxiliar;
}

int eCliente_Modificacion(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{

	int retorno = -1;
	int i;
	int banderaCargado = 0;
	int j;
	eCliente auxCliente;


	if(listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		if(eCliente_Listado(listaCliente, tamCliente, listaLocalidad, tamLocalidad) == 1)
		{
			banderaCargado = 1;
		}
		if(banderaCargado == 1)
		{
			retorno = -2;
			i = eCliente_PedirIdParaAccion(listaCliente, tamCliente, "Ingrese id del cliente a modificar: ", listaLocalidad, tamLocalidad);
			j = eLocalidad_BuscarPorID(listaLocalidad, tamLocalidad, listaCliente[i].idLocalidad);
			auxCliente = eCliente_ModificarUno(listaCliente[i], listaLocalidad, tamLocalidad);

			eCliente_Titulo(listaCliente, tamCliente);
			eCliente_MostrarUno(auxCliente, listaLocalidad[j]);

			if(utn_getRespuestaSiNo("Confirmar modificacion de este cliente.") == 1)
			{
				listaCliente[i] = auxCliente;
				retorno = 1;
			}

		}
	}
	return retorno;
}



int eCliente_Baja(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = -1;
	int i;
	int banderaCargado = 0;
	int j;
	if(listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		if(eCliente_Listado(listaCliente, tamCliente, listaLocalidad, tamLocalidad) == 1)
		{
			banderaCargado = 1;
		}
		if(banderaCargado == 1)
		{
			i = eCliente_PedirIdParaAccion(listaCliente, tamCliente, "Ingrese id del cliente a dar de baja: ", listaLocalidad, tamLocalidad);
			if(i != -1)
			{
				retorno = -2;
				eCliente_Titulo(listaCliente, tamCliente);
				j = eLocalidad_BuscarPorID(listaLocalidad, tamLocalidad, listaCliente[i].idCliente);
				eCliente_MostrarUno(listaCliente[i], listaLocalidad[j]);
				if(utn_getRespuestaSiNo("Esta seguro de dar de baja este cliente? Se eliminaran todos sus datos y su pedidos.") == 1)
				{
					listaCliente[i].isEmpty = VACIO_CLIENTE;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}




void eCliente_MostrarUno(eCliente unCliente, eLocalidad unaLocalida)
{
	printf("%30s %15s %30s %30s %5d\n", unCliente.nombreEmpresa, unCliente.cuit,
			unCliente.direccion, unaLocalida.descripcion, unCliente.idCliente);
}
int eCliente_Listado(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = -1;
	int j;
	if(listaCliente != NULL && tamCliente > 0)
	{
		retorno = 0;
		eCliente_Titulo(listaCliente, tamCliente);
		for(int i = 0; i<tamCliente; i++)
		{
			if(listaCliente[i].isEmpty == LLENO)
			{
				j = eLocalidad_BuscarPorID(listaLocalidad, tamLocalidad, listaCliente[i].idLocalidad);
				if(j != -1)
				{
					eCliente_MostrarUno(listaCliente[i], listaLocalidad[j]);
				}
				retorno = 1;
			}
		}
	}
	return retorno;
}


void eCliente_Titulo(eCliente listaCliente[], int tamCliente)
{
	for(int i = 0; i<tamCliente; i++)
	{
		if(listaCliente[i].isEmpty == LLENO)
		{
			printf("%30s %15s %30s %30s %5s\n","EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD", "ID");
			break;
		}
	}
}
