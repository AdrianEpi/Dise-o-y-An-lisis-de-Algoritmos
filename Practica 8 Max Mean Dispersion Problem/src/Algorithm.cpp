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
* @Last Modified time: 2020-04-17 13:30:04
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
 * @brief      { function_description }
 *
 * @param      graph  The graph
 */
void Algorithm::runAlgorithm (Graph& graph) {
}

/**
 * @brief      Prints a result.
 *
 * @param      os    The operating system
 *
 * @return     { description_of_the_return_value }
 */
std::ostream& Algorithm::printResult (std::ostream& os) {
}

/**
 * @brief      Finds the distance mean of the given vertex.
 *
 * @param[in]  vertex  The vertex
 * @param      graph   The graph
 *
 * @return     The mean
 */
float Algorithm::findMean (std::vector<Vertex> vertex, Graph& graph) {
	float mean = 0;
	for (int i = 0; i < vertex.size(); i++) {
		for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
			if (vertex[i].get_Number() == graph.get_Edges()[edge].get_VertexA()) {
				mean += graph.get_Edges()[edge].get_Distance();
			}
		}
	}
	mean /= ((graph.get_Vertex().size() -1)* vertex.size());
	return mean;
}

/**
 * @brief      Adds a vertex to the solution vector.
 *
 * @param[in]  newVertex  The new vertex
 */
void Algorithm::addVertex (Vertex newVertex) {
	solutions_.push_back(newVertex);
}