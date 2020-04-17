/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     vertex.cpp                                         =
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
* @Date:   2020-04-15 19:34:52
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-17 17:58:07
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/vertex.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Vertex::Vertex () {
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  number  The number
 */
Vertex::Vertex (int number) {
	assert(number >= 0);
	set_Number(number);
	generateName();
}

/**
 * @brief      Destroys the object.
 */
Vertex::~Vertex () {
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
 * @brief      Assignment operator.
 *
 * @param[in]  vertex  The vertex
 */
void Vertex::operator= (const Vertex& vertex) {
    set_Name(vertex.get_Name());
    set_Number(vertex.get_Number());
} 

/**
 * @brief      Generates the name for the vertex
 */
void Vertex::generateName (void) {
	std::string name = "Vertex ";
	name += std::to_string(get_Number());
	set_Name(name);
}
