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
* @Last Modified time: 2020-05-06 18:06:30
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
 * @brief      Gets the maximum mean.
 *
 * @return     The maximum mean.
 */
float Algorithm::get_MaxMean (void) const {
	return maxMean_;
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
 * @brief      Sets the maximum mean.
 *
 * @param[in]  maxMean  The maximum mean
 */
void Algorithm::set_MaxMean (float maxMean) {
	maxMean_ = maxMean;
}

/**
 * @brief      Runs the code
 *
 * @param      graph  The graph
 */
void Algorithm::runAlgorithm (Graph& graph, Chrono& chrono) {
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
                tmp += pow((vertex[i].get_Coordinates()[k] - vertex[j].get_Coordinates[k]), 2);
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
std::vector<float> Algorithm::generateGravityCenter (std::vector<Vertex>& vertex) {
    std::vector<float> gravityCenter;
    gravityCenter.resize(vertex.get_Coordinates().size());
    for (int i = 0; i < vertex.get_Coordinates().size(); i++) {
        gravityCenter[i] = 0;
        for (int j = 0; j < vertex.size(); j++) {
            gravityCenter[i] += vertex[j].get_Coordinates()[i];
        }
        gravityCenter[i] /= vertex.size();
    }
    return gravityCenter;
}