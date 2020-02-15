/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     registers.cpp                                      =
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
* @Date:   2020-02-14 14:53:40
* @Last Modified by:   adria
* @Last Modified time: 2020-02-15 10:54:47
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/registers.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Registers::Registers(void)
{
	initialize();
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  registers  The registers
 */
Registers::Registers(std::vector<int> registers)
{
	set_Registers(registers);
}

/**
 * @brief      Gets the registers.
 *
 * @return     The registers.
 */
std::vector<int> Registers::get_Registers(void)
{
	return registers_;
}

/**
 * @brief      Sets the registers.
 *
 * @param[in]  registers  The registers
 */
void Registers::set_Registers(std::vector<int> registers)
{
	registers_ = registers_;
}

/**
 * @brief      Initializes the object.
 */
void Registers::initialize(void)
{
	// Create the vector with MAX_REGISTERS registers and all initialized to 0;
	registers_ = std::vector<int>(MAX_REGISTERS, 0);
}

/**
 * @brief      Edit the data of an specific register
 *
 * @param[in]  data    The data
 * @param[in]  number  The number
 */
void Registers::set_SpecificRegister(int data, int number)
{
	assert(number > 0 && number < MAX_REGISTERS);
	registers_[number] = data;
}

/**
 * @brief      Edit the data of the Accumulator (R[0])
 *
 * @param[in]  data  The data
 */
void Registers::set_Accumulator(int data)
{
	registers_[0] = data;
}

/**
 * @brief      Reads a register.
 *
 * @param[in]  number  The number
 *
 * @return     Data of an specific register
 */
int Registers::get_SpecificRegister(int number)
{
	return registers_[number];
}

/**
 * @brief      Reads an accumulator.
 *
 * @return     Data of accumulator (R[0])
 */
int Registers::get_Accumulator(void)
{
	return registers_[0];
}

/**
 * @brief      Prints by console all the registers with their data
 */
void Registers:: write(void)
{
	std::cout << "Accumulator -> R[0]" << std::endl;
	for(int i = 0; i < MAX_REGISTERS; i++)
		std::cout << "R[" << i << "] = " << registers_[i] << std::endl; 
}
