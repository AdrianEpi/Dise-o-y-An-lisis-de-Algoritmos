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
* @Last Modified time: 2020-04-23 16:29:08
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
void MultiBootAlgorithm::runAlgorithm (Graph& graph) {
	srand(time(NULL));
	switch (MODE) {
		case 1:
			runAlgorithmMode1(graph);
			break;

		case 2:
			runAlgorithmMode2(graph);
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
void MultiBootAlgorithm::runAlgorithmMode1 (Graph& graph) {
	std::vector<Vertex> solution;
	bool endAlgorithm = false;
	int counterLoops = 0;
	initialRandomSolution(graph, solution);
	while (endAlgorithm == false) {
		std::vector<Vertex> RLC;	// Restricted List of Candidates
		std::vector<Vertex> tempSolution = solution;
		generateRLC(RLC, solution, graph);
		int vertexPosition = getRandomVertex(RLC);
		if (vertexPosition >= 0) {
			tempSolution.push_back(graph.get_Vertex()[vertexPosition]);
			if ((findMean(tempSolution, graph) > findMean(solution, graph)) && (vertexPosition != -1)) {
				solution.push_back(graph.get_Vertex()[vertexPosition]);
			}		
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
 * @brief      Executes the MultiBoot algorithm MODE 2 (Grasp initial solution & different local search  )
 *
 * @param      graph  The graph
 */
void MultiBootAlgorithm::runAlgorithmMode2 (Graph& graph) {
	std::vector<Vertex> solution;
	initialGraspSolution(graph, solution);
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
}
/**
 * @brief      Generates the Random List of Candidates
 *
 * @param      RLC       The rlc
 * @param[in]  solution  The solution
 * @param[in]  graph     The graph
 */
void MultiBootAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph) {
	float tempMean = findMean(solution, graph);
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size() && RLC.size() < RLCSIZE; vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			std::vector<Vertex> tempSolution = solution;
			tempSolution.push_back(graph.get_Vertex()[vertexCounter]);
			if (findMean(tempSolution, graph) > tempMean) {
				RLC.push_back(graph.get_Vertex()[vertexCounter]);
			}
		}
	}
}

/**
 * @brief      Gets a random vertex form the RLC.
 *
 * @param[in]  RLC   The rlc
 *
 * @return     The random vertex.
 */
int MultiBootAlgorithm::getRandomVertex (std::vector<Vertex> RLC) {
	if (RLC.size() > 0) {
		int num = rand() % RLC.size();
		return RLC[num].get_Number();
	}
	else {
		return -1;
	}
}

/**
 * @brief      Generates the initialGrasp solution of the algorithm
 *
 * @param      graph   The graph
 * @param      vertex  The vertex
 */
void MultiBootAlgorithm::initialGraspSolution (Graph& graph, std::vector<Vertex>& vertex) {
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
 * @brief      Generates a random initial solution
 *
 * @param      graph     The graph
 * @param      solution  The solution
 */
void MultiBootAlgorithm::initialRandomSolution (Graph& graph, std::vector<Vertex>& solution) {
	int node = getRandomVertex(graph.get_Vertex());
	solution.push_back(graph.get_Vertex()[node]);
	while (isInVector(node, solution)) {
		node = getRandomVertex(graph.get_Vertex());
	}
	solution.push_back(graph.get_Vertex()[node]);
}
