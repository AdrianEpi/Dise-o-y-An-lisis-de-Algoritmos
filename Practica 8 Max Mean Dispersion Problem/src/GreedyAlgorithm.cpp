/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     GreedyAlgorithm.cpp                                =
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
* @Last Modified time: 2020-04-17 13:53:00
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GreedyAlgorithm::GreedyAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
GreedyAlgorithm::~GreedyAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void GreedyAlgorithm::runAlgorithm (Graph& graph) {
	std::vector<Vertex> tempSolution;
	std::vector<Vertex> solution;
	int vertexNumber = findMaxDistance(graph, tempSolution);
	bool found = false;
	if (vertexNumber >= 0) {
		solution.push_back(graph.get_Vertex()[vertexNumber]);
		tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
	}
	else {
		std::cout << std::endl << "ERROR in GreedyAlgorithm" << std::endl;
		exit(0);
	}
	do {
		vertexNumber = findMaxVertexDispersion(graph, tempSolution);
		if (vertexNumber == -1) {
			break;
		}
		tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
		if (findMean(tempSolution, graph) >= findMean(solution, graph)) {
			solution.push_back(graph.get_Vertex()[vertexNumber]);
		}
	} while (findMean(tempSolution, graph) == findMean(solution, graph));
	set_Solution(tempSolution);
	set_MaxMean(findMean(tempSolution, graph));
}

/**
 * @brief      Finds a the maximum vertex distance witout being in vector.
 *
 * @param      graph   The graph
 * @param[in]  vertex  The vertex
 *
 * @return     The number of the vertex
 */
int GreedyAlgorithm::findMaxDistance (Graph& graph, std::vector<Vertex> vertex) {
	int vertexNumber = -1;
	int tempMaxMean = STARTMEAN;
	for (int i = 0; i < graph.get_Vertex().size(); i++) {
		for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
			if ((graph.get_Vertex()[i].get_Number() == graph.get_Edges()[edge].get_VertexA())) {
				if (isInVector(graph.get_Vertex()[i].get_Number(), vertex) == false) {
					if (graph.get_Edges()[edge].get_Distance() > tempMaxMean) {
						tempMaxMean = graph.get_Edges()[edge].get_Distance();
						vertexNumber = i;
					}
				}
			}
		}
	}
	return vertexNumber;
}

/**
 * @brief      Finds the maximum vertex mean dispersion.
 *
 * @param      graph   The graph
 * @param[in]  vertex  The vertex
 *
 * @return     The number of the vertex
 */
int GreedyAlgorithm::findMaxVertexDispersion (Graph& graph, std::vector<Vertex> vertex) {
	int vertexNumber = -1;
	int tempMaxMean = STARTMEAN;
	for (int i = 0; i < graph.get_Vertex().size(); i++) {
		int tempMean = 0;
		for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
			if ((graph.get_Vertex()[i].get_Number() == graph.get_Edges()[edge].get_VertexA())) {
				tempMean += graph.get_Edges()[edge].get_Distance();
			}
		}
		if (isInVector(i, vertex) == false) {
			if (tempMean > tempMaxMean) {
				vertexNumber = i;

				tempMaxMean = tempMean;
			}
		}
	}
	return vertexNumber;
}

/**
 * @brief      Determines if a vertex is in vector.
 *
 * @param[in]  number  The number
 * @param[in]  vertex  The vertex
 *
 * @return     True if in vector, False otherwise.
 */
bool GreedyAlgorithm::isInVector (int number, std::vector<Vertex> vertex) {
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].get_Number() == number) {
			return true;
		}
	}
	return false;
}

/**
 * @brief      Prints the solurion result.
 *
 * @param      os    The output stream
 *
 * @return     output Stream
 */
std::ostream& GreedyAlgorithm::printResult (std::ostream& os) {
	os << std::endl << "Solution: { ";
	for (int i = 0; i < get_Solution().size() - 1; i++) {
		os << get_Solution()[i].get_Number() << ", ";
	}
	os << get_Solution()[get_Solution().size() - 1].get_Number() << " }" << std::endl;
	os << "Max-Mean value: " << get_MaxMean() << std::endl;
	return os;
}
