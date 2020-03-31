/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 7 Subsecuencia común mas larga LCS        =
    =            File name:     lcs.hpp                                            =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         27/03/2020                                         =
    =            Subject:       Diseño y Análisis de Algoritmos                    =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-27 10:24:01
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-31 11:44:25
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/lcs.hpp"

/*------------------------------------------------*/

/**
 * @brief      Main program
 *
 */
int main(void) { 
	std::string string1 = " ", string2 = " ", aux;
	std::cout << std::endl << "Introduce the first secuence: ";
	std::cin >> aux;
	string1 += aux;
	std::cout << std::endl << "Introduce the second secuence: ";
	std::cin >> aux;
	string2 += aux;

	LCS test(string1, string2);
} 
