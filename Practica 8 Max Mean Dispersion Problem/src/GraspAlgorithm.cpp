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
* @Last Modified time: 2020-04-17 19:08:47
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

void GraspAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph) {
	float tempMean = findMean(solution, graph);
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			std::vector<Vertex> tempSolution;
			tempSolution.push_back(graph.get_Vertex()[vertexCounter]);
			if (findMean(tempSolution, graph) > tempMean) {
				RLC.push_back(graph.get_Vertex()[vertexCounter]);
			}
		}
	}
}

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
 * @brief      Determines if a vertex is in vector.
 *
 * @param[in]  number  The number
 * @param[in]  vertex  The vertex
 *
 * @return     True if in vector, False otherwise.
 */
bool GraspAlgorithm::isInVector (int number, std::vector<Vertex> vertex) {
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].get_Number() == number) {
			return true;
		}
	}
	return false;
}