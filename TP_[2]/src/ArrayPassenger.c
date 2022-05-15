/*
 * getTP2.c
 *
 *  Created on: 13 may. 2022
 *      Author: alanl
 */
#include "ArrayPassenger.h"

static int idIncremental = 2000;
static int obtenerIdPasajero();
static int obtenerIdPasajero() {
	return idIncremental++;
}

int Menu(char menus[])
{
	int opcionMenu;
	printf("%s",menus);
	scanf("%d",&opcionMenu);
	return opcionMenu;
}

int RecorrerArrayBuscandoEmpy(ePasajero* pasajeros, int size)
{
	int retorno=-1;
	int i;

	if(pasajeros!=NULL&&size>0)
	{

		for(i=0;i<size;i++)
		{
			if (pasajeros[i].isEmpty==0)
			{
				return retorno=i;
				break;

			}
		}
	}
	return retorno;
}
ePasajero CargarPasajero(void)
{
	ePasajero pasajero;

		pasajero.idPasajero=obtenerIdPasajero();//Codigo album generico e incremental
		printf("Su ID de pasajero es: %d\n\n",pasajero.idPasajero); //Muestro ID pasajero generico
		// PedirCadenaCaracteres nombre pasajero
		while (PedirCadenaCaracteres("Ingrese el nombre del pasajero: \n",pasajero.nombrePasajero,51)==-1)
		{
			PedirCadenaCaracteres("Ingrese el nombre del pasajero, sin superar los 51 caracteres: \n",pasajero.nombrePasajero,51);
		}

		//Apellido pasajero
		while (PedirCadenaCaracteres("Ingrese el apellido del pasajero: \n",pasajero.apellidoPasajero,51)==-1)
		{
			PedirCadenaCaracteres("Ingrese el apellido del pasajero, sin superar los 51 caracteres: \n",pasajero.apellidoPasajero,51);
		}


		//Importe
		pasajero.precio=PedirLongFloatMinimoMaximo("Ingrese un precio: ", 1,90000000);
		while(pasajero.precio==-1)
		{
			pasajero.precio=PedirLongFloatMinimoMaximo("Error, ingrese un precio entre 1 y 90000000: ", 1,90000000);
		}
		// IdTipoPasajero
		pasajero.idTipoPasajero=PedirEnteroMinimoMaximo("Ingrese tipo de pasajero: \n1)Clase economica\n2)Clase ejecutiva\n3)Primera clase\n", 1,3);
		while(pasajero.idTipoPasajero==-1)
		{
			pasajero.idPasajero=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
		}

		//CodigoVuelo
		while (PedirCadenaCaracteres("Ingrese el codigo del vuelo: \n",pasajero.codigoVuelo,10)==-1)
		{
			PedirCadenaCaracteres("Ingrese el codigo del vuelo, sin superar los 10 caracteres: \n",pasajero.codigoVuelo,10);
		}

		//Estado de vuelo
		pasajero.estadoVuelo=PedirEnteroMinimoMaximo("Seleccione estado de vuelo: \n1)Activo\n2)Cancelado\n3)Demorado", 1,3);
		while(pasajero.estadoVuelo==-1)
		{
			pasajero.estadoVuelo=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
		}


		pasajero.isEmpty=1;
		return pasajero;
}



float RecorrerArraySumandoImporte(ePasajero* array, int size)
{
	float retorno=-1;
	int i;
	float sumaImporte=0;

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].isEmpty!=0&&array[i].precio>0)
			{
				sumaImporte=sumaImporte+array[i].precio;
				retorno=sumaImporte;
			}
		}
	}
	return retorno;
}
int RecorrerArrayBuscandoCantImporteMayorA(ePasajero* array, int size,float importe)
{
	int retorno=-1;
	int i;
	int contadorImporte=0;

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].isEmpty!=0&&array[i].precio>importe)
			{
				contadorImporte++;
				retorno=contadorImporte;
			}
		}
	}
	return retorno;
}
//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.

int PasajerosOrdenadosPorApellidoYTipo(ePasajero* arrayPasajero, int size)
{
	ePasajero auxiliar;
	ePasajero auxiliar2;
	int retorno=-1;

	if(arrayPasajero!=NULL&&size>0)
	{
		for(int i=0;i<size-1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(strcmp(arrayPasajero[i].apellidoPasajero,arrayPasajero[j].apellidoPasajero)>0)
				{
					auxiliar=arrayPasajero[i];
					arrayPasajero[i]=arrayPasajero[j];
					arrayPasajero[j]=auxiliar;
					retorno=0;
				}
				else
				{
					if(strcmp(arrayPasajero[i].apellidoPasajero,arrayPasajero[j].apellidoPasajero)==0)
					{
						if(arrayPasajero[i].idTipoPasajero<arrayPasajero[j].idTipoPasajero) // De mayor clase a menor clase
						{
							auxiliar2=arrayPasajero[i];
							arrayPasajero[i]=arrayPasajero[j];
							arrayPasajero[j]=auxiliar2;
							retorno=0;
						}
					}
				}
			}
		}
	}

return retorno;

}
int ListarPasajerosOrdenadosPorCodigoVuelo(ePasajero* array, int size)
{
	int retorno=-1;
	ePasajero auxiliar;
	if(array!=NULL&&size>0)
	{
	 for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(strcmp(array[i].codigoVuelo,array[j].codigoVuelo)>0)
				{
					auxiliar=array[i];
					array[i]=array[j];
					array[j]=auxiliar;
					retorno=0;
				}
			}
		}
	}

 return retorno;
}
////////////////////////////////
//pasenger
int initPasengers(ePasajero* list, int len)
{
	int i;
	int retorno=-1;
	if (list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=0;
		}
		retorno= 0;
	}
	return retorno;
return 0;
}
int findPassengerById(ePasajero* list, int len,int id)
{

	int retorno=-1;
	int i;

	if(list!=NULL&&len>0)
	{

		for(i=0;i<len;i++)
		{
			if (list[i].isEmpty!=0&&list[i].idPasajero==id)
			{
				printf("Se encontro el siguiente pasajero: %s\n",list[i].apellidoPasajero);
				return retorno= i;
				break;

			}
		}
	}
	return retorno;
}
int removePassenger(ePasajero* list, int len)
{
	int bajaIdpasajero;
	int indiceBaja;
	int retorno=-1;
	printf("Ingrese un ID de pasajero: ");
	scanf("%d",&bajaIdpasajero);
	indiceBaja=findPassengerById(list, len, bajaIdpasajero);
	if(indiceBaja>=0)
	{
		list[indiceBaja].isEmpty=0;
		printf("Su album ha sido eliminado.\n");
		retorno=0;
	}
	else
	{
		printf("No se ha encontrado su codigo\n");
	}

return retorno;
}


