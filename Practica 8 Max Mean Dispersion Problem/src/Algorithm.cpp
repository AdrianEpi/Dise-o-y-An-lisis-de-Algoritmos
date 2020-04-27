/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     Algorithm.cpp                                      =
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
* @Date:   2020-04-16 16:48:59
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-27 08:05:50
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Algorithm.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Algorithm::Algorithm () {
}

/**
 * @brief      Destroys the object.
 */
Algorithm::~Algorithm () {
}

/**
 * @brief      Gets the solution.
 *
 * @return     The solution.
 */
std::vector<Vertex> Algorithm::get_Solution (void) const {
	return solutions_;
}

/**
 * @brief      Gets the maximum mean.
 *
 * @return     The maximum mean.
 */
float Algorithm::get_MaxMean (void) const {
	return maxMean_;
}

/**
 * @brief      Sets the solution.
 *
 * @param[in]  solution  The solution
 */
void Algorithm::set_Solution (std::vector<Vertex> solution) {
	solutions_ = solution;
}

/**
 * @brief      Sets the maximum mean.
 *
 * @param[in]  maxMean  The maximum mean
 */
void Algorithm::set_MaxMean (float maxMean) {
	maxMean_ = maxMean;
}

/**
 * @brief      Runs the code
 *
 * @param      graph  The graph
 */
void Algorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
}

/**
 * @brief      Prints a result.
 *
 * @param      os      The output stream
 * @param      chrono  The chrono
 *
 * @return     The output stream
 */
std::ostream& Algorithm::printResult (std::ostream& os, Chrono& chrono) {
	assert(get_Solution().size() > 0);
	os << std::endl << "CPU Time: " << chrono.get_Seconds(5) << " seconds";
	os << std::endl << "Solution: { ";
	for (int i = 0; i < get_Solution().size() - 1; i++) {
		os << get_Solution()[i].get_Number() << ", ";
	}
	os << get_Solution()[get_Solution().size() - 1].get_Number() << " }" << std::endl;
	os << "Max-Mean value: " << get_MaxMean() << std::endl;
	return os;
}

/**
 * @brief      Finds the distance mean of the given vertex.
 *
 * @param[in]  vertex  The vertex
 * @param      graph   The graph
 *
 * @return     The mean
 */
float Algorithm::findMean (std::vector<Vertex>& vertex, Graph& graph) {
	float mean = 0;
	if (vertex.size() == 0) {
		return 0.0;
	}
	for (int i = 0; i < vertex.size(); i++) {
		for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
			if (graph.get_Edges()[edge].get_VertexA() == vertex[i].get_Number()) {
				for (int j = i + 1; j < vertex.size(); j++) {
					if (vertex[j].get_Number() == graph.get_Edges()[edge].get_VertexB()) {
						mean += graph.get_Edges()[edge].get_Distance();
					}
				}
			}
		}
	}
	mean /= vertex.size();
	return mean;
}

/**
 * @brief      Adds a vertex to the solution vector.
 *
 * @param[in]  newVertex  The new vertex
 */
void Algorithm::addVertex (Vertex& newVertex) {
	solutions_.push_back(newVertex);
}

/**
 * @brief      Determines if a vertex is in vector.
 *
 * @param[in]  number  The number
 * @param[in]  vertex  The vertex
 *
 * @return     True if in vector, False otherwise.
 */
bool Algorithm::isInVector (int number, std::vector<Vertex>& vertex) {
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].get_Number() == number) {
			return true;
		}
	}
	return false;
}

/**
 * @brief      Gets a random vertex form the vector.
 *
 * @param[in]  vector   The vector
 *
 * @return     The random vertex.
 */
int Algorithm::getRandomVertex (std::vector<Vertex> vector) {
	if (vector.size() > 0) {
		int num = rand() % vector.size();
		return vector[num].get_Number();
	}
	else {
		return -1;
	}
}

/**
 * @brief      Gets a random position of the vector.
 *
 * @param[in]  vector  The vector
 *
 * @return     The random position.
 */
int Algorithm::getRandomPosition (std::vector<Vertex>& vector) {
	if (vector.size() > 0) {
		int num = rand() % vector.size();
		return num;
	}
	else {
		return -1;
	}
}

/**
 * @brief      Generates the initial solution of the algorithm by finding the best edge for start
 *
 * @param      graph   The graph
 * @param      vertex  The vertex
 */
void Algorithm::initialSolution (Graph& graph, std::vector<Vertex>& vertex) {
	int vertexNumberA = -1;
	int vertexNumberB = -1;
	int tempMaxMean = STARTMEAN;
	for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
		if (graph.get_Edges()[edge].get_Distance() > tempMaxMean) {
			tempMaxMean = graph.get_Edges()[edge].get_Distance();
			vertexNumberA = graph.get_Edges()[edge].get_VertexA();
			vertexNumberB = graph.get_Edges()[edge].get_VertexB();
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
void Algorithm::initialRandomSolution (Graph& graph, std::vector<Vertex>& solution) {
	int node = getRandomVertex(graph.get_Vertex());
	solution.push_back(graph.get_Vertex()[node]);
	while (isInVector(node, solution)) {
		node = getRandomVertex(graph.get_Vertex());
	}
	solution.push_back(graph.get_Vertex()[node]);
}