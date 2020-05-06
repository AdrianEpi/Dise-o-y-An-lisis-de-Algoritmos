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
* @Last Modified time: 2020-05-06 17:26:10
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

