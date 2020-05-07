/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     AnotherGreedyAlgorithm.hpp                         =
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
* @Date:   2020-04-17 09:29:34
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-07 18:58:19
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/AnotherGreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
AnotherGreedyAlgorithm::AnotherGreedyAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
AnotherGreedyAlgorithm::~AnotherGreedyAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void AnotherGreedyAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	set_FreeVertex(graph.get_Vertex());
	for (int i = 0; i < get_SolutionSize(); i++) {
		addition(solution, i);
	}
	float diversity = findDiversity(solution); 
	for (int i = 0; i < get_SolutionSize(); i++) {
		for (int j = 0; j < get_FreeVertex().size(); j++) {
			std::vector<Vertex> tmp = solution;
			tmp.erase(tmp.begin() + i);
			tmp.push_back(get_FreeVertex()[j]);
			float tmpDiversity = findDiversity(tmp);
			if (tmpDiversity > diversity) {
				swap(solution, i, j);
				diversity = tmpDiversity;
			}

		}
	}
	set_Solution(solution);
	set_Diversity(findDiversity(solution));
	chrono.stopChrono();
}