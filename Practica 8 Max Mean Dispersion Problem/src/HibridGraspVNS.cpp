/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     HibridGraspVNS.cpp                                   =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         17/04/2020                                         =
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
* @Date:   2020-04-24 11:51:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-28 12:39:49
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/HibridGraspVNS.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
HibridGraspVNS::HibridGraspVNS () {
}

/**
 * @brief      Destroys the object.
 */
HibridGraspVNS::~HibridGraspVNS () {
}

/**
 * @brief      Executes the VNS algorithm
 *
 * @param      graph  The graph
 */
void HibridGraspVNS::runAlgorithm (Graph& graph, Chrono& chrono) {
	int counterLoops = 0, structureSize = 1;
	std::vector<Vertex> solution, graspSolution;
	GraspAlgorithm initalGrasp;
	Chrono tmp;
	initalGrasp.runAlgorithm(graph, tmp);
	chrono.startChrono();
	solution = initalGrasp.get_Solution();
	graspSolution = solution;
	assert(solution.size() >= 3);
	float mean = findMean(solution, graph);
	while (counterLoops < 5) {
		structureSize = 1;
		std::vector<Vertex> tmpSolution = solution;
		while (structureSize != 4) {
			std::vector<Vertex> possibilities;
			genertePossiblesChanges(possibilities, tmpSolution, graph);
			structures(possibilities, tmpSolution, structureSize);
			float tmpMean = findMean(tmpSolution, graph);
			if (tmpMean > mean) {
				solution = tmpSolution;
				mean = tmpMean;
			}
			structureSize++;
		}
		counterLoops++;
	}

	if (findMean(graspSolution, graph) > findMean(solution, graph)) {
		set_Solution(graspSolution);
	}
	else {
		set_Solution(solution);
	}
	set_MaxMean(mean);
	chrono.stopChrono();
}

/**
 * @brief      Generates the vector with all the possibles vertex without being in solution.
 *
 * @param      possibilities  The possibilities
 * @param      solution       The solution
 * @param      graph          The graph
 */
void HibridGraspVNS::genertePossiblesChanges (std::vector<Vertex>& possibilities, std::vector<Vertex>& solution, Graph& graph) {
	for (int vertexCounter = 0; vertexCounter < graph.get_Vertex().size(); vertexCounter++) {
		if (isInVector(vertexCounter, solution) == false) {
			possibilities.push_back(graph.get_Vertex()[vertexCounter]);

		}
	}
}

/**
 * @brief      Swaps vertex from the solution with the possible vertex vector for searching a better solution
 *
 * @param      possibilities  The possibilities
 * @param      tmpSolution    The temporary solution
 * @param      swapsNum       The swaps number
 */
void HibridGraspVNS::structures (std::vector<Vertex>& possibilities, std::vector<Vertex>& tmpSolution, int& swapsNum) {
	int vertexVector1, vertexVector2;
	switch (swapsNum) {
		case 1:
			vertexVector1 = getRandomPosition(tmpSolution);
			possibilities.push_back(tmpSolution[vertexVector1]);
			tmpSolution.erase(tmpSolution.begin() + vertexVector1);
			break;

		case 2:
			vertexVector2 = getRandomPosition(possibilities);
			tmpSolution.push_back(possibilities[vertexVector2]);
			possibilities.erase(possibilities.begin() + vertexVector2);
			break;

		case 3:
			vertexVector1 = getRandomPosition(tmpSolution);
			vertexVector2 = getRandomPosition(possibilities);
			tmpSolution.erase(tmpSolution.begin() + vertexVector1);
			tmpSolution.push_back(possibilities[vertexVector2]);
			possibilities.erase(possibilities.begin() + vertexVector2);
			break;
	}
	/*for (int counter = 0; counter < swapsNum && counter < possibilities.size() && counter < tmpSolution.size(); counter++) {
		int vertexVector1 = getRandomPosition(tmpSolution);
		int vertexVector2 = getRandomPosition(possibilities);
		tmpSolution.erase(tmpSolution.begin() + vertexVector1);
		tmpSolution.push_back(possibilities[vertexVector2]);
		possibilities.erase(possibilities.begin() + vertexVector2);
	}*/
}
