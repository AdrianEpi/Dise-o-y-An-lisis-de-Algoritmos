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
* @Last Modified time: 2020-04-26 12:45:27
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
void GraspAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	int RLCSize, iterations, mode;
	selectData(RLCSize, iterations, mode);
	chrono.startChrono();
	std::vector<Vertex> solution;
	int counterLoops = 0;
	initialSolution(graph, solution);
	if (mode == 2) {
		while (counterLoops < iterations) {
			std::vector<Vertex> RLC;	// Restricted List of Candidates
			std::vector<Vertex> tempSolution = solution;
			generateRLC(RLC, solution, graph, RLCSize);
			int vertexPosition = getRandomVertex(RLC);
			if (vertexPosition != -1) {
				tempSolution.push_back(graph.get_Vertex()[vertexPosition]);
				if (findMean(tempSolution, graph) > findMean(solution, graph)) {
					solution.push_back(graph.get_Vertex()[vertexPosition]);
				}
				else {
					counterLoops++;
				}
			}
			else {
				counterLoops++;
			}
		}
	}
	else {
		while (counterLoops < iterations) {
			std::vector<Vertex> RLC;	// Restricted List of Candidates
			std::vector<Vertex> tempSolution = solution;
			generateRLC(RLC, solution, graph, RLCSize);
			int vertexPosition = getRandomVertex(RLC);
			if (vertexPosition != -1) {
				tempSolution.push_back(graph.get_Vertex()[vertexPosition]);
				if (findMean(tempSolution, graph) > findMean(solution, graph)) {
					solution.push_back(graph.get_Vertex()[vertexPosition]);
				}
			}
			counterLoops++;
		}
	}
	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
	chrono.stopChrono();
}

/**
 * @brief      Generates the Random List of Candidates
 *
 * @param      RLC       The rlc
 * @param[in]  solution  The solution
 * @param[in]  graph     The graph
 */
void GraspAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph, int RLCSize) {
	std::vector<Vertex> tempRLC;
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			tempRLC.push_back(graph.get_Vertex()[vertexCounter]);
		}
	}
	int size = tempRLC.size();
	while ((RLC.size() < RLCSize) && (size > 0)) {
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
 * @brief      Prints a menu for let the user select the parameters of the algorithm.
 *
 * @param      RLCSize     The rlc size
 * @param      iterations  The iterations
 * @param      stopMode    The stop mode
 */
void GraspAlgorithm::selectData (int& RLCSize, int& iterations, int& stopMode) {
	int aux;
	std::cout << std::endl << "Please select the stop mode: ";
	std::cout << std::endl << "\t 1. Number of iterations";
	std::cout << std::endl << "\t 2. Number of iterations without improvement" << std::endl;
	std::cin >> aux;
	assert(aux == 1 || aux == 2);
	stopMode = aux;
	std::cout << std::endl << "Please select the Restricted List of Candidates (RLC) size: ";
	std::cin >> aux;
	assert(aux > 0);
	RLCSize = aux;
	std::cout << std::endl << "Please select the number of itreations: ";
	std::cin >> aux;
	assert(aux > 0);
	iterations = aux;
}