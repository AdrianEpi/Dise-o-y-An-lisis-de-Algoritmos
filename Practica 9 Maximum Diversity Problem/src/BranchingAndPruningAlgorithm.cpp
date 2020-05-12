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
* @Last Modified time: 2020-05-12 10:04:37
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
 * @brief      Gets the possible vertex.
 *
 * @return     The possible vertex.
 */
std::vector<Vertex> BranchingAndPruningAlgorithm::get_PossibleVertex (void) const {
	return possibleVertex_;
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
 * @brief      Sets the possible vertex.
 *
 * @param[in]  possibilities  The possibilities
 */
void BranchingAndPruningAlgorithm::set_PossibleVertex (std::vector<Vertex> possibilities) {
	possibleVertex_ = possibilities;
}

/**
 * @brief      Executes the BranchingAndPruning algorithm
 *
 * @param      graph  The graph
 */
void BranchingAndPruningAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	set_PossibleVertex(graph.get_Vertex());
	set_LowerBound(0);
	std::vector<Vertex> initial;
	if (get_Strategy() == 1) {
		for (int i = 0; i < possibleVertex_.size(); i++) {
			expandNodeStrategy1(initial, i, 0.0);	
		}
	}
	else {
		expandNodeStrategy0(initial, i, 0.0);	
	}
	set_Solution(tmpSolution_);
	set_Diversity(findDiversity(tmpSolution_));
	chrono.stopChrono();
}

/**
 * @brief      Expands the deepest node, strategy 1.
 *
 * @param[in]  tmp        The temporary solution
 * @param[in]  pos        The position
 * @param[in]  diversity  The diversity
 */
void BranchingAndPruningAlgorithm::expandNodeStrategy1 (std::vector<Vertex> tmp, int pos, float diversity) {
	if ((tmp.size() > get_SolutionSize())) {
		return;
	}
	else if (tmp.size() < get_SolutionSize()){
		std::vector<Vertex> newTmp = tmp;
		newTmp.push_back(possibleVertex_[pos]);
		float newDiversity = findDiversity(newTmp);
		if (newDiversity >= diversity) {
			for (int i = pos; i < possibleVertex_.size(); i++) {
				expandNode(newTmp, i, newDiversity);
			}
		}
	}
	else {
		if (isValidSolution(tmp) && (diversity >= get_LowerBound())) {
			set_LowerBound(diversity);
			set_TmpSolution(tmp);
		}
	}
}

void BranchingAndPruningAlgorithm::expandNodeStrategy0 (std::vector<Vertex> tmp, int pos, float diversity) {

}

/**
 * @brief      Determines whether the specified temporary solution is a valid solution or not.
 *
 * @param      tmp   The temporary
 *
 * @return     True if the specified temporary is valid solution, False otherwise.
 */
bool BranchingAndPruningAlgorithm::isValidSolution (std::vector<Vertex>& tmp) {
	for (int i = 0; i < (tmp.size() - 1); i++) {
		int aux = tmp[i].get_Number();
		for (int j = (i + 1); j < tmp.size(); j++) {
			if (tmp[j].get_Number() == aux) {
				return false;
			}
		}
	}
	return true;
}




