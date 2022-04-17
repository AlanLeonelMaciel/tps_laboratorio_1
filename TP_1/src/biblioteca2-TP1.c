/*
 * biblioteca2-TP1.c
 *
 *  Created on: 16 abr. 2022
 *      Author: alanl
 */

#include "biblioteca2-TP1.h"

	int SumarVector(int vector[], int size)
	{
		int sumar=0;
		for(int i=0;i<size;i++)
		{
			printf("Calculando...\n");
			sumar+=vector[i];
		}
	return sumar;

	}

	float DescontarUnPorcentajeDelTotal(int porcentaje, float total)
	{
		float descuentoAplicado;
		float descuento=0;

		descuento=(float)porcentaje/100*total;

		descuentoAplicado=total-descuento;

		return descuentoAplicado;
	}

	float SumarPorcentajeAlNumero(int porcentaje, float numero)
	{
		float numeroConAumento;
		float aumento;

		aumento=(float)porcentaje/100*numero;
		numeroConAumento=aumento+numero;




		return numeroConAumento;
	}

	int DevuelveCuantasCifrasTieneUnNumero(float numero)
	{
		int numeroCifras=1;

		while(numero>=10)
		{
			numero=numero/10;
			numeroCifras++;
		}


		return numeroCifras;
	}
