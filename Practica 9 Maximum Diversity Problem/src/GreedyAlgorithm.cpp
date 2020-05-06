/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     GreedyAlgorithm.cpp                                =
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
* @Date:   2020-04-03 20:29:34
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-06 19:25:40
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GreedyAlgorithm::GreedyAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
GreedyAlgorithm::~GreedyAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void GreedyAlgorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
	chrono.startChrono();
	std::vector<Vertex> solution;
	set_FreeVertex(graph.get_Vertex());
	Vertex gravityCenter;
	gravityCenter = generateGravityCenter(get_FreeVertex());
	do {
		int candidate = findFurthestFromGravityCenter(get_FreeVertex(), gravityCenter);
		solution.push_back(get_FreeVertex()[candidate]);
		get_FreeVertex().erase(get_FreeVertex().begin() + candidate);
		gravityCenter = generateGravityCenter(solution);
	} while (solution.size() < get_SolutionSize());
	set_Solution(solution);
	set_Diversity(findDiversity(solution));
	chrono.stopChrono();
}




