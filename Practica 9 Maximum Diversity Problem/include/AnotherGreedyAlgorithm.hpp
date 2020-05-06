/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     AnotherGreedyAlgorithm.hpp                         =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         17/04/2020                                         =
	=            Subject:       Diseño y Análisis de Algoritmos                    =
	=            Language:      C++                                                =
	=            Email:         alu0101158280@ull.edu.es                           =
	=            Place:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class AnotherGreedyAlgorithm : public Algorithm {

	public:
		// Builder & Destroyer
		AnotherGreedyAlgorithm ();
		virtual ~AnotherGreedyAlgorithm ();

		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);
};