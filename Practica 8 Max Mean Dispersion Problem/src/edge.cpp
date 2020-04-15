/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     edge.cpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         03/04/2020                                         =
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
* @Date:   2020-04-15 19:20:56
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-15 21:19:27
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/edge.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Edge::Edge () {
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  vertexA     The vertex a
 * @param[in]  vertexB     The vertex b
 * @param[in]  distance  The distance
 */
Edge::Edge (int vertexA, int vertexB, int distance) {
	assert(vertexA >= 0 && vertexB >= 0);
	set_VertexA(vertexA);
	set_VertexB(vertexB);
	set_Distance(distance);
}

/**
 * @brief      Destroys the object.
 */
Edge::~Edge () {
}

/**
 * @brief      Gets the distance.
 *
 * @return     The distance.
 */
int Edge::get_Distance (void) const {
	return distance_;
}

/**
 * @brief      Gets the vertex a.
 *
 * @return     The vertex a.
 */
int Edge::get_VertexA (void) const {
	return vertexA_;
}

/**
 * @brief      Gets the vertex b.
 *
 * @return     The vertex b.
 */
int Edge::get_VertexB (void) const {
	return vertexB_;
}

/**
 * @brief      Sets the distance.
 *
 * @param[in]  distance  The distance
 */
void Edge::set_Distance (int distance) {
	distance_ = distance;
}

/**
 * @brief      Sets the vertex a.
 *
 * @param[in]  vertexA  The vertex a
 */
void Edge::set_VertexA (int vertexA) {
	vertexA_ = vertexA;
}

/**
 * @brief      Sets the vertex b.
 *
 * @param[in]  vertexB  The vertex b
 */
void Edge::set_VertexB (int vertexB) {
	vertexB_ = vertexB;
}
