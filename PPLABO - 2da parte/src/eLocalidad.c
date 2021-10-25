/*
 * eLocalidad.c
 *
 *  Created on: 25 oct. 2021
 *      Author: F2019
 */


/*
 * eLocalidad.c
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#include "eLocalidad.h"
int eLocalidad_BuscarPorID(eLocalidad listaLocalidad[], int tamLocalidad, int idBuscar)
{
	int index = -1;
	int i;
	for(i = 0; i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].isEmpty == LLENO && listaLocalidad[i].idLocalidad == idBuscar)
		{
			index = i;
		}
	}
	return index;
}

int eLocalidad_RetornarIdPorIndice(eLocalidad listaLocalidad[], int indice, int tamLocalidad)
{
	int id = -1;
	int i;
	i = eLocalidad_BuscarPorID(listaLocalidad, tamLocalidad, listaLocalidad[indice].idLocalidad);
	if(i != -1)
	{
		id = listaLocalidad[i].idLocalidad;
	}
	return id;
}



int eLocalidad_ContarCargados(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int contador = 0;
	for(int i = 0; i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].isEmpty == LLENO)
		{
			contador++;
		}
	}
	return contador;
}

int eLocalidad_ObterIdDelIndex(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int indiceLocalidad;
	int max;
	max = eLocalidad_ContarCargados(listaLocalidad, tamLocalidad);
	eLocalidad_MostrarListaNumerada(listaLocalidad, tamLocalidad);
	utn_getEntero(&indiceLocalidad, "Ingrese Localidad: ","(!)Opcion invalida. ", 1, INT_MAX);
	while(indiceLocalidad < 1 || indiceLocalidad > max)
	{
		eLocalidad_MostrarListaNumerada(listaLocalidad, tamLocalidad);
		utn_getEntero(&indiceLocalidad, "Fuera de rango, reingrese: ","(!)Opcion invalida. ", 1, INT_MAX);
	}
	return listaLocalidad[indiceLocalidad-1].idLocalidad;
}

int eLocalidad_ReordenarArray(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = 0;
	eLocalidad auxiliar;
	for(int i = 0;i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].isEmpty == VACIO)
		{
			for(int j = i+1; j<tamLocalidad; j++)
			{
				auxiliar = listaLocalidad[i];
				listaLocalidad[i] = listaLocalidad[j];
				listaLocalidad[j] = auxiliar;
				retorno = 1;
			}
		}
	}
	return retorno;
}


//////////////////////////

int eLocalidad_Harcodear(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = 0;
	if(listaLocalidad != NULL && tamLocalidad > 0)
	{
		strcpy(listaLocalidad[0].descripcion, "Wilde");
		listaLocalidad[0].idLocalidad = 1;
		listaLocalidad[0].isEmpty = LLENO;

		strcpy(listaLocalidad[1].descripcion, "Avellaneda");
		listaLocalidad[1].idLocalidad = 2;
		listaLocalidad[1].isEmpty = LLENO;

		strcpy(listaLocalidad[2].descripcion, "Villa Dominico");
		listaLocalidad[2].idLocalidad = 3;
		listaLocalidad[2].isEmpty = LLENO;

		strcpy(listaLocalidad[3].descripcion, "Quilmes");
		listaLocalidad[3].idLocalidad = 4;
		listaLocalidad[3].isEmpty = LLENO;

		strcpy(listaLocalidad[4].descripcion, "CABA");
		listaLocalidad[4].idLocalidad = 5;
		listaLocalidad[4].isEmpty = LLENO;
	}
	return retorno;
}

int eLocalidad_BuscarLibre(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int index = -1;
	int i;
	for(i = 0; i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}


void eLocalidad_MostrarUno(eLocalidad unLocalidad)
{
	printf(" \n");
}
int eLocalidad_Listado(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = 0;
	if(listaLocalidad != NULL && tamLocalidad > 0)
	{
		retorno = -1;
		eLocalidad_Titulo(listaLocalidad, tamLocalidad, "DESCRIPCION", "ID");
		for(int i = 0; i<tamLocalidad; i++)
		{
			if(listaLocalidad[i].isEmpty == LLENO)
			{
				printf(" %d\n", listaLocalidad[i].idLocalidad);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int eLocalidad_MostrarListaNumerada(eLocalidad listaLocalidad[], int tamLocalidad)
{
	int retorno = 0;
	if(listaLocalidad != NULL && tamLocalidad > 0/* && eLocalidad_ReordenarArray(listaLocalidad, tamLocalidad) == 1*/)
	{
		retorno = -1;
		for(int i = 0; i<tamLocalidad; i++)
		{
			if(listaLocalidad[i].isEmpty == LLENO)
			{
				printf(" %d. %s\n", i+1, listaLocalidad[i].descripcion);
				retorno = 1;
			}
		}
	}
	return retorno;
}

void eLocalidad_Titulo(eLocalidad listaLocalidad[], int tamLocalidad, char msj1[], char msj2[])
{
	int banderaCargados = 0;
	for(int i = 0; i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].isEmpty == LLENO)
		{
			banderaCargados = 1;
		}
	}
	if(banderaCargados == 1)
	{
		printf("\n \n");
	}
}

void Info_ListarLocalidad(eLocalidad listaLocalidad[], int tamLocalidad)
{
	switch(eLocalidad_Listado(listaLocalidad, tamLocalidad))
	{
	case 0:
		printf("(!!)Ocurrio un error inesperado\n");
	break;
	case -1:
		printf("Aun no hay Localidad cargado\n");
	break;
	}
}
