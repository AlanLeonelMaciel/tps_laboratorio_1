/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alan Leonel Maciel
 Description : Trabajo Práctico número 1 Programación I – Laboratorio I.
Tecnicatura Superior en Programación.

UTN-FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTP1.h"
#include "biblioteca2-TP1.h"


int main(void)
{
	int opcion;
	float precioAerolineas=0;
	float precioLatam=0;
	float kilometros=0;
	char continuar;
	float descuentoDebitoAerolineasArgentinas;
	float descuentoDebitoLatam;
	float interesAerolineasArgentinas;
	float interesLatam;
	int contadorPrecioAerolineas=0,contadorPrecioLatam=0;
	float precioEnBitcoinAerolineasArgentinas,precioEnBitcoinLatam,precioUnitarioAerolineas,precioUnitarioLatam;
	float diferenciaDePrecios;
	char menu[500]= "1. Ingresar kilometros: \n\n2. Ingresar Precio de Vuelos: (Aerolineas, Latam)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%)\nTarjeta de credito (interes 25%)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n\0";
	int OpcionSubMenu;
	char SubMenu[500]="Seleccione una opcion:\n\n1) Ingresar precio para Aerolineas Argentinas: \n2) Ingresar precio para Latam: \n\0";
	char MostrarResultado[500]="Latam: \na) Precio con tarjeta de debito: \nb) Precio con tarjeta de credito: \nc) Precio pagando con bitcoin : \nd) Precio unitario: \nAerolineas: \na) Precio con tarjeta de debito: \nb) Precio con tarjeta de credito: \nc) Precio pagando con bitcoin : \nd) Precio unitario: \nLa diferencia de precio es : \n\0";
	int FlagCalcular=0;
	setbuf(stdout,0);



	do
	{	//COMIENZO DE DO WHILE

//MENU GENERAL
		ModificarMenu(kilometros, precioAerolineas, precioLatam, menu);
		opcion=PedirNumeroEntero(menu);

		switch(opcion) //SWITCH GENERAL
			{
				case 1:
					kilometros=PedirNumeroFlotante("Por favor ingrese los kilometros totales del vuelo: \n ");
					kilometros=ValidarSiEsMenorIgualA(kilometros,0,"Error,ingrese kilometros mayores a 0: ");
					system("cls");
					continuar='s';
					break;
				case 2:
					OpcionSubMenu=PedirNumeroEntero(SubMenu);
					while(OpcionSubMenu!=1&&OpcionSubMenu!=2)
					{
						OpcionSubMenu=PedirNumeroEntero("Error, seleccione una opcion correcta: (1)Aerolineas Argentinas o (2)Latam)");

					}
					switch(OpcionSubMenu)
						{
							case 1:
								precioAerolineas=PedirNumeroFlotante("a) Ingrese precio para Aerolineas Argentinas: \n");
								precioAerolineas=ValidarSiEsMenorIgualA(precioAerolineas,0,"a) Error, ingrese un precio mayor a 0 para Aerolineas Argentinas: \n");
								system("cls");
								contadorPrecioAerolineas++;
								//
								continuar='s';
								break;
							case 2:
								precioLatam=PedirNumeroFlotante("a) Ingrese precio para Latam: \n");
								precioLatam=ValidarSiEsMenorIgualA(precioLatam,0,"a) Error, ingrese un precio mayor a 0 para Latam: \n");
								system("cls");
								contadorPrecioLatam++;
								//
								continuar='s';
								break;
							default:
								MostrarMensajePausar("No has seleccionado una opcion correcta\n\nVolviendo a pantalla pricipal: ");
								continuar='s';
								system("cls");
								break;
						}
						break; //FIN DEL CASE 2 DE SWITCH GENERAL
				case 3:
					if(contadorPrecioAerolineas>0&&contadorPrecioLatam>0) //si tengo los dos precios
					{
						//a) Tarjeta de débito (descuento 10%)
						descuentoDebitoAerolineasArgentinas=DescontarUnPorcentajeDelTotal(10,precioAerolineas);
						descuentoDebitoLatam=DescontarUnPorcentajeDelTotal(10,precioLatam);
						//b) Tarjeta de crédito (interés 25%)
						interesAerolineasArgentinas=SumarPorcentajeAlNumero(25,precioAerolineas);
						interesLatam=SumarPorcentajeAlNumero(25,precioLatam);
						//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
						precioEnBitcoinLatam=precioLatam/4606954.55;
						precioEnBitcoinAerolineasArgentinas=precioAerolineas/4606954.55;
						//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
						diferenciaDePrecios=precioAerolineas-precioLatam;
						if(diferenciaDePrecios<0)//si la diferencia de precios me da negativa
						{
							//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
							diferenciaDePrecios=diferenciaDePrecios*-1;
						}
						sprintf(MostrarResultado,"Latam: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: No se han ingresado kilometros \nAerolineas: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: No se han ingresado kilometros \nLa diferencia de precio es : %.2f \n",precioLatam,descuentoDebitoLatam,interesLatam,precioEnBitcoinLatam,precioAerolineas,descuentoDebitoAerolineasArgentinas,interesAerolineasArgentinas,precioEnBitcoinAerolineasArgentinas,diferenciaDePrecios);
						if (kilometros!=0)
						{
							//d) Mostrar precio por km (precio unitario)
							precioUnitarioAerolineas=precioAerolineas/kilometros;
							precioUnitarioLatam=precioLatam/kilometros;
							sprintf(MostrarResultado,"Latam: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nAerolineas: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nLa diferencia de precio es : %.2f \n",precioLatam,descuentoDebitoLatam,interesLatam,precioEnBitcoinLatam,precioUnitarioLatam,precioAerolineas,descuentoDebitoAerolineasArgentinas,interesAerolineasArgentinas,precioEnBitcoinAerolineasArgentinas,precioUnitarioAerolineas,diferenciaDePrecios);
						}
					}
					else
					{
						if (contadorPrecioAerolineas>0) //si solo tengo el precio aerolineas
						{
							//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) AEROLINEAS
							precioEnBitcoinAerolineasArgentinas=precioAerolineas/4606954.55;
							//a) Tarjeta de débito (descuento 10%) AEROLINEAS
							descuentoDebitoAerolineasArgentinas=DescontarUnPorcentajeDelTotal(10,precioAerolineas);
							//b) Tarjeta de crédito (interés 25%) AEROLNEAS
							interesAerolineasArgentinas=SumarPorcentajeAlNumero(25,precioAerolineas);
							sprintf(MostrarResultado,"Aerolineas: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: No se han cargado kilometros \nLa diferencia de precio es: No se han cargado dos precios\n",precioAerolineas,descuentoDebitoAerolineasArgentinas,interesAerolineasArgentinas,precioEnBitcoinAerolineasArgentinas);
							if (kilometros!=0)
							{
								//d) Mostrar precio por km (precio unitario) AEROLINEAS
								precioUnitarioAerolineas=precioAerolineas/kilometros;
								sprintf(MostrarResultado,"Aerolineas: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nLa diferencia de precio es: No se han registrado dos precios. \n",precioAerolineas,descuentoDebitoAerolineasArgentinas,interesAerolineasArgentinas,precioEnBitcoinAerolineasArgentinas,precioUnitarioAerolineas);
							}
						}
						else
						{
							if (contadorPrecioLatam>0) //si solo tengo el precio de Latam
							{
								//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) LATAM
								precioEnBitcoinLatam=precioLatam/4606954.55;
								//a) Tarjeta de débito (descuento 10%) LATAM
								descuentoDebitoLatam=DescontarUnPorcentajeDelTotal(10,precioLatam);
								//b) Tarjeta de crédito (interés 25%)LATAM
								interesLatam=SumarPorcentajeAlNumero(25,precioLatam);
								sprintf(MostrarResultado,"Latam: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: No se han ingresado kilometros \nLa diferencia de precio es : No se han registrado dos precios. \n",precioLatam,descuentoDebitoLatam,interesLatam,precioEnBitcoinLatam);
								if (kilometros!=0)
								{
									//d) Mostrar precio por km (precio unitario) LATAM
									precioUnitarioLatam=precioLatam/kilometros;
									sprintf(MostrarResultado,"Latam: %.2f \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nLa diferencia de precio es : No se han registrado dos precios. \n",precioLatam,descuentoDebitoLatam,interesLatam,precioEnBitcoinLatam,precioUnitarioLatam);
								}
							}
							else //ELSE SIN NINGUN VUELO
							{
								FlagCalcular=0;
								continuar='s';
								MostrarMensajePausar("Debe ingresar vuelos para calcular. Volviendo al menu principal: ");
								system("cls");
								break;
							}
						}
					}
					FlagCalcular=1;
					continuar='s';
					MostrarMensajePausar("Calculando...\n\nVolviendo a pantalla pricipal. ");
					system("cls");
					break;
				case 4:
					if(FlagCalcular==1)
					{
						printf("%s",MostrarResultado);
					}
					else
					{
						printf("Debe calcular antes de informar los resultados. Volviendo al menu principal: ");
					}
					continuar='s';
					MostrarMensajePausar("\n\n ");
					system("cls");
				break;

				case 5:
					//a) Tarjeta de débito (descuento 10%)
					descuentoDebitoAerolineasArgentinas=DescontarUnPorcentajeDelTotal(10,162965);
					descuentoDebitoLatam=DescontarUnPorcentajeDelTotal(10,159339);
					//b) Tarjeta de crédito (interés 25%)
					interesAerolineasArgentinas=SumarPorcentajeAlNumero(25,162965);
					interesLatam=SumarPorcentajeAlNumero(25,159339);
					//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
					precioEnBitcoinLatam=159339/4606954.55;
					precioEnBitcoinAerolineasArgentinas=162965/4606954.55;
					//d) Mostrar precio por km (precio unitario)
					precioUnitarioAerolineas=(float)162965/7090;
					precioUnitarioLatam=(float)159339/7090;

					//e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
					diferenciaDePrecios=162965-159339;
					printf("Latam: 159339 \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nAerolineas: 162965 \na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin : %f\nd) Precio unitario: %.2f \nLa diferencia de precio es :%.2f \n",descuentoDebitoLatam,interesLatam,precioEnBitcoinLatam,precioUnitarioLatam,descuentoDebitoAerolineasArgentinas,interesAerolineasArgentinas,precioEnBitcoinAerolineasArgentinas,precioUnitarioAerolineas,diferenciaDePrecios);
					continuar='s';
					MostrarMensajePausar("\n\n ");
					system("cls");
				break;

				case 6:
					continuar=PedirUnChar("Presionar 'n' si esta seguro de salir. De lo contrario,para seguir, presione 's'. ");
					continuar=ValidarCaracter(continuar);
					system("cls");
				break;

				default:

					MostrarMensajePausar("No has seleccionado una opcion correcta\n\nVolviendo a pantalla pricipal. ");
					continuar='s';
					system("cls");

					break;
			}//FIN DEL SWITCH GENERAL
	}while(continuar=='s'); //FIN DEL DO WHILE

	return 0;
}
