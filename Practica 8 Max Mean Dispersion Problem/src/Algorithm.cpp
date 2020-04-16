/*
* @Author: Adrián Epifanio
* @Date:   2020-04-16 16:48:59
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-16 18:43:52
*/

#include "../include/Algorithm.hpp"

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

std::vector<Vertex> Algorithm::get_Solution (void) const {
	return solutions_;
}

void Algorithm::set_Solution (std::vector<Vertex> solution) {
	std::cout << "TAMA" << solution.size();
	solutions_ = solution;
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
	mean /= vertex.size();
	std::cout << "\nmean:" << mean;
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