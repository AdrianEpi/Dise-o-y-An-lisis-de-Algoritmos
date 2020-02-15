/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     tagRegister.cpp                                    =
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
* @Date:   2020-02-15 11:17:46
* @Last Modified by:   adria
* @Last Modified time: 2020-02-15 11:33:41
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/tagRegister.hpp"

/*------------------------------------------------*/


/**
 * @brief      Gets the tags.
 *
 * @return     The tags.
 */
std::vector<Tag> TagRegister::get_Tags(void)
{
	return tags_;
}

/**
 * @brief      Sets the tags.
 *
 * @param[in]  tags  The tags
 */
void TagRegister::set_Tags(std::vector<Tag> tags)
{
	tags_ = tags;
}

/**
 * @brief      Finds a position.
 *
 * @param[in]  name  The name
 *
 * @return     The position if it's found or -1 if it's not
 */
int TagRegister::findPos(std::string name)
{
	for(int i = 0; i < tags_.size(); i++)
		if(tags_[i].get_Name() == name)
			return tags_[i].get_Pos();
	return -1;
}

/**
 * @brief      Add a new tag to the vector
 *
 * @param[in]  name  The name
 * @param[in]  pos   The position
 */
void TagRegister::insertTag(std::string name, int pos)
{
	Tag aux(name, pos);
	tags_.push_back(aux);
}

/**
 * @brief      Prints the tags by console
 */
void TagRegister::write(void)
{
	std::cout << "Tags: " << std::endl;
	for(int i = 0; i < tags_.size(); i++)
		std::cout << tags[i].get_Name() << ": " << tags_.get_Pos() << std::endl;;
}