/*
 * trabajo 1
 *
 *  Created on: 4 abr. 2022
 *      Author: Alan Maciel
 */

#include "bibliotecaTP1.h"

void IngresarNumeroVector(int vector[], int size)
	{
		for(int i=0;i<size;i++)
			{
				printf("Ingrese un numero:\n");
				scanf("%d",&vector[i]);

			}
	}

void MostrarNumerosVector(int vector[], int size)
	{
		for(int i=0;i<size;i++)
		{
			printf("Los numeros son: %d \n",vector[i]);
		}
	}


	int PedirNumeroEntero(char mensaje[])
	{
		int numero;
		printf("%s",mensaje);
		scanf("%d",&numero);

		return numero;
	}

	void MostrarMensajePausar(char mensaje[])
	{
		printf("%s",mensaje);
		system("pause");
	}

	float PedirNumeroFlotante(char mensaje[])
	{
		float numero;
		printf("%s",mensaje);
		scanf("%f",&numero);

		return numero;
	}

	float ValidarSiEsMenorIgualA(float numero, float numeroCondicion, char mensaje[])
	{
		while(numero<=numeroCondicion)
		{
			numero=PedirNumeroEntero(mensaje);
		}
		return numero;
	}

	char ModificarMenu(float numero, float otroNumero, float tercerNumero, char mensaje[500])
	{


		if (numero>0&&otroNumero>0&&tercerNumero>0)
		{
			sprintf(mensaje,"1. Ingresar kilometros: (km=%.2f) \n\n2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",numero,otroNumero,tercerNumero,37,37);
		}
		else
		{
			if(numero>0&&otroNumero>0)
			{
				sprintf(mensaje,"1. Ingresar kilometros: (km=%.2f) \n\n2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",numero,otroNumero,37,37);
			}
			else
			{
				if (numero>0&&tercerNumero>0)
				{
					sprintf(mensaje,"1. Ingresar kilometros: (km=%.2f) \n\n2. Ingresar Precio de Vuelos: (Aerolineas, Latam=%.2f)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",numero,tercerNumero,37,37);
				}
				else
				{
					if(tercerNumero>0&&otroNumero>0)
					{
						sprintf(mensaje,"1. Ingresar kilometros: (km=0) \n\n2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",otroNumero,tercerNumero,37,37);
					}

				}
			}
		}
		if(numero>0&&otroNumero<=0&&tercerNumero<=0)
		{
			sprintf(mensaje,"1. Ingresar kilometros: (km=%.2f) \n\n2. Ingresar Precio de Vuelos: (Aerolineas, Latam)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",numero,37,37);
		}
		else
		{
			if(numero<=0&&otroNumero>0&&tercerNumero<=0)
			{
				sprintf(mensaje,"1. Ingresar kilometros: (km=0) \n\n2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",otroNumero,37,37);
			}
			else
			{
				if(numero<=0&&otroNumero<=0&&tercerNumero>0)
				{
					sprintf(mensaje,"1. Ingresar kilometros: (km=0) \n\n2. Ingresar Precio de Vuelos: (Aerolineas, Latam=%.2f)\n\n3. Calcular todos los costos:\nTarjeta de debito (descuento 10%c)\nTarjeta de credito (interes 25%c)\nBitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nPrecio por km (precio unitario)\nDiferencia de precio ingresada (Latam - Aerolineas)\n\n4. Informar Resultados.\n\n5. Carga forzada de datos.\n\n6. Salir\n",tercerNumero,37,37);
				}


			}
		}
		return (char)mensaje[500];
	}

	char ValidarCaracter(char caracter)
	{
		while(caracter!='n'&&caracter!='s')
		{
			printf("Error, presionar 'n' si esta seguro de salir. De lo contrario,para seguir, presione 's'. ");
			fflush(stdin);
			scanf("%c",&caracter);

		}


		return caracter;
	}

	char PedirUnChar(char mensaje[])
	{
		char caracter;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&caracter);

		return caracter;
	}
