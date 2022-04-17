/*
 * trabajarVectores.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Alan Maciel
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_

/// @fn void IngresarNumeroVector(int[], int)
/// @brief funcion para cargar numeros a un vector de enteros.
///
/// @param vector: Recibe el vector a cargar.
/// @param size: Recibe el tamaño del vector.
 void IngresarNumeroVector(int vector[], int size);

 /// @fn void MostrarNumerosVector(int[], int)
 /// @brief Muestra en pantalla los numeros cargados en el vector de enteros
 ///
 /// @param vector: Recibe el vector
 /// @param size: Recibe el tamaño del vector
 void MostrarNumerosVector(int vector[], int size);

 /// @fn int PedirNumeroEntero(char[])
 /// @brief Pide un numero entero y lo retorna.
 ///
 /// @param mensaje: Recibe el mensaje que quiero imprimir en pantalla antes de guardar el entero.
 /// @return Retorna el numero entero.
 int PedirNumeroEntero(char mensaje[]);

 /// @fn void MostrarMensajePausar(char[])
 /// @brief muestra un mensaje en pantalla y pausa la ejecucion del programa.
 ///
 /// @param mensaje: Recibe el mensaje a mostrar en pantalla.
 void MostrarMensajePausar(char mensaje[]);

 /// @fn float PedirNumeroFlotante(char[])
 /// @brief Pide un numero flotante y lo retorna.
 ///
 /// @param mensaje: Recibe el mensaje que quiero imprimir en pantalla antes de guardar el flotante.
 /// @return Retorna el numero flotante.
 float PedirNumeroFlotante(char mensaje[]);

 /// @fn float ValidarSiEsMenorIgualA(float, float, char[])
 /// @brief Valida si un numero flotante es menor o igual a otro numero flotante e imprimite un mensaje.
 ///
 /// @param numero: Recibe el flotante a comparar.
 /// @param numeroCondicion: Recibe otro flotante para comparar con el anterior.
 /// @param mensajeError Si numero es menor o igual a numero condicion se imprime este mensaje de error (a recibir).
 /// @return
 float ValidarSiEsMenorIgualA(float numero, float numeroCondicion, char mensajeError[]);

/// @fn char PedirUnChar(char[])
/// @brief Recibe un mensaje para ingresar un caracter,lo muestra en pantalla, se guarda el caracter y se retorna.
///
/// @param mensaje: Mensaje que se muestra en pantalla para pedir un char.
/// @return Retorna el caracter ingresado.
 char PedirUnChar(char mensaje[]);

 /// @fn char ModificarMenu(float, float, float, char[])
 /// @brief Recibe 3numeros flotantes y en base a esos numeros modifica el mensaje para luego retornarlo modificado.
 ///
 /// @param numero: primer numero flotante
 /// @param otroNumero: segundo numero flotante
 /// @param tercerNumero: tercer numero flotante
 /// @param mensaje: Imprime un mensaje con los numeros ingresados.
 /// @return retorna el nuevo mensaje, modificado.
 char ModificarMenu(float numero, float otroNumero, float tercerNumero, char mensaje[500]);

 /// @fn char ValidarCaracter(char)
 /// @brief Valida si un caracter es distinto de 'n' o 's'. Retornandolo en caso de no ser distinto.
 ///
 /// @param caracter: Recibe el caracter a validar.
 /// @return retorna el caracter ingresado y validado.
 char ValidarCaracter(char caracter);
//



#endif /* BIBLIOTECATP1_H_ */
