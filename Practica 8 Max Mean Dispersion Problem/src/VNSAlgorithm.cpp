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
* @Last Modified time: 2020-04-26 22:26:07
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
	int iterations, mode, counterLoops = 0, swapSize = 1;
	selectData(iterations, mode);
	std::vector<Vertex> solution;
	GraspAlgorithm initalGrasp;
	Chrono tmp;
	chrono.startChrono();
	initalGrasp.runAlgorithm(graph, tmp);
	solution = initalGrasp.get_Solution();
	assert(solution.size() >= 3);
	float mean = findMean(solution, graph);
	if (mode == 1) {
		while (counterLoops < iterations) {
			std::vector<Vertex> tmpSolution = solution;
			std::vector<Vertex> possibilities;
			genertePossiblesChanges(possibilities, tmpSolution, graph);
			swapVertex(possibilities, tmpSolution, swapSize);
			float tmpMean = findMean(tmpSolution, graph);
			if (tmpMean > mean) {
				solution = tmpSolution;
				mean = tmpMean;
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
	}
	else {
		while (counterLoops < iterations) {
			std::vector<Vertex> tmpSolution = solution;
			std::vector<Vertex> possibilities;
			genertePossiblesChanges(possibilities, tmpSolution, graph);
			swapVertex(possibilities, tmpSolution, swapSize);
			float tmpMean = findMean(tmpSolution, graph);
			if (tmpMean > mean) {
				solution = tmpSolution;
				mean = tmpMean;
				swapSize = 1;
			}
			else {
				counterLoops++;
				swapSize++;
				if (swapSize > 2) {
					swapSize = 1;
				}
			}
		}
	}
	set_Solution(solution);
	set_MaxMean(mean);
	chrono.stopChrono();
}

/**
 * @brief      Generates the vector with all the possibles vertex without being in solution.
 *
 * @param      possibilities  The possibilities
 * @param      solution       The solution
 * @param      graph          The graph
 */
void VNSAlgorithm::genertePossiblesChanges (std::vector<Vertex>& possibilities, std::vector<Vertex>& solution, Graph& graph) {
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			possibilities.push_back(graph.get_Vertex()[vertexCounter]);

		}
	}
}

/**
 * @brief      Swaps vertex from the solution with the possible vertex vector for searching a better solution
 *
 * @param      possibilities  The possibilities
 * @param      tmpSolution    The temporary solution
 * @param      swapsNum       The swaps number
 */
void VNSAlgorithm::swapVertex (std::vector<Vertex>& possibilities, std::vector<Vertex>& tmpSolution, int& swapsNum) {
	for (int counter = 0; counter < swapsNum && counter < possibilities.size() && counter < tmpSolution.size(); counter++) {
		int vertexVector1 = getRandomPosition(tmpSolution);
		int vertexVector2 = getRandomPosition(possibilities);
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
void VNSAlgorithm::selectData (int& iterations, int& stopMode) {
	int aux;
	std::cout << std::endl << "Please select the stop mode fo VNS algorithm: ";
	std::cout << std::endl << "\t 1. Number of iterations";
	std::cout << std::endl << "\t 2. Number of iterations without improvement" << std::endl;
	std::cin >> aux;
	assert(aux == 1 || aux == 2);
	stopMode = aux;
	std::cout << std::endl << "Please select the number of itreations for VNSAlgorithm: ";
	std::cin >> aux;
	assert(aux > 0);
	iterations = aux;
}