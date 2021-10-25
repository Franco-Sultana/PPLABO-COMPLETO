/*
 ============================================================================
	Franco Sultana		Div: "C"
 ============================================================================
 */

#include "Informes.h"


int main(void)
{
	setbuf(stdout, NULL);
	int eCliente_idAutoincremental = 1;
	eCliente listaCliente[TAM_CLIENTE];
	int opcionCliente;
	ePedido listaPedido[TAM_PEDIDO];
	int ePedido_idAutoincremental = 1;

	eLocalidad listaLocalidad[TAM_LOCALIDAD];

	eCliente_InicializarIsEmpty(listaCliente, TAM_CLIENTE);
	ePedido_InicializarIsEmpty(listaPedido, TAM_PEDIDO);
	eLocalidad_Harcodear(listaLocalidad, TAM_LOCALIDAD);
	do
	{
		MenuPrincipal(&opcionCliente, 0, 13);
		switch(opcionCliente)
		{
		case 0:
			if(utn_getRespuestaSiNo("Desea salir del menu cliente?") == 1)
			{
				opcionCliente = -1;
				printf("\n%60s", "Saliendo...");
			}
		break;
		case 1:
			Info_DarDeAltaCliente(listaCliente, TAM_CLIENTE, &eCliente_idAutoincremental, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 2:
			Info_ModificarCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 3:
			Info_DarDeBajaCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 4:
			Info_CrearPedidoPedido(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE, &ePedido_idAutoincremental, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 5:
			Info_ProcesarResiduosPedido(listaPedido, TAM_PEDIDO);
		break;
		case 6:
			Info_ListarClientesPendientes(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 7:
			Info_ListarPedidosPendientesConCliente(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
		break;
		case 8:
			Info_ListarPedidosCompletados(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
		break;
		case 9:
			//Info_MostrarCantidadPorLocalidad(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD);
		break;
		case 10:
			Info_MostrarPromedioKilosPP(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
		break;
		case 11:
			eCliente_BuscarMayorPorTipo(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO, PENDIENTE);
		break;
		case 12:
			eCliente_BuscarMayorPorTipo(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO, COMPLETADO);
		break;
		case 13:
			eCliente_BuscarMayorPorTipoDistinto(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO, COMPLETADO);
		break;
		}
	}while(opcionCliente != -1);

	return EXIT_SUCCESS;
}
