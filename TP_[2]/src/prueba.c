
/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alan Maciel
 ============================================================================
 */
#define CANT 5
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"



int main(void)
{
	char continuar='s';
	int opcionMenu;
	int cantidadDeDatos=0;
	int bajaIdpasajero;
	int indiceBaja;
	float sumaImporte;
	float promedioImportes;
	int pasajerosSuperandoPromedio;
	int cantidadDeDatosForzados=5;

	eTipoPasajero tiposDePasajeros[3]=
	{
			{1,"Clase economica"},
			{2,"Clase ejecutiva"},
			{3,"Primera clase"}
	};
	ePasajero pasajerosForzado[5]= // Carga forzada
		{
				{200,"Alan","Maciel",500,"f5d6",3,1,1},
				{200,"Juan","Herrera",1000,"g6d6",2,3,1},
				{200,"Roberto","Gonzalez",3000,"h5d6",3,2,1},
				{200,"Camila","Benitez",5000,"kgu6",1,2,1},
				{200,"victoria","Sanchez",50000,"8h75d",3,2,1}
		};
	setbuf(stdout,0);
	ePasajero pasajeros[CANT];//Mi vector de pasajeros
		//Cargar estado de pasajero en cero
		initPasengers(pasajeros, CANT);
		//comienzo do While
		do
		{
			opcionMenu=Menu("1) Alta\n2) Modificar\n3) Baja\n4) Informar\n5) Carga forzada pasajeros\n6) Salir\n"); // El menu
			switch(opcionMenu)
			{
			case 1: //Alta////////////////////////////////////////
				if(RecorrerArrayBuscandoEmpy(pasajeros, CANT)>=0)
				{
					pasajeros[RecorrerArrayBuscandoEmpy(pasajeros, CANT)]=CargarPasajero();
					cantidadDeDatos++;
				}
				else
				{
					printf("No queda mas espacio en el sistema\n");
				}

				break;
			case 2: //Modificacion/////////////////////////////////
				if(cantidadDeDatos!=0)
				{
					printf("Ingrese un Id de pasajero: ");
					scanf("%d",&bajaIdpasajero);
					indiceBaja=findPassengerById(pasajeros,CANT,bajaIdpasajero);
					if(indiceBaja>=0)
					{
						opcionMenu=Menu("Seleccione la opcion a modificar: \n1)Nombre pasajero.\n2)Apellido Pasajero.\n3)Precio.\n4)Tipo de pasajero.\n5)Codigo de vuelo.\n");
						switch (opcionMenu) //Sub menu de modificacion
						{
						case 1:
							// PedirCadenaCaracteres nombre pasajero
							while (PedirCadenaCaracteres("Ingrese el nombre del pasajero: \n",pasajeros[indiceBaja].nombrePasajero,51)==-1)
							{
								PedirCadenaCaracteres("Ingrese el nombre del pasajero, sin superar los 51 caracteres: \n",pasajeros[indiceBaja].nombrePasajero,51);
							}
							break;
						case 2:
							//Apellido pasajero
							while (PedirCadenaCaracteres("Ingrese el apellido del pasajero: \n",pasajeros[indiceBaja].apellidoPasajero,51)==-1)
							{
								PedirCadenaCaracteres("Ingrese el apellido del pasajero, sin superar los 51 caracteres: \n",pasajeros[indiceBaja].apellidoPasajero,51);
							}
							break;
						case 3:
							//Importe
							pasajeros[indiceBaja].precio=PedirLongFloatMinimoMaximo("Ingrese un precio: ", 1,90000000);
							while(pasajeros[indiceBaja].precio==-1)
							{
								pasajeros[indiceBaja].precio=PedirLongFloatMinimoMaximo("Error, ingrese un precio entre 1 y 90000000: ", 1,90000000);
							}
							break;
						case 4:
							// IdTipoPasajero
							pasajeros[indiceBaja].idTipoPasajero=PedirEnteroMinimoMaximo("Ingrese tipo de pasajero: \n1)Clase economica\n2)Clase ejecutiva\n3)Primera clase\n", 1,3);
							while(pasajeros[indiceBaja].idTipoPasajero==-1)
							{
								pasajeros[indiceBaja].idTipoPasajero=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
							}
							break;
						case 5:
							//CodigoVuelo
							while (PedirCadenaCaracteres("Ingrese el codigo del vuelo: \n",pasajeros[indiceBaja].codigoVuelo,10)==-1)
							{
								PedirCadenaCaracteres("Ingrese el codigo del vuelo, sin superar los 10 caracteres: \n",pasajeros[indiceBaja].codigoVuelo,10);
							}
							break;
						default: printf("No se ha seleccionado una opcion correcta.\n");
						break;
						}//Fin switch submenu modificar
					}//Fin de if indice buscado mayor o  igual a cero.
					else
					{
						printf("No se ha encontrado su codigo\n");
					}
				}//Fin de if de cantidad de datos mayor a cero
				else
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 3: //Baja/////////////////////////////////////////////
				if(cantidadDeDatos!=0)
				{
					if(removePassenger(pasajeros, CANT)!=-1)
					{
						cantidadDeDatos--;
					}

				}
				else
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 4:  ///Informar/////////////////////////////
				if(cantidadDeDatos!=0)
				{
					//submenu informar
					opcionMenu=Menu("Seleccione la opcion a informar: \n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
					switch(opcionMenu)
					{
					case 1:
					//	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
						if(PasajerosOrdenadosPorApellidoYTipo(pasajeros,CANT)==0)
						{
							for(int i=0;i<CANT;i++)
							{
								printf("Pasajero: %s\t",pasajeros[i].apellidoPasajero);
								for (int j=0;j<3;j++)
								{
									if(pasajeros[i].idTipoPasajero==tiposDePasajeros[j].idTipoPasajero)
									{
										printf("Tipo de pasajero: %s\n",tiposDePasajeros[j].descripcionTipoPasajero);
									}
								}
							}
						}
						break;
					case 2:
						//2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
						sumaImporte=RecorrerArraySumandoImporte(pasajeros, CANT);
						promedioImportes=sumaImporte/cantidadDeDatos;
						pasajerosSuperandoPromedio=RecorrerArrayBuscandoCantImporteMayorA(pasajeros, CANT,promedioImportes);
						printf("Total importes: %.2f\tPromedio de importes: %.2f\tCantidad de pasajeros que superan ese promedio: %d\n",sumaImporte,promedioImportes,pasajerosSuperandoPromedio);
						break;
					case 3:
						//3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’*/
						if (ListarPasajerosOrdenadosPorCodigoVuelo(pasajeros,CANT)==0)
						{
							for(int i=0;i<CANT;i++)
							{
								if(pasajeros[i].estadoVuelo==1)
								{
									printf("Apellido: %s\tCodigo de vuelo: %s\tEstado del vuelo: Activo.\n",pasajeros[i].apellidoPasajero,pasajeros[i].codigoVuelo);
								}
							}
						}

						break;
					default: printf("No ha seleccionado una opcion correcta.\n");
					break;
					}//Fin switch de sub menu informar

				}//Fin de if cantidad de datos mayor a 0
				else
				{
					printf("No hay datos cargados.\n");
				}

				break;
			case 5: // Alta forzada////////////////////////////////////////////
				cantidadDeDatosForzados=5;

				opcionMenu=Menu("Seleccione la opcion a informar: \n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
				switch(opcionMenu)
				{
				case 1:
				//	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
					if(PasajerosOrdenadosPorApellidoYTipo(pasajerosForzado,5)==0)
					{
						for(int i=0;i<5;i++)
						{
							printf("Pasajero: %s\t",pasajerosForzado[i].apellidoPasajero);
							for (int j=0;j<3;j++)
							{
								if(pasajerosForzado[i].idTipoPasajero==tiposDePasajeros[j].idTipoPasajero)
								{
									printf("Tipo de pasajero: %s\n",tiposDePasajeros[j].descripcionTipoPasajero);
								}
							}
						}
					}
					break;
				case 2:
				//2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
					sumaImporte=RecorrerArraySumandoImporte(pasajerosForzado, 5);
					promedioImportes=sumaImporte/cantidadDeDatosForzados;
					pasajerosSuperandoPromedio=RecorrerArrayBuscandoCantImporteMayorA(pasajerosForzado, 5,promedioImportes);
					printf("Total importes: %.2f\tPromedio de importes: %.2f\tCantidad de pasajeros que superan ese promedio: %d\n",sumaImporte,promedioImportes,pasajerosSuperandoPromedio);
					break;
				case 3:
					//3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’*/
					if (ListarPasajerosOrdenadosPorCodigoVuelo(pasajerosForzado,5)==0)
					{
						for(int i=0;i<5;i++)
						{
						if(pasajerosForzado[i].estadoVuelo==1)
							{
								printf("Apellido: %s\tCodigo de vuelo: %s\tEstado del vuelo: Activo.\n",pasajerosForzado[i].apellidoPasajero,pasajerosForzado[i].codigoVuelo);
							}
						}
					}

					break;
				default: printf("No ha seleccionado una opcion correcta.\n");
				break;
				}//Fin switch de sub menu informar
				break;
			case 6: //salir
				continuar='n';
				break;

			default: printf("No ha seleccionado una opcion correcta.\n");
			break;
			}//Fin de switch
		}while(continuar=='s');

	return 0;
}
