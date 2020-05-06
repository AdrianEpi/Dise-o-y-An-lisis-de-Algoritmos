/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     AnotherGreedyAlgorithm.cpp                         =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-04-17 09:29:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-26 22:45:23
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/AnotherGreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
AnotherGreedyAlgorithm::AnotherGreedyAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
AnotherGreedyAlgorithm::~AnotherGreedyAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void AnotherGreedyAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	initialSolution(graph, solution);
	float mean = findMean(solution, graph);
	for (int vertexCounter = 2; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			std::vector<Vertex> tempSolution = solution;
			tempSolution.push_back(graph.get_Vertex()[vertexCounter]);
			float tempMean = findMean(tempSolution, graph);
			if (tempMean > mean) {
				solution.push_back(graph.get_Vertex()[vertexCounter]);
				mean = tempMean;
			}
		}
	}
	set_Solution(solution);
	set_MaxMean(mean);
	chrono.stopChrono();
}