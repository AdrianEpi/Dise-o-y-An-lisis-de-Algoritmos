/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     vertex.cpp                                         =
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
* @Date:   2020-04-15 19:34:52
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-06 19:17:48
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/vertex.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Vertex::Vertex () {
    coordinates_.resize(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  number  The number
 */ 
Vertex::Vertex (int number) {
	assert(number >= 0);
	set_Number(number);
    coordinates_.resize(0);
	generateName();
}

/**
 * @brief      Destroys the object.
 */
Vertex::~Vertex () {
    coordinates_.resize(0);
}

/**
 * @brief      Gets the number.
 *
 * @return     The number.
 */
int Vertex::get_Number (void) const {
	return number_;
}

/**
 * @brief      Gets the name.
 *
 * @return     The name.
 */
std::string Vertex::get_Name (void) const {
	return name_;
}

/**
 * @brief      Gets the coordinates.
 *
 * @return     The coordinates.
 */
std::vector<float> Vertex::get_Coordinates (void) const {
    return coordinates_;
}

/**
 * @brief      Sets the number.
 *
 * @param[in]  number  The number
 */
void Vertex::set_Number (int number) {
	number_ = number;
}

/**
 * @brief      Sets the name.
 *
 * @param[in]  name  The name
 */
void Vertex::set_Name (std::string name) {
	name_ = name;
}

/**
 * @brief      Sets the coordinates.
 *
 * @param[in]  coordinates  The coordinates
 */
void Vertex::set_Coordinates (std::vector<float> coordinates) {
    coordinates_.clear();
    coordinates_.resize(coordinates.size());
    for (int i = 0; i < coordinates.size(); i++) {
        coordinates_[i] = coordinates[i];
    }
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  vertex  The vertex
 */
void Vertex::operator= (const Vertex& vertex) {
    set_Name(vertex.get_Name());
    set_Number(vertex.get_Number());
    set_Coordinates(vertex.get_Coordinates());
} 

/**
 * @brief      Generates the name for the vertex
 */
void Vertex::generateName (void) {
	std::string name = "Vertex ";
	name += std::to_string(get_Number());
	set_Name(name);
}

/**
 * @brief      Adds a coordinate to the coords vecctor.
 *
 * @param[in]  coordinate  The coordinate
 */
void Vertex::addCoordinate (float coordinate) {
    coordinates_.push_back(coordinate);
}

/**
 * @brief      Sets the coordinate.
 *
 * @param[in]  position  The position
 * @param[in]  number    The number
 */
void Vertex::setCoordinate(int position, float number) {
    coordinates_[position] = number;
}