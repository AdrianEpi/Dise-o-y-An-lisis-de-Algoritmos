/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     outputTape.cpp                                     =
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
* @Date:   2020-02-14 09:44:03
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-17 15:50:38
*/

/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/outputTape.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
OutputTape::OutputTape()
{
	initialize();
}

/**
 * @brief      Gets the tape.
 *
 * @return     The tape.
 */
std::vector<int> OutputTape::get_tape(void)
{
	return tape_;
}

/**
 * @brief      Sets the tape.
 *
 * @param[in]  tape  The tape
 */
void OutputTape::set_tape(std::vector<int> tape)
{
	tape_ = tape;
}

/**
 * @brief      Initializes the object.
 */
void OutputTape::initialize(void)
{
	tape_.clear();
}

/**
 * @brief      Loads the tape of an existing file, most not used for the output but just in case its needed to modify or add something to an existing tape
 *
 * @param[in]  filename  The filename
 */
void OutputTape::load(std::string filename)
{
	int data;
	std::ifstream file(filename.c_str());
	tape_.resize(0);
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
 * @brief      Prints by console the output tape
 */
void OutputTape::write(void)
{
	if(tape_.size() == 0)
		std::cout << "Empty tape" << std::endl;
	else
		for(int i = 0; i < tape_.size(); i++)
			std::cout << "OutputTape[" << i << "] -> " << tape_[i] << std::endl;
}

/**
 * @brief      Sends the output tape to a file
 *
 * @param[in]  filename  The filename
 */
void OutputTape::write(std::string filename)
{
	std::ofstream file;
	file.open(filename.c_str());
	if(file.is_open())
	{
		for(int i = 0; i < tape_.size(); i++)
			file << tape_[i] << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error writing output tape on file" << std::endl;
		exit(0);
	}
}
