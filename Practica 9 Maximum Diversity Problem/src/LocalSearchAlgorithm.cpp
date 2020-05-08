/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     LocalSearchAlgorithm.cpp                           =
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
* @Date:   2020-05-08 09:15:21
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-08 09:59:37
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/LocalSearchAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
LocalSearchAlgorithm::LocalSearchAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
LocalSearchAlgorithm::~LocalSearchAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void LocalSearchAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	set_FreeVertex(graph.get_Vertex());
	// Initial fase
	for (int i = 0; i < get_SolutionSize(); i++) {
		addition(solution, i);
	}
	bool end = false;
	int counter = 0;
	float diversity = findDiversity(solution);
	// Improvement fase
	do {
		std::vector<Vertex> tmp = solution;
		bool changed = false;
		for (int i = 0; i < get_FreeVertex().size(); i++) {
			tmp.erase(tmp.begin() + counter);
			tmp.push_back(get_FreeVertex()[i]);
			float tmpDiversity = findDiversity(tmp);
			if (tmpDiversity > diversity) {
				diversity = tmpDiversity;
				swap(solution, counter, i);
				changed = true;
			}
		}
		if (changed == true) {
			counter = 0;
		}
		else {
			counter++;
			if (counter > get_SolutionSize()) {
				end = true;
			}
		}
	} while (end != true);
	set_Solution(solution);
	set_Diversity(findDiversity(solution));
	chrono.stopChrono();
}