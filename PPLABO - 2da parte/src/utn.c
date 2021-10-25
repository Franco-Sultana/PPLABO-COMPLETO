 /* input.c
 *
 *  Created on: 18 abr. 2021
 *      Author: F2019
 */

#include "utn.h"

int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char buffer[TAM_BUFFER];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			if(buffer[strnlen(buffer,sizeof(buffer)) - 1] == '\n')
			{
				buffer[strnlen(buffer,sizeof(buffer)) - 1] = '\0';
			}
			if(strnlen(buffer ,sizeof(buffer)) <= longitud)
			{
				strncpy(cadena, buffer, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/*
 ============================================================================
								   ENTEROS
 ============================================================================
*/
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[TAM_BUFFER];

	if(pResultado != NULL &&
			myGets(buffer, sizeof(buffer)) == 0 &&
			esNumerica(buffer, sizeof(buffer)) == 1)
	{
			retorno = 0;
			*pResultado = atoi(buffer);
	}
	return retorno;
}
int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] != '\0'; i++)
	{
		if(i == 0 && cadena[i] == '-')
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
//*************************** CON REINTENTOS ***************************//
int utn_getEnteroConReintentos(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&numero) == 0 && numero >= minimo && numero <= maximo)
			{
				*pResultado = numero;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
//*************************** SIN  REINTENTOS ***************************//
int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int bandera = 0;
	int retorno = -1;
	int numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&numero) == 0 && numero >= minimo && numero <= maximo)
			{
				*pResultado = numero;
				retorno = 0;
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}
/*
 ============================================================================
								  FLOTANTES
 ============================================================================
*/
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[TAM_BUFFER];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumeroConDecimal(buffer, sizeof(buffer)) == 1)
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}
int esNumeroConDecimal(char* cadena, int limite)
{
	int retorno = 1;
	int i = 0;
	int contador = 0;

	for(i = 0; i<limite && cadena[i] != '\0'; i++)
	{
		if(i == 0 && cadena[i] == '-')
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			if(cadena[i] == '.' && contador == 0)
			{
				contador++;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//***************************** CON REINTENTOS *****************************//
int utn_getFlotanteReintentos(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float numeroConDecimal;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&numeroConDecimal) == 0 && numeroConDecimal >= minimo && numeroConDecimal <= maximo)
			{
				*pResultado = numeroConDecimal;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
//************************** SIN REINTENTOS  ***************************//
int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int bandera = 0;
	int retorno = -1;
	float numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&numero) == 0 && numero >= minimo && numero <= maximo)
			{
				*pResultado = numero;
				retorno = 0;
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}
/*
 ============================================================================
						 OTRAS FUNCIONES CON NUMEROS
 ============================================================================
*/
//************************ FECHA ************************//
int utn_getFecha(int* pResultadoMes, int* pResultadoDia, int* pResultadoAnio, char* mensajeError, int anioMin, int aniMax)
{
	int retorno = -1;
	int mes;
	int dia;
	int anio;
	char mensajeDia[] = "Ingrese el dia: ";

	if(pResultadoMes != NULL && pResultadoDia != NULL && pResultadoAnio != NULL)
	{
		utn_getEntero(&mes, "Ingrese el mes", "Error. ", 1, 12);
		*pResultadoMes = mes;
		switch(mes)
		{
			case 4:
			case 6:
			case 9:
			case 11:
				utn_getEntero(&dia, mensajeDia, "Error, este mes tiene 30 dias. ", 1, 30);
			break;
			case 2:
				utn_getEntero(&dia, mensajeDia, "Error, este mes tiene 28 dias. ", 1, 28);
			break;
			default:
				utn_getEntero(&dia, mensajeDia, "Error, este mes tiene 31 dias. ", 1, 31);
			break;
		}
		*pResultadoDia = dia;

		utn_getEntero(&anio, "Ingrese el año: ", "Error. ", anioMin, aniMax);
		*pResultadoAnio = anio;
		retorno = 1;
	}
	return retorno;
}


//************************* DNI *************************//

/*
 ============================================================================
						 	 	 CARACTERES
 ============================================================================
*/
int getChar(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && longitud > 0
			&& myGets(&buffer, sizeof(buffer)) == 0
			&& esCaracter(&buffer, sizeof(buffer)) == 1 &&
			strnlen(&buffer, sizeof(buffer)) == longitud)
	{
		strncpy(pResultado, &buffer, longitud);
		retorno = 0;
	}
	return retorno;
}
int esCaracter(char* caracter, int limite)
{
	int retorno = 1;
	int i;

	if(caracter != NULL && limite >0)
	{
		for(i=0; i<limite; i++)
		{
			if((caracter[i] < 'A' || caracter[i] > 'Z') && (caracter[i] < 'a' || caracter[i] > 'z')
					&& caracter[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//********************* CUALQUIER CARACTERES *********************//
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError)
{
	int bandera = 0;
	char buffer;
	int retorno;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			if(getChar(&buffer, sizeof(buffer)) == 0)
			{
				strcpy(pResultado, &buffer);
				retorno = 1;
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}
//********************* RESPUESTA "SI" "NO" *********************//
int utn_getRespuestaSiNo(char* mensaje)
{
	int retorno = -1;
	char buffer;

	if(mensaje != NULL)
	{
		do
		{
			printf("%s Ingrese 's'(SI) o 'n'(NO): ", mensaje);
			if((getChar(&buffer, sizeof(buffer)) == 0)
					&& (buffer == 's' ||buffer == 'S'))
			{
				retorno = 1;
				break;
			}
			if(buffer == 'N' || buffer == 'n')
			{
				retorno = 0;
				break;
			}

			printf("(!)Opción inválida. ");
		}while(buffer != 's' || buffer != 'n' || buffer != 'S' || buffer != 'N');

	}
	return retorno;
}
/*
 ============================================================================
						 	 CADENA DE CARACTERES
 ============================================================================
*/
//************************* NOMBRES *************************//
int getNombre(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[TAM_BUFFER];

	if(pResultado != NULL && longitud > 0
			&& myGets(buffer, sizeof(buffer)) == 0
			&& esUnNombre(buffer, sizeof(buffer)) == 1 &&
			strnlen(buffer,sizeof(buffer)) < longitud)
	{
		strncpy(pResultado, buffer, longitud);
		retorno = 0;
	}
	return retorno;
}
int esUnNombre(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	if(cadena != NULL && limite >0)
	{
		for(i=0; i<limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z')
					&& cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int longitud)
{
	int bandera = 0;
	char buffer[TAM_BUFFER];
	int retorno;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			if(getNombre(buffer, sizeof(buffer)) == 0 && strnlen(buffer,sizeof(buffer)) < longitud)
			{
				strncpy(pResultado, buffer,  longitud);
				retorno = 1;
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}
//************************** TEXTO **************************//
int getTexto(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[TAM_BUFFER];

	if(pResultado != NULL && longitud > 0
			&& myGets(buffer, sizeof(buffer)) == 0
			&& esTexto(buffer, sizeof(buffer)) == 1 &&
			strnlen(buffer,sizeof(buffer))<longitud)
	{
		strncpy(pResultado, buffer, longitud);
		retorno = 0;
	}
	return retorno;
}
int esTexto(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	if(cadena != NULL && limite >0)
	{
		for(i=0; i<limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z')
					&& cadena[i] != ' ' && cadena[i] != '.' && cadena[i] !=  '-' &&
					(cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getTexto(char* pResultado, char* mensaje, char* mensajeError, int longitud)
{
	int bandera = 0;
	char buffer[TAM_BUFFER];
	int retorno;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			if(getTexto(buffer, sizeof(buffer)) == 0 && strnlen(buffer,sizeof(buffer)) < longitud)
			{
				strncpy(pResultado, buffer, longitud);
				retorno = 1;
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}

/*
 ============================================================================
						 	 	   CUIT
 ============================================================================
*/

int esCuit(char* cadena, int longitud)
{
	int retorno = 1;
	for(int i = 0; i<strlen(cadena); i++)
	{
		if((i==2 && cadena[i] == '-') || (i==11 && cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
int getCuit(char* cuit, int longitud)
{
	int retorno = 0;
	char buffer[TAM_BUFFER];
	if(myGets(buffer, sizeof(buffer)) == 0 && esCuit(buffer, sizeof(buffer)) == 1 &&
			strlen(buffer) < longitud)
	{
		strcpy(cuit, buffer);
		retorno = 1;
	}
	return retorno;
}

int utn_getCuit(char* cuit, char* mensaje, char* mensajeError, int longitud)
{
	int retorno = 0;
	int bandera = 0;
	char buffer[TAM_BUFFER];
	if(cuit != NULL && mensaje != NULL && mensajeError != NULL && longitud > 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getCuit(buffer, sizeof(buffer)) && strlen(buffer) == longitud)
			{
				retorno = 1;
				strcpy(cuit, buffer);
				break;
			}
			bandera++;
			printf("%s", mensajeError);
		}while(bandera != 0);
	}
	return retorno;
}
