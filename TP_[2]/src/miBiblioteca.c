/*
 * miBiblioteca.c
 *
 *  Created on: 14 may. 2022
 *      Author: alanl
 */
#include "miBiblioteca.h"
#ifndef MIBIBLIOTECA_C_
#define MIBIBLIOTECA_C_
int  PedirCadenaCaracteres(char mensaje [],char cadena1[], int TAM)
{
	int retorno=0;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",cadena1);
	if (strlen(cadena1)>TAM)
	{

		printf("su ingreso es incorrecto\n");
		retorno= -1;
	}

return retorno;
}
int PedirEnteroMinimoMaximo(char mensaje[], int minimo,int maximo)
{
	int numero;
	int retorno=-1;
	printf("%s",mensaje);
	scanf("%d",&numero);
	if(numero>=minimo&&numero<=maximo)
	{
		retorno=numero;
	}
	else
	{
		retorno=-1;
	}
	return retorno;

}
double PedirLongFloatMinimoMaximo(char mensaje[], double minimo,double maximo)
{
	double numero;
	double retorno=-1;
	printf("%s",mensaje);
	scanf("%lf",&numero);
	if(numero>=minimo&&numero<=maximo)
	{
		retorno=numero;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}

#endif /* MIBIBLIOTECA_C_ */
