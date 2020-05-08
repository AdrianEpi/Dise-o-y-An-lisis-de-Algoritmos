/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     LocalSearchAlgorithm.hpp                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         06/05/2020                                         =
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

class LocalSearchAlgorithm : public Algorithm {

	public:
		// Builder & Destroyer
		LocalSearchAlgorithm ();
		virtual ~LocalSearchAlgorithm ();

		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		// Private Functions
		int findMaxDispersion (Graph& graph, std::vector<Vertex>& vertex);
};