/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_add.cpp                                          =
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
* @Date:   2020-02-18 12:37:41
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 09:42:30
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_add.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct  The instruct
 * @param      reg       The register
 */
I_Add::I_Add(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

/**
 * @brief      Adds data from a register and accumulator
 *
 * @param      instruct  The instructions
 * @param      reg       The registers
 */
void I_Add::runProcess(Instruction& instruct, Registers& reg)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			reg.set_Accumulator(reg.get_Accumulator() + instruct.get_Operand());
	        break;

		case instruct.DIRECTO:
			reg.set_Accumulator(reg.get_Accumulator() + reg.get_SpecificRegister(instruct.get_Operand()));
			break;

		case instruct.INDIRECTO:
			reg.set_Accumulator(reg.get_Accumulator() + reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand())));
			break;
	}
}


