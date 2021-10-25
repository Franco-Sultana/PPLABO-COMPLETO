/*
 * Nexo.h
 *
 *  Created on: 9 oct. 2021
 *      Author: F2019
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "eCliente.h"
#include "ePedido.h"
#include "eLocalidad.h"

typedef struct
{
	int id;
	int contador;
	float acumulador;
	float promedio;
	int isEmpty;
}eAuxiliar;


/**
 * @fn ePedido ePedido_CargarUno(ePedido[], int, eCliente[], int)
 * @brief Carga un dato de tipo pedido con datos que se le piden al usuario
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedido
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array cliente
 * @return auxiliar de pedido con todos los datos cargados pedidos al usuario
 */
ePedido ePedido_CargarUno(ePedido listaPedido[], int tamPedido,eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int ePedido_CrearPedido(ePedido[], int, eCliente[], int, int*)
 * @brief Crea un nuevo pedido
 * @param miPedido array de pedido
 * @param tam tamaño del array pedido
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @param id puntero a direccion de memoria del id autoincremental de pedido
 * @return -1: si alguno de los parametros recibido vino erroneo | 0: si no hay mas espacio | -2 si el usuario cancela la creacion |
 * 			1 si se pudo crear el pedido
 */
int ePedido_CrearPedido(ePedido miPedido[], int tam, eCliente listaCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad);


/**
 * @fn void ePedido_TituloPendientesConCliente(ePedido[], int)
 * @brief encabezazdo para lista de pendientes con datos des cliente
 * @param listaPedido array de pedido
 * @param tamPedido tamaño del array pedido
 */
void ePedido_TituloPendientesConCliente(ePedido listaPedido[], int tamPedido); ////////////////

/**
 * @fn void ePedido_MostrarUnoPendienteConCliente(ePedido, eCliente)
 * @brief muestra un pedido en estado PENDIENTE con datos de su cliente
 * @param unPedido un pedido
 * @param unCliente un cliente
 */
void ePedido_MostrarUnoPendienteConCliente(ePedido unPedido, eCliente unCliente);

/**
 * @fn int ePedido_ListadoPendientesConCliente(ePedido[], int, eCliente[], int)
 * @brief Lista los pedidos en estado PENDIENTE con datos de su cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 * @return -1 si alguno de los datos vino erroneo | 0 si no hay pedidos pendientes | 1 si pudo mostrar
 */
int ePedido_ListadoPendientesConCliente(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);


/**
 * @fn void eCliente_TituloCantidadPendientes(eCliente[], int, ePedido[], int)
 * @brief encabezado para listar clientes con cantidad de pedidos pendientes
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del aray cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 */
void eCliente_TituloCantidadPendientes(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);

/**
 * @fn void eCliente_MostrarUnoConCantidadPendientes(eCliente, eAuxiliar)
 * @brief muestra un cliente con la cantidad de pedidos en estado PENDIENTE
 * @param unCliente
 * @param auxiliar
 */
void eCliente_MostrarUnoConCantidadPendientes(eCliente unCliente, eAuxiliar auxiliar, eLocalidad unaLocalidad);

/**
 * @fn int eCliente_ListadoPendientes(ePedido[], int, eCliente[], int)
 * @brief lista los clientes junto con la cantidad de pedidos en estado PENDIENTE
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del arrray clientes
 * @return -1 si uno de los datos vino erroneo | 0 si no hay clientes con pedidos pendientes | 1 si pudo mostrar
 */
int eCliente_ListadoPendientes(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);



/**
 * @fn void eAuxiliar_InicializarPorCliente(eCliente[], int, eAuxiliar[])
 * @brief Inicializa la estructura auxiliar
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 * @param auxiliar array de auxiliar
 */
void eAuxiliar_InicializarPorCliente(eCliente listaCliente[], int tamCliente, eAuxiliar auxiliar[]);

/**
 * @fn int eAuxiliar_ContarPedidosPorCliente(ePedido[], int, eAuxiliar[], int, int)
 * @brief cuenta cuantos pedidos en estado PENDIENTE tiene cada cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedido
 * @param auxiliar array de auxiliar
 * @param idBuscar id a buscar para comparar
 * @param index indice del auxiliar (mismo que el de cliente)
 * @return 0: si no hay pedidos en estado PENDIENTE | 1 si pudo contar
 */
int eAuxiliar_ContarPedidosPorCliente(ePedido listaPedido[], int tamPedido, eAuxiliar auxiliar[], int idBuscar, int index, int estado);

/**
 * @fn int ePedido_BuscarPorIdCliente(ePedido[], int, int, int)
 * @brief busca por id de cliente un pedido con un estado que se le pasa por parametro
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param idBuscar id a buscar
 * @param estado estado del pedido a buscar
 * @return -1: si no encontro el id | la posicion del pedido que tiene el mismo id que se le paso por parametro
 */
int ePedido_BuscarPorIdCliente(ePedido listaPedido[], int tamPedido, int idBuscar, int estado);

/**
 * @fn int ePedido_MostrarProcesados(ePedido[], int, eCliente[], int)
 * @brief lista los pedidos que esten en estado COMPLETADO
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 * @return -1 si algun dato vino erroneo | 0 si no hay pedidos COMPLETADOS | 1 si pudo mostrar
 */
int ePedido_MostrarProcesados(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);

/**
 * @fn void eCliente_MostrarUnClientePedidoCompletado(eCliente, ePedido)
 * @brief Muestra un los pedidos en estado COMPLETADO y todos los datos del cliente
 * @param unCliente un cliente
 * @param unPedido un pedido
 */
void eCliente_MostrarUnClientePedidoCompletado(eCliente unCliente, ePedido unPedido);


/**
 * @fn void eAuxiliar_InicializarPorPedido(ePedido[], eAuxiliar[], int)
 * @brief Inicializa el array de auxiliar por pedidos
 * @param listaPedido array de pedidos
 * @param listaAux array de auxiliar
 * @param tamAux tamaño de auxiiar (mismo que el de pedidos)
 */
void eAuxiliar_InicializarPorPedido(ePedido listaPedido[],eAuxiliar listaAux[], int tamAux);

/**
 * @fn int eAuxiliar_ContarPorLocalidad(ePedido[], int, eAuxiliar[], int, char[], int)
 * @brief cuenta por localidad
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaAux array de auxiliar
 * @param idBuscar id a buscar
 * @param localidad localidad que ingreso el usuario
 * @param index indice de auxiliar, que es el mismo que el de cliente
 * @return 0: si no pudo contar | 1: si pudo contar
 */
int eAuxiliar_ContarPorLocalidad(ePedido listaPedido[], int tamPedido, eAuxiliar listaAux[], int idBuscar, char localidad[], int index);

/**
 * @fn int ePedido_MostrarPendientesPorLocalidad(ePedido[], int, eCliente[], int)
 * @brief muestra cuantos pedido hay en una localidad
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array de clientes
 * @return -1 si alguno de los paramtros vino erroneo | 0: si no hay pedidos pendientes en la localidad | 1: si pudo mostrar
 */
int ePedido_MostrarPendientesPorLocalidad(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn void eCliente_MostrarUnaCantidadPorLocalidad(char[], eAuxiliar)
 * @brief muestra una localidad con la cantidad de pedidos en estado PENDIENTE
 * @param localidad localidad que ingresó el usuario
 * @param unAux un dato del tipo auxiliar
 */
void eCliente_MostrarUnaCantidadPorLocalidad(char localidad[], eAuxiliar unAux);


/**
 * @fn int ePedido_ContarAcumularPP(ePedido[], eAuxiliar[], int, int, int)
 * @brief cuenta y acumula los residuos del tipo PP cuando encuentra un pedido en estado COMPLETADO
 *
 * @param listaPedido array de pedidos
 * @param listaAux array de auxilair
 * @param tamPedido tamaño del array pedidos
 * @param idBuscar id a buscar
 * @param index indice del array auxiliar (mismo que el de cliente)
 * @return 0: si no hay pedidos en estado COMPLETADO o si no encontro el id | 1: si pudo contar y acumular
 */
int ePedido_ContarAcumularPP(ePedido listaPedido[], eAuxiliar listaAux[], int tamPedido, int idBuscar, int index);

/**
 * @fn int ePedido_CalcularPromedio(ePedido[], int, eCliente[], int)
 * @brief calcula y muestra el promedio de peso de residuos PP por cliente
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 * @param listaCliente array clientes
 * @param tamCliente tamaño del array clientes
 * @return -1: si alguno de los datos vino erroneo | 0: si no hay clientes cargados o pedidos en estado COMPLETADO |
 * 			 1: si pudo calcular
 */
int ePedido_CalcularPromedio(ePedido listaPedido[], int tamPedido, eCliente listaCliente[], int tamCliente);


/**
 * @fn void ePedido_TituloPromedioPorClientePP(eCliente[], int, ePedido[], int)
 * @brief encabezado para la lista de promedios de PP por cliente
 * @param listaCliente array de clientes
 * @param tamCliente tamaño del array clientes
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedidos
 */
void ePedido_TituloPromedioPorClientePP(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido);

/**
 * @fn float ePedido_AcumularKilosPP(ePedido[], int)
 * @brief acumula y retorna el peso total de PP
 * @param listaPedido array de pedidos
 * @param tamPedido tamaño del array pedido
 * @return el acumulador con el total de peso
 */
float ePedido_AcumularKilosPP(ePedido listaPedido[], int tamPedido);


/**
 * @fn eCliente eCliente_CargarUno()
 * @brief Carga en un auxiliar de cliente todos los datos ingresados por el usuario
 * @return el auxiliar de cliente con datos cargados
 */
eCliente eCliente_CargarUno(eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eCliente_Alta(eCliente[], int, int*)
 * @brief Da de alta un cliente
 * @param miCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @param id puntero a direccion de memoria del id autoincremental de cliente
 * @return -1: si alguno de los parametros recibido vino erroneo | 0: si no hay mas espacio | -2 si el usuario cancela el alta |
 * 			1 si se pudo dar de alta
 */
int eCliente_Alta(eCliente miCliente[], int tamCliente, int* id, eLocalidad listaLocalidad[], int tamLocalidad);


/**
 * @fn int eCliente_PedirIdParaAccion(eCliente[], int, char[])
 * @brief Pide el id para hacer una accion (como dar de baja o modificar)
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @param msjAccion mensaje que se le mostrara al usuario, pidiendo para qué debe ingresar un id
 * @return indice del cliente que tenga el mismo id que ingreso el usuario
 */
int eCliente_PedirIdParaAccion(eCliente listaCliente[], int tamCliente, char msjAccion[], eLocalidad listaLocaldiad[], int tamLocalidad);

/**
 * @fn eCliente eCliente_ModificarUno(eCliente)
 * @brief muestra a usuario un menu para que elija que quiere modificar y lo guarda en un auxiliar de cliente
 * @param unCliente un cliente
 * @return auxiliar de cliente con los datos modificados
 */
eCliente eCliente_ModificarUno(eCliente unCliente, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn int eCliente_Modificacion(eCliente[], int)
 * @brief pide al usuario un id para modificar un cliente
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @return -1: si alguno de los parametros recibido vino erroneo | 0: si no hay clientes cargados |
 * 			-2 si el usuario cancela la modificacion | 1 si se pudo modificar
 */
int eCliente_Modificacion(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);


/**
 * @fn int eCliente_Baja(eCliente[], int)
 * @brief pide al usuario un id para dar de baja un cliente
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @return -1: si alguno de los parametros recibido vino erroneo | 0: si no hay clientes cargados |
 * 			-2 si el usuario cancela la baja | 1 si se pudo dar de baja
 */
int eCliente_Baja(eCliente listaCliente[], int tamCliente, eLocalidad listaLocalidad[], int tamLocalidad);

/**
 * @fn void eCliente_MostrarUno(eCliente)
 * @brief Muestra un cliente al usuario
 * @param unCliente cliente a mostrar
 */
void eCliente_MostrarUno(eCliente unCliente, eLocalidad unaLocalida);

/**
 * @fn int eCliente_Listado(eCliente[], int)
 * @brief lista los clientes dados de alta
 * @param listaCliente array de cliente
 * @param tamCliente tamaño del array cliente
 * @return -1 si alguno de los parametros rebido vino erroneo | 0: si no hay clientes cargados | 1 si pudo mostrar
 */
int eCliente_Listado(eCliente listaCliente[], int tamCliente , eLocalidad listaLocalidad[], int tamLocalidad);//


int eAuxiliar_ContarPedidosDistintoPorCliente(ePedido listaPedido[], int tamPedido, eAuxiliar auxiliar[], int idBuscar, int index, int estado);
int eCliente_BuscarMayorPorTipoDistinto(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, int estado);
int eCliente_BuscarMayorPorTipo(eCliente listaCliente[], int tamCliente, ePedido listaPedido[], int tamPedido, int estado);
#endif /* NEXO_H_ */
