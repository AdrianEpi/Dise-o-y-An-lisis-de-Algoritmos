/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     tag.cpp                                            =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         14/02/2020                                         =
	=            Subject:       Diseño y Análisis de Algoritmos                    =
	=            Language:      C++                                                =
	=            Email:         alu0101158280@ull.edu.es                           =
	=            Place:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=====================================================================================
===================================================================================*/
/*
* @Author: adria
* @Date:   2020-02-14 14:53:48
* @Last Modified by:   adria
* @Last Modified time: 2020-02-15 12:18:38
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/tag.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  namename   The namename
 * @param[in]  pos   The position
 */
Tag::Tag(std::string namename, int pos)
{
	set_Name(namename);
	set_Pos(pos);
}

/**
 * @brief      Gets the name.
 *
 * @return     The name.
 */
std::string Tag::get_Name(void)
{
	return name_;
}

/**
 * @brief      Gets the position.
 *
 * @return     The position.
 */
int Tag::get_Pos(void)
{
	return pos_;
}

/**
 * @brief      Sets the name.
 *
 * @param[in]  name   The new value
 */
void Tag::set_Name(std::string name)
{
	name_ = name; 
}

/**
 * @brief      Sets the position.
 *
 * @param[in]  pos   The new value
 */
void Tag::set_Pos(int pos)
{
	pos_ = pos; 
}