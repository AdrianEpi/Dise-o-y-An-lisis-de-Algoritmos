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
* @Last Modified time: 2020-04-26 12:29:14
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
	chrono.startChrono();
	int size = 2;
	if (rint(graph.get_VertexNum()) / 4 > 2) {
		size = rint(graph.get_VertexNum()) / 4;
	}
	set_NeighbourHoodSize(size);
	size = 0;
	std::vector<Vertex> solution;
	initialRandomSolution(graph, solution);
	int counterLoops = 0;


	while (counterLoops < ITERATIONS) {
		std::vector<Vertex> neighbourHood;
		std::vector<Vertex> tempSolution = solution;
		generateNeighbourHoodStructure(neighbourHood, solution, graph, size);
		int vertexPosition = getRandomVertex(neighbourHood);
		tempSolution.push_back(graph.get_Vertex()[vertexPosition]);
		if ((findMean(tempSolution, graph) > findMean(solution, graph)) && (vertexPosition != -1)) {
			solution.push_back(graph.get_Vertex()[vertexPosition]);
			size = 0;
		}
		else {
			if (size < 3) {
				size++;
			}
			counterLoops++;
		}
	}
	set_Solution(solution);
	set_MaxMean(findMean(solution, graph));
	chrono.stopChrono();
	/*std::vector<Vertex> solution;
	bool endAlgorithm = false;
	int counterLoops = 0;
	initialSolution(graph, solution);
	while (endAlgorithm == false) {
		std::vector<Vertex> neighbourHood;	// Restricted List of Candidates
		std::vector<Vertex> tempSolution = solution;
		generateNeigbourhoodStructure(neighbourHood, solution, graph, 0);
		int vertexPosition = getRandomVertex(neighbourHood);
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
	*/
}

void VNSAlgorithm::getGraspSolution (std::vector<Vertex>& solution, Graph& graph) {

}






void VNSAlgorithm::generateNeighbourHoodStructure(std::vector<Vertex>& neighbourHood, std::vector<Vertex> solution, Graph graph, int neighbourHoodSelector) {
	float tempMean = findMean(solution, graph);
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size() && neighbourHood.size() < 10; vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			std::vector<Vertex> tempSolution = solution;
			tempSolution.push_back(graph.get_Vertex()[vertexCounter]);
			if (findMean(tempSolution, graph) > tempMean) {
				neighbourHood.push_back(graph.get_Vertex()[vertexCounter]);
			}
		}
	}
}