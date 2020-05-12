/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     BranchingAndPruningAlgorithm.cpp                   =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         06/05/2020                                         =
    =            Subject:       Diseño y Análisis de Algoritmos                    =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-05-12 08:08:12
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-12 08:21:21
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/BranchingAndPruningAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
BranchingAndPruningAlgorithm::BranchingAndPruningAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
BranchingAndPruningAlgorithm::~BranchingAndPruningAlgorithm () {
}

/**
 * @brief      Gets the upper bound.
 *
 * @return     The upper bound.
 */
float BranchingAndPruningAlgorithm::get_UpperBound (void) const {
	return upperBound_;
}

/**
 * @brief      Gets the lower bound.
 *
 * @return     The lower bound.
 */
float BranchingAndPruningAlgorithm::get_LowerBound (void) const {
	return lowerBound_;
}

/**
 * @brief      Gets the strategy.
 *
 * @return     The strategy.
 */
int BranchingAndPruningAlgorithm::get_Strategy (void) const {
	return strategy_;
}

/**
 * @brief      Gets the temporary solution.
 *
 * @return     The temporary solution.
 */
std::vector<Vertex> BranchingAndPruningAlgorithm::get_TmpSolution (void) const {
	return tmpSolution_;
}

/**
 * @brief      Sets the upper bound.
 *
 * @param[in]  bound  The bound
 */
void BranchingAndPruningAlgorithm::set_UpperBound (float bound) {
	upperBound_ = bound;
}

/**
 * @brief      Sets the lower bound.
 *
 * @param[in]  bound  The bound
 */
void BranchingAndPruningAlgorithm::set_LowerBound (float bound) {
	lowerBound_ = bound;
}

/**
 * @brief      Sets the strategy.
 *
 * @param[in]  strategy  The strategy
 */
void BranchingAndPruningAlgorithm::set_Strategy (int strategy) {
	strategy_ = strategy;
}

/**
 * @brief      Sets the temporary solution.
 *
 * @param[in]  tmp   The new value
 */
void BranchingAndPruningAlgorithm::set_TmpSolution (std::vector<Vertex> tmp) {
	tmpSolution_ = tmp;
}

/**
 * @brief      Executes the BranchingAndPruning algorithm
 *
 * @param      graph  The graph
 */
void BranchingAndPruningAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	set_FreeVertex(graph.get_Vertex());
	Vertex gravityCenter;
	gravityCenter = generateGravityCenter(get_FreeVertex());
	do {
		int candidate = findFurthestFromGravityCenter(get_FreeVertex(), gravityCenter);
		addition(solution, candidate);
		gravityCenter = generateGravityCenter(solution);
	} while (solution.size() < get_SolutionSize());
	set_Solution(solution);
	set_Diversity(findDiversity(solution));
	chrono.stopChrono();
}




