/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     AnotherGreedyAlgorithm.cpp                                =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-04-03 20:29:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-17 13:59:13
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
void AnotherGreedyAlgorithm::runAlgorithm (Graph& graph) {
	std::vector<Vertex> solution;
	solution.push_back(graph.get_Vertex()[0]);
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		std::vector<Vertex> tempSolution;
		tempSolution.push_back(graph.get_Vertex()[vertexCounter]);
		if (findMean(tempSolution, graph) > findMean(solution, graph)) {
			solution.push_back(graph.get_Vertex()[vertexCounter]);
		}
	}
	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
}


/**
 * @brief      Prints the solurion result.
 *
 * @param      os    The output stream
 *
 * @return     output Stream
 */
std::ostream& AnotherGreedyAlgorithm::printResult (std::ostream& os) {
	os << std::endl << "Solution: { ";
	for (int i = 0; i < get_Solution().size() - 1; i++) {
		os << get_Solution()[i].get_Number() << ", ";
	}
	os << get_Solution()[get_Solution().size() - 1].get_Number() << " }" << std::endl;
	os << "Max-Mean value: " << get_MaxMean() << std::endl;
	return os;
}
