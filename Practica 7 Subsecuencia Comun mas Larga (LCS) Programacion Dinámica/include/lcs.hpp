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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

/*------------------------------------------------*/


class LCS {

	private:
		std::vector<std::vector<int>> C;

	public:
		// Builders & Destroyer
		LCS();
		LCS(std::string X, std::string Y);
		~LCS();

		// Functions
		int LCSLength(std::string X, std::string Y);
		std::string backTrack(std::vector<std::vector<int>> C, std::string X, std::string Y, int i, int j);
};