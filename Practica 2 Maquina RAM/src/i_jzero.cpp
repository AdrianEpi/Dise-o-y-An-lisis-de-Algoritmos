/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_jzero.cpp                                        =
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
* @Author: Adrián Epifanio
* @Date:   2020-02-18 12:38:49
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 20:26:08
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_jzero.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct         The instruct
 * @param      tag_reg          The tag register
 * @param      program_counter  The program counter
 */
I_Jzero::I_Jzero(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter)
{
	runProcess(instruct, tag_reg, reg, program_counter);
}

/**
 * @brief      Jumps to the tag ig accumulator is == 0
 *
 * @param      instruct         The instruct
 * @param      tag_reg          The tag register
 * @param      reg              The register
 * @param      program_counter  The program counter
 */
void I_Jzero::runProcess(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter)
{
	if(reg.get_Accumulator() == 0)
	{
		if(tag_reg.findPos(instruct.get_Operand()) >= 0)
			program_counter = tag_reg.findPos(instruct.get_Operand()) - 1;
		else
		{
			std::cout << "Error while JUMP, not tag defined." << std::endl;
			exit(0);
		}
	}
}




