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
* @Last Modified time: 2020-04-22 19:26:58
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
	baseSolution(graph, tempSolution);
	std::vector<Vertex> solution = tempSolution;
	do {
		int vertexNumber = findMaxDispersion(graph, tempSolution);
		if (vertexNumber == -1) {
			break;
		}
		tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
		if (findMean(tempSolution, graph) >= findMean(solution, graph)) {
			solution.push_back(graph.get_Vertex()[vertexNumber]);
		}
	} while (findMean(tempSolution, graph) == findMean(solution, graph));
	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
}


/**
 * @brief      Generates the base solution of the algorithm
 *
 * @param      graph   The graph
 * @param      vertex  The vertex
 */
void GreedyAlgorithm::baseSolution (Graph& graph, std::vector<Vertex>& vertex) {
	int vertexNumberA = -1;
	int vertexNumberB = -1;
	int tempMaxMean = STARTMEAN;
	for (int i = 0; i < graph.get_Vertex().size(); i++) {
		for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
			if ((graph.get_Vertex()[i].get_Number() == graph.get_Edges()[edge].get_VertexA())) {
				if (isInVector(graph.get_Vertex()[i].get_Number(), vertex) == false) {
					if (graph.get_Edges()[edge].get_Distance() > tempMaxMean) {
						tempMaxMean = graph.get_Edges()[edge].get_Distance();
						vertexNumberA = graph.get_Edges()[edge].get_VertexA();
						vertexNumberB = graph.get_Edges()[edge].get_VertexB();
					}
				}
			}
		}
	}
	vertex.push_back(graph.get_Vertex()[vertexNumberA]);
	vertex.push_back(graph.get_Vertex()[vertexNumberB]);
}

/**
 * @brief      Finds a the maximum dispersion without being in the graph.
 *
 * @param      graph   The graph
 * @param[in]  vertex  The vertex
 *
 * @return     The position of the maximum dispersion vertex
 */
int GreedyAlgorithm::findMaxDispersion (Graph& graph, std::vector<Vertex> vertex) {
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

