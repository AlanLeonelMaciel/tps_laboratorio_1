/*
 * biblioteca2-TP1.h
 *
 *  Created on: 16 abr. 2022
 *      Author: AlanMaciel
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECA2_TP1_H_
#define BIBLIOTECA2_TP1_H_

/// @fn int SumarVector(int[], int)
/// @brief Suma los numeros ingresados en un vector partiendo de la posicion 0 de su indice.
///
/// @param vector: Recibe el vector a sumar.
/// @param size: Recibe el tamaño del mismo.
/// @return Retorna la suma del vector.
int SumarVector(int vector[], int size);

/// @fn float DescontarUnPorcentajeDelTotal(int, float)
/// @brief Descuenta el porcentaje ingresado, a un numero flotante ingresado.
///
/// @param porcentaje: Porcentaje a descontar.
/// @param total: numero flotante al que se descuenta dicho porcentaje.
/// @return Retorna el numero con el descuento aplicado.
float DescontarUnPorcentajeDelTotal(int porcentaje,float total);

/// @fn float SumarPorcentajeAlNumero(int, float)
/// @brief Suma el porcentaje ingresado, a un numero flotante ingresado.
///
/// @param porcentaje: Porcentaje a sumar.
/// @param numero: numero flotante al que se le suma dicho porcentaje.
/// @return Retorna el numero con el aunmento aplicado.
float SumarPorcentajeAlNumero(int porcentaje, float numero);

/// @fn int DevuelveCuantasCifrasTieneUnNumero(float)
/// @brief Devuelve la cantidad de cifras que tiene un numero.
///
/// @param numero: Recibe el numero para contar sus cifras.
/// @return Retorna el numero de cifras.
int DevuelveCuantasCifrasTieneUnNumero(float numero);


#endif /* BIBLIOTECA2_TP1_H_ */
