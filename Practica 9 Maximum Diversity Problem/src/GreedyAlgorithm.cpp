/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     GreedyAlgorithm.cpp                                =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-04-03 20:29:34
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-06 17:27:37
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
void GreedyAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> tempSolution;
	initialSolution(graph, tempSolution);
	std::vector<Vertex> solution = tempSolution;
	float mean = findMean(solution, graph);
	float tempMean = 0;
	do {
		int vertexNumber = findMaxDispersion(graph, tempSolution);
		if (vertexNumber == -1) {
			break;
		}
		tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
		tempMean = findMean(tempSolution, graph);
		if (tempMean >= mean) {
			solution.push_back(graph.get_Vertex()[vertexNumber]);
			mean = tempMean;
		}
	} while (tempMean == mean);
	set_Solution(solution);
	set_MaxMean(mean);
	chrono.stopChrono();
}


/**
 * @brief      Finds a the maximum dispersion without being in the graph.
 *
 * @param      graph   The graph
 * @param[in]  vertex  The vertex
 *
 * @return     The position of the maximum dispersion vertex
 */
int GreedyAlgorithm::findMaxDispersion (Graph& graph, std::vector<Vertex>& vertex) {
	int mean = STARTMEAN;
	int vertexNumber = -1;
	for (int i = 0; i < graph.get_Vertex().size(); i++) {
		int tempMean = 0;
		if (isInVector(graph.get_Vertex()[i].get_Number(), vertex) == false) {
			for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
				if ((isInVector(graph.get_Edges()[edge].get_VertexA(), vertex) == true) && (graph.get_Vertex()[i].get_Number()) == graph.get_Edges()[edge].get_VertexB()) {
					tempMean += graph.get_Edges()[edge].get_Distance();
				}
			}
			if (mean < tempMean) {
				mean = tempMean;
				vertexNumber = i;
			}
		}
	}
	return vertexNumber;
}

