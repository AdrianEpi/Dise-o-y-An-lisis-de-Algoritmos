/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     MultiBootAlgorithm.cpp                             =
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
* @Date:   2020-04-23 12:09:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-26 12:01:38
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/MultiBootAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
MultiBootAlgorithm::MultiBootAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
MultiBootAlgorithm::~MultiBootAlgorithm () {
}

/**
 * @brief      Switchs wich of the 2 available modes is going to run the code.
 *
 * @param      graph  The graph
 */
void MultiBootAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	switch (MODE) {
		case 1:
			runAlgorithmMode1(graph, chrono);
			break;

		case 2:
			runAlgorithmMode2(graph, chrono);
			break;

		default:
			std::cout << std::endl << "ERROR, not a valid mode un MultiBootAlgorithm" << std::endl;
			exit(0);
			break;
	}
}

/**
 * @brief      Executes the MultiBoot algorithm MODE 1 (Random initial solution & Grasp local search  )
 *
 * @param      graph  The graph
 */
void MultiBootAlgorithm::runAlgorithmMode1 (Graph& graph, Chrono& chrono) {
	srand(time(NULL));
	chrono.startChrono();
	std::vector<Vertex> solution;
	bool endAlgorithm = false;
	int counterLoops = 0;
	initialRandomSolution(graph, solution);
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
	chrono.stopChrono();
}

/**
 * @brief      Executes the MultiBoot algorithm MODE 2 (Grasp initial solution & different local search  )
 *
 * @param      graph  The graph
 */
void MultiBootAlgorithm::runAlgorithmMode2 (Graph& graph, Chrono& chrono) {
	srand(time(NULL));
	chrono.startChrono();
	std::vector<Vertex> solution;
	initialSolution(graph, solution);
	int iteration = 0;
	do {
		int vertexNumber = getRandomVertex(graph.get_Vertex());
		if (vertexNumber >= 0) {
			if (isInVector(vertexNumber, solution) == false) {
				std::vector<Vertex> tempSolution = solution;
				tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
				if (findMean(tempSolution, graph) > findMean(solution, graph)) {
					solution.push_back(graph.get_Vertex()[vertexNumber]);
				}
			}
		}
		iteration++;
	} while (iteration < ITERATIONS);
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
void MultiBootAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph) {
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