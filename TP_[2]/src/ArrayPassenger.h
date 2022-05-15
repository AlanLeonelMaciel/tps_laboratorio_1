/*
 * getTP2.h
 *
 *  Created on: 13 may. 2022
 *      Author: alanl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"

typedef struct
{
	int idTipoPasajero; //principal key
	char descripcionTipoPasajero[51];
}eTipoPasajero;

typedef struct
{
	int idPasajero; //principal key
	char nombrePasajero[51];
	char apellidoPasajero[51];
	float precio;
	char codigoVuelo[10];
	int idTipoPasajero;//Foranea
	int estadoVuelo;
	int isEmpty;


}ePasajero;



#ifndef GETTP2_H_
#define GETTP2_H_

int Menu(char menus[]);
int initPasengers(ePasajero* list, int len);//ya esta
int RecorrerArrayBuscandoEmpy(ePasajero* pasajeros, int size);
ePasajero CargarPasajero(void);
////Validacion

////Fin validacion
int findPassengerById(ePasajero* list, int len,int id);
int removePassenger(ePasajero* list, int len);
float RecorrerArraySumandoImporte(ePasajero* array, int size);
int RecorrerArrayBuscandoCantImporteMayorA(ePasajero* array, int size,float importe);
int PasajerosOrdenadosPorApellidoYTipo(ePasajero* arrayPasajero, int size);
int ListarPasajerosOrdenadosPorCodigoVuelo(ePasajero* array, int size);
/////////////////////////////////////////////////////////////////////////////
//ArrayPassenger.h




#endif /* GETTP2_H_ */
