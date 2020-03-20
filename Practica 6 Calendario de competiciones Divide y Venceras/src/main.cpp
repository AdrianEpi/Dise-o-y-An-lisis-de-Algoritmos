/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 6 Calendario de Competiciones DyV         =
    =            File name:     calendar.hpp                                       =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         20/03/2020                                         =
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
* @Date:   2020-03-20 13:06:38
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-20 17:01:33
*/

/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../include/calendar.hpp"

/*-------------------------------------------------*/
void help(void);


int main(int argc, char *argv[]) {
	if (argc != 2) {
		help();
		exit(0);
	}
	Calendar asd(atoi(argv[1]));
	return 0;
}

void help(void) {
	std::cout << std::endl << "Manual de ayuda al usuario";
	std::cout << std::endl << "Introduzca como parámetro la cantidad de equipos. Actualmente solo funciona el algoritmo para equipos potencias de base 2.";
	std::cout << std::endl << std::endl << "\t Ejemplo de uso:";
	std::cout << std::endl << "../bin/calendar 16";
	std::cout << std::endl;
}