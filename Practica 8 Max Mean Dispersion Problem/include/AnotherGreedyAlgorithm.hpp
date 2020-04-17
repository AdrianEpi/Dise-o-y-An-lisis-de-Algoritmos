/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     AnotherGreedyAlgorithm.hpp                         =
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

class AnotherGreedyAlgorithm : public Algorithm {

	public:
		AnotherGreedyAlgorithm ();
		virtual ~AnotherGreedyAlgorithm ();

		void runAlgorithm (Graph& graph);
		int findMaxDistance (Graph& graph, std::vector<Vertex> vertex);
		int findMaxVertexDispersion (Graph& graph, std::vector<Vertex> vertex);
		bool isInVector (int number, std::vector<Vertex> vertex);
		std::ostream& printResult (std::ostream& os);


};