/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     GraspAlgorithm.hpp                                 =
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
* @Author: Adrián Epifanio
* @Date:   2020-04-17 17:29:34
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-08 09:07:01
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GraspAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GraspAlgorithm::GraspAlgorithm () {
}

GraspAlgorithm::GraspAlgorithm (int RLC, int iterations) {
	set_RLC(RLC);
	set_Iterations(iterations);
}

/**
 * @brief      Destroys the object.
 */
GraspAlgorithm::~GraspAlgorithm () {
}

/**
 * @brief      Gets the rlc.
 *
 * @return     The rlc.
 */
int GraspAlgorithm::get_RLC (void) const {
	return RLC_;
}

/**
 * @brief      Gets the iterations.
 *
 * @return     The iterations.
 */
int GraspAlgorithm::get_Iterations (void) const {
	return iterations_;
}

/**
 * @brief      Sets the rlc.
 *
 * @param[in]  RLC   The new value
 */
void GraspAlgorithm::set_RLC (int RLC) {
	RLC_ = RLC;
}

/**
 * @brief      Sets the iterations.
 *
 * @param[in]  iterations  The iterations
 */
void GraspAlgorithm::set_Iterations (int iterations) {
	iterations_ = iterations;
}


/**
 * @brief      Executes the Grasp algorithm
 *
 * @param      graph  The graph
 */
void GraspAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	set_FreeVertex(graph.get_Vertex());
	// Constructive Part
	do {
		int candidate = getRandomVertex(get_FreeVertex());
		addition(solution, candidate);
	} while (solution.size() < get_SolutionSize());
	// Improve Part
	int counter = 0;
	float diversity = findDiversity(solution);
	do {
		std::vector<Vertex> tempSolution = solution;
		std::vector<Vertex> RLCvector;
		generateRLC(RLCvector, tempSolution);
		int candidateIntroduce = getRandomVertex(RLCvector);
		int candidateExtract = getRandomVertex(tempSolution);
		// TMP Swap
		tempSolution.erase(tempSolution.begin() + candidateExtract);
		tempSolution.push_back(RLCvector[candidateIntroduce]);
		float tmpDiversity = findDiversity(tempSolution);
		if (tmpDiversity > diversity) {
			int pos = getPositionFromVector(get_FreeVertex(), RLCvector[candidateIntroduce].get_Number());
			if (pos != -1) {
				diversity = tmpDiversity;
				swap(solution, candidateExtract, pos);
			}
		}
		counter++;
	} while (counter < get_Iterations());
	set_Solution(solution);
	set_Diversity(findDiversity(solution));
	chrono.stopChrono();
}

/**
 * @brief      Generates the Random List of Candidates
 *
 * @param      RLC       The rlc
 * @param[in]  solution  The solution
 */
void GraspAlgorithm::generateRLC(std::vector<Vertex>& RLC, std::vector<Vertex>& solution) {
	std::vector<Vertex> tempSolution;
	std::vector<float> diversities;
	int diversity = findDiversity(solution);
	for (int i = 0; i < get_FreeVertex().size(); i++) {
		std::vector<Vertex> tmp = solution;
		tmp.push_back(get_FreeVertex()[i]);
		int tmpDiversity = findDiversity(tmp);
		if (tmpDiversity > diversity) {
			tempSolution.push_back(get_FreeVertex()[i]);
			diversities.push_back(tmpDiversity);
		}
	}
	while (tempSolution.size() >= get_RLC()) {
		int pos = 0;
		float min = diversities[0];
		for (int i = 1; i < tempSolution.size(); i++) {
			if (diversities[i] < min) {
				min = diversities[i];
				pos = i;
			}
		}
		tempSolution.erase(tempSolution.begin() + pos);
	}
	RLC = tempSolution;
}

