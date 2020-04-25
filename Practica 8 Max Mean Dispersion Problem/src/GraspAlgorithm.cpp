/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     GraspAlgorithm.cpp                                 =
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
* @Date:   2020-04-17 17:29:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-25 22:18:15
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GraspAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GraspAlgorithm::GraspAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
GraspAlgorithm::~GraspAlgorithm () {
}

/**
 * @brief      Executes the Grasp algorithm
 *
 * @param      graph  The graph
 */
void GraspAlgorithm::runAlgorithm (Graph& graph) {
	srand(time(NULL));
	std::vector<Vertex> solution;
	bool endAlgorithm = false;
	int counterLoops = 0;
	initialSolution(graph, solution);
	while (endAlgorithm == false) {
		std::vector<Vertex> RLC;	// Restricted List of Candidates
		std::vector<Vertex> tempSolution = solution;
		generateRLC(RLC, solution, graph);
		int vertexPosition = getRandomVertex(RLC);
		tempSolution.push_back(graph.get_Vertex()[vertexPosition]);
		if ((findMean(tempSolution, graph) > findMean(solution, graph)) && (vertexPosition != -1)) {
			solution.push_back(graph.get_Vertex()[vertexPosition]);
		}
		else {
			counterLoops++;
			if (counterLoops >= ITERATIONS) {
				endAlgorithm = true;
			}
		}
	}
	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
}

/**
 * @brief      Generates the Random List of Candidates
 *
 * @param      RLC       The rlc
 * @param[in]  solution  The solution
 * @param[in]  graph     The graph
 */
void GraspAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph) {
	std::vector<Vertex> tempRLC;
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			tempRLC.push_back(graph.get_Vertex()[vertexCounter]);
		}
	}
	int size = tempRLC.size();
	while ((RLC.size() < RLCSIZE) && (size > 0)) {
		int vertex = getRandomVertex(tempRLC);
		if (vertex == -1) {
			break;
		}
		if (isInVector(vertex, RLC) == false) {
			RLC.push_back(graph.get_Vertex()[vertex]);
		}
		size--;
	}
}

/**
 * @brief      Gets a random vertex form the RLC.
 *
 * @param[in]  RLC   The rlc
 *
 * @return     The random vertex.
 */
int GraspAlgorithm::getRandomVertex (std::vector<Vertex> RLC) {
	if (RLC.size() > 0) {
		int num = rand() % RLC.size();
		return RLC[num].get_Number();
	}
	else {
		return -1;
	}
}

/**
 * @brief      Generates the initial solution of the algorithm
 *
 * @param      graph   The graph
 * @param      vertex  The vertex
 */
void GraspAlgorithm::initialSolution (Graph& graph, std::vector<Vertex>& vertex) {
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