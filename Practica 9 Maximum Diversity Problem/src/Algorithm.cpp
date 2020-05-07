/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 9 Maximum Diversity                       =
	=            File name:     Algorithm.cpp                                      =
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
* @Date:   2020-04-16 16:48:59
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-07 17:43:26
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
 * @brief      Gets the diversity.
 *
 * @return     The diversity.
 */
float Algorithm::get_Diversity (void) const {
	return diversity_;
}

/**
 * @brief      Gets the solution size.
 *
 * @return     The solution size.
 */
int Algorithm::get_SolutionSize (void) const {
	return solutionSize_;
}

/**
 * @brief      Gets the free vertex vector.
 *
 * @return     The free vertex.
 */
std::vector<Vertex>& Algorithm::get_FreeVertex (void) {
	return freeVertex_;
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
 * @brief      Sets the diversity.
 *
 * @param[in]  diversity  The diversity
 */
void Algorithm::set_Diversity (float diversity) {
	diversity_ = diversity;
}

/**
 * @brief      Sets the free vertex vector.
 *
 * @param[in]  freeVertex  The free vertex
 */
void Algorithm::set_FreeVertex (std::vector<Vertex> freeVertex) {
	freeVertex_.clear();
	freeVertex_.resize(freeVertex.size());
	for (int i = 0; i < freeVertex.size(); i++) {
		freeVertex_[i] = freeVertex[i];
	}
}

/**
 * @brief      Sets the solution size.
 *
 * @param[in]  size  The size
 */
void Algorithm::set_SolutionSize (int size) {
	solutionSize_ = size;
}

/**
 * @brief      Runs the code
 *
 * @param      graph  The graph
 */
void Algorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
} 

std::ostream& Algorithm::printResult (std::ostream& os, Chrono& chrono) {
	assert(get_Solution().size() > 0);
	os << std::endl << "CPU Time: " << chrono.get_Seconds(5) << " seconds";
	os << std::endl << "Solution: { ";
	for (int i = 0; i < get_Solution().size() - 1; i++) {
		os << get_Solution()[i].get_Number() << ", ";
	}
	os << get_Solution()[get_Solution().size() - 1].get_Number() << " }" << std::endl;
	os << "Diversity value: " << get_Diversity() << std::endl;
	return os;
}

/**
 * @brief      Finds the diversity of a given vector of vertex.
 *
 * @param      vertex  The vertex
 *
 * @return     The diversity
 */
float Algorithm::findDiversity (std::vector<Vertex>& vertex) {
	float diversity = 0.0;
	for (int i = 0; i < (vertex.size() - 1); i++) {
		for (int j = i + 1; j < vertex.size(); j++) {
			float tmp;
			for (int k = 0; k < vertex[0].get_Coordinates().size(); k++) {
				tmp += pow((vertex[i].get_Coordinates()[k] - vertex[j].get_Coordinates()[k]), 2);
			}
			diversity += tmp;
		}
	}
	diversity = sqrt(diversity);
	return diversity;
}

/**
 * @brief      Calculates and generates the gravity center of a given vertex vector.
 *
 * @param      vertex  The vertex
 *
 * @return     The vector with the gravity center
 */
Vertex Algorithm::generateGravityCenter (std::vector<Vertex>& vertex) {
	std::vector<float> gravityCenter;
    gravityCenter.resize(vertex[0].get_Coordinates().size());
    for (int i = 0; i < gravityCenter.size(); i++) {
        gravityCenter[i] = 0;
        for (int j = 0; j < vertex.size(); j++) {
            gravityCenter[i] += vertex[j].get_Coordinates()[i];
        }
        gravityCenter[i] /= vertex.size();
    }
    Vertex gravity;
    for (int i = 0; i < gravityCenter.size(); i++) {
    	gravity.addCoordinate(gravityCenter[i]);
    }
	return gravity;
}

/**
 * @brief      Finds the furthest vertex from the gravity center.
 *
 * @param      vertex         The vertex
 * @param      gravityCenter  The gravity center
 *
 * @return     The number of the vertex
 */
int Algorithm::findFurthestFromGravityCenter (std::vector<Vertex>& vertex, Vertex& gravityCenter) {
	int number = 0;
	float diversity_ = STARTMEAN;
	for (int i = 0; i < vertex.size(); i++) {
		std::vector<Vertex> tmp;
		tmp.resize(2);
		tmp[0] = gravityCenter;
		tmp[1] = vertex[i];
		float diversity = findDiversity(tmp);
		if (diversity_ < diversity) {
			number = i;
			diversity_ = diversity;
		}
	}
	return number;
}