/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     GreedyAlgorithm.hpp                                =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         03/04/2020                                         =
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

class GreedyAlgorithm : public Algorithm {

	public:
		// Builder & Destroyer
		GreedyAlgorithm ();
		virtual ~GreedyAlgorithm ();

		// Public Function
		void runAlgorithm (Graph& graph);

	private:
		// Private Functions
		int findMaxDistance (Graph& graph, std::vector<Vertex> vertex);
		int findMaxVertexDispersion (Graph& graph, std::vector<Vertex> vertex);
		bool isInVector (int number, std::vector<Vertex> vertex);
};