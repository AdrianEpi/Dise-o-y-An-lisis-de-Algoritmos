/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     VNSAlgorithm.cpp                                   =
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
* @Date:   2020-04-24 11:51:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-26 13:44:31
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/VNSAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
VNSAlgorithm::VNSAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
VNSAlgorithm::~VNSAlgorithm () {
}

/**
 * @brief      Gets the neighbour hood size.
 *
 * @return     The neighbour hood size.
 */
int VNSAlgorithm::get_NeighbourHoodSize (void) {
	return neighbourHoodSize_;
}

/**
 * @brief      Sets the neighbour hood size.
 *
 * @param[in]  size  The size
 */
void VNSAlgorithm::set_NeighbourHoodSize (int size) {
	neighbourHoodSize_ = size;
}

/**
 * @brief      Executes the VNS algorithm
 *
 * @param      graph  The graph
 */
void VNSAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	int RLCSize, iterations, mode, counterLoops = 0, swapSize = 1;
	selectData(RLCSize, iterations, mode);
	std::vector<Vertex> solution;
	chrono.startChrono();
	getGraspSolution(solution, graph, RLCSize, iterations);
	while(counterLoops < iterations) {
		std::vector<Vertex> tmpSolution = solution;
		std::vector<Vertex> possibilities;
		genertePossiblesChanges(possibilities, tmpSolution, graph);
		swapVertex(possibilities, tmpSolution, swapSize);
		if (findMean(tmpSolution, graph) > findMean(solution, graph)) {
			solution = tmpSolution;
			swapSize = 1;
		}
		else {
			swapSize++;
			if (swapSize > 3) {
				swapSize = 1;
			}
		}
		counterLoops++;
	}

	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
	chrono.stopChrono();
}

void VNSAlgorithm::getGraspSolution (std::vector<Vertex>& solution, Graph& graph, int& RLCSize, int& iterations) {
	int counterLoops = 0;
	initialSolution(graph, solution);
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

void VNSAlgorithm::genertePossiblesChanges (std::vector<Vertex>& possibilities, std::vector<Vertex>& solution, Graph& graph) {
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			possibilities.push_back(graph.get_Vertex()[vertexCounter]);
		}
	}
}

void VNSAlgorithm::swapVertex (std::vector<Vertex>& possibilities, std::vector<Vertex>& tmpSolution, int& swapsNum) {
	for (int counter = 0; counter < swapsNum || counter < possibilities.size() || counter < tmpSolution.size(); counter++) {
		int vertexVector1 = getRandomVertex(tmpSolution);
		int vertexVector2 = getRandomVertex(possibilities);
		tmpSolution.erase(tmpSolution.begin() + vertexVector1);
		tmpSolution.push_back(possibilities[vertexVector2]);
		possibilities.erase(possibilities.begin() + vertexVector2);

	}
}

/**
 * @brief      Prints a menu for let the user select the parameters of the algorithm.
 *
 * @param      RLCSize     The rlc size
 * @param      iterations  The iterations
 * @param      stopMode    The stop mode
 */
void VNSAlgorithm::selectData (int& RLCSize, int& iterations, int& stopMode) {
	int aux;
	std::cout << std::endl << "Please select the stop mode: ";
	std::cout << std::endl << "\t 1. Number of iterations";
	std::cout << std::endl << "\t 2. Number of iterations without improvement" << std::endl;
	std::cin >> aux;
	assert(aux == 1 || aux == 2);
	stopMode = aux;
	std::cout << std::endl << "Please select the Restricted List of Candidates (RLC) size for the GRASP initial solution: ";
	std::cin >> aux;
	assert(aux > 0);
	RLCSize = aux;
	std::cout << std::endl << "Please select the number of itreations: ";
	std::cin >> aux;
	assert(aux > 0);
	iterations = aux;
}

/**
 * @brief      Generates the Random List of Candidates
 *
 * @param      RLC       The rlc
 * @param[in]  solution  The solution
 * @param[in]  graph     The graph
 */
void VNSAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex>& solution, Graph& graph, int& RLCSize) {
	std::vector<Vertex> tempRLC;
	genertePossiblesChanges(tempRLC, solution, graph);
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