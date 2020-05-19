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
* @Last Modified time: 2020-05-19 09:56:36
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
 * @brief      Constructs a new instance.
 *
 * @param[in]  strategy  The strategy
 */
BranchingAndPruningAlgorithm::BranchingAndPruningAlgorithm (int strategy) {
	set_Strategy(strategy);
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
	std::cout << std::endl << "Select the LowerBound ";
	float aux;
	std::cin >> aux;
	lowerBoundsVector_.resize(get_SolutionSize());
	upperBoundsVector_.resize(get_SolutionSize());	
	for (int i = 0; i < get_SolutionSize(); i++) {
		lowerBoundsVector_[i] = 0.0;
		upperBoundsVector_[i] = 0.0;
	}
	lowerBoundsVector_[get_SolutionSize() - 1] = aux;
	generatedNodes_ = 0;
	chrono.startChrono();
	set_PossibleVertex(graph.get_Vertex());
	set_LowerBound(aux);
	set_Strategy(1);
	std::vector<Vertex> initial;
	if (get_Strategy() == 1) {
		for (int i = 0; i < possibleVertex_.size(); i++) {
			expandNodeStrategy1(initial, i, 0.0);	
		}
	}
	else {
		expandNodeStrategy0(initial, 0);	
	}
	set_Solution(tmpSolution_);
	set_Diversity(findDiversity(tmpSolution_));
	chrono.stopChrono();
	std::cout << std::endl << "Generated nodes -> " << generatedNodes_ << std::endl;
}

/**
 * @brief      Expands the deepest node, strategy 1.
 *
 * @param[in]  tmp        The temporary solution
 * @param[in]  pos        The position
 * @param[in]  diversity  The diversity
 */
void BranchingAndPruningAlgorithm::expandNodeStrategy1 (std::vector<Vertex>& tmp, int pos, float diversity) {
	if ((tmp.size() > get_SolutionSize())) {
		return;
	}
	else if (tmp.size() < get_SolutionSize()){
		std::vector<Vertex> newTmp = tmp;
		newTmp.push_back(possibleVertex_[pos]);
		float newDiversity = findDiversity(newTmp);
		if (newDiversity >= diversity) {
			if (newDiversity >= lowerBoundsVector_[tmp.size() - 1]) {
				generatedNodes_++;
			}
			lowerBoundsVector_[tmp.size() - 1] = newDiversity;
			for (int i = pos; i < possibleVertex_.size(); i++) {
				expandNodeStrategy1(newTmp, i, newDiversity);
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

/**
 * @brief      Expands the node strategy 0.
 *
 * @param[in]  tmp   The temporary
 * @param[in]  pos   The position
 */
void BranchingAndPruningAlgorithm::expandNodeStrategy0 (std::vector<Vertex> tmp, int pos) {
	generatedNodes_++;
	if ((tmp.size() > get_SolutionSize())) {
		return;
	}
	else if (tmp.size() < get_SolutionSize()){
		if (hasbetterUpperBound(tmp, pos) == true) {
			tmp.push_back(possibleVertex_[pos]);
			expandNodeStrategy0(tmp, pos + 1);
		}
		expandNodeStrategy0(tmp, pos + 1);
	}
	else {
		float diversity  = findDiversity(tmp);
		if (isValidSolution(tmp) && (diversity >= get_LowerBound())) {
			set_LowerBound(diversity);
			set_TmpSolution(tmp);
		}
	}
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

/**
 * @brief      Searchs if the given vector has better UpperBound
 *
 * @param[in]  tmp   The temporary
 * @param[in]  pos   The position
 *
 * @return     True if it the tmp has better upperbound than the actual one, false otherwhise
 */
bool BranchingAndPruningAlgorithm::hasbetterUpperBound (std::vector<Vertex> tmp, int pos) {
	std::vector<Vertex> newTmp = tmp;
	for (int i = pos; i < possibleVertex_.size(); i++) {
		tmp.push_back(possibleVertex_[i]);
	}
	float tmpDiversity = findDiversity(tmp);
	for (int i = pos + 1; i < possibleVertex_.size(); i++) {
		newTmp.push_back(possibleVertex_[i]);
	}
	float newTmpDiversity = findDiversity(newTmp);
	if (tmpDiversity < newTmpDiversity) {
		if (tmpDiversity < get_UpperBound()) {
			set_UpperBound(tmpDiversity);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	} 
}


