/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     inputTape.cpp                                      =
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
* @Date:   2020-02-14 14:53:26
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 19:12:31
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/inputTape.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
InputTape::InputTape()
{
	initialize();
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  tape      The tape
 * @param[in]  filename  The filename
 */
InputTape::InputTape(std::vector<int> tape, std::string filename)
{
	initialize();
	set_tape(tape);
	set_filename(filename);
}

/**
 * @brief      Gets the head.
 *
 * @return     The head.
 */
unsigned InputTape::get_head(void)
{
	return head_;
}

/**
 * @brief      Gets the tape.
 *
 * @return     The tape.
 */
std::vector<int> InputTape::get_tape(void)
{
	return tape_;
}

/**
 * @brief      Gets the filename.
 *
 * @return     The filename.
 */
std::string InputTape::get_filename(void)
{
	return filename_;
}

/**
 * @brief      Sets the head.
 *
 * @param[in]  head  The head
 */
void InputTape::set_head(unsigned head)
{
	head_ = head;
}

/**
 * @brief      Sets the tape.
 *
 * @param[in]  tape  The tape
 */
void InputTape::set_tape(std::vector<int> tape)
{
	tape_ = tape;
}

/**
 * @brief      Sets the filename.
 *
 * @param[in]  filename  The filename
 */
void InputTape::set_filename(std::string filename)
{
	filename_ = filename;
}

/**
 * @brief      Initializes the object.
 */
void InputTape::initialize(void)
{
	tape_.clear();
	head_ = 0;
}

/**
 * @brief      Loads the input tape from a file
 *
 * @param[in]  filename  The filename
 */
void InputTape::load(std::string filename)
{
	set_filename(filename);
	int data;
	tape_.resize(0);
	std::ifstream file(filename.c_str());
	if(file.is_open())
	{
		while(!file.eof())
		{
			file >> data;
			tape_.push_back(data);
		}
		file.close();	
	}
	else
	{
		std::cout << "Error loading the input tape" << std::endl;
		exit(0);
	}
}

/**
 * @brief      Reads an element from the tape and increases the head
 *
 * @return     Increased tape with the new head
 */
int InputTape::read(void)
{
	if(head_ < tape_.size())
		return tape_[head_++];
	else
	{
		std::cout << "Error reading the input tape (overflow)" << std::endl;
		exit(0);
	}
}

/**
 * @brief      Prints the input tapy by console
 */
void InputTape::write(void)
{
	if(tape_.size() == 0)
		std::cout << "Empty tape" << std::endl;
	else
		for(int i = 0; i < tape_.size(); i++)
			std::cout << "InputTape[" << i << "] -> " << tape_[i] << std::endl;
}