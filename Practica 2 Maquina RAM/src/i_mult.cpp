/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_mult.cpp                                         =
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
* @Date:   2020-02-18 12:38:32
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 09:48:39
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_mult.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct  The instruct
 * @param      reg       The register
 */
I_Mult::I_Mult(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

/**
 * @brief      Mults data from a register and accumulator
 *
 * @param      instruct  The instructions
 * @param      reg       The registers
 */
void I_Mult::runProcess(Instruction& instruct, Registers& reg)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			reg.set_Accumulator(reg.get_Accumulator() * instruct.get_Operand());
	        break;

		case instruct.DIRECTO:
			reg.set_Accumulator(reg.get_Accumulator() * reg.get_SpecificRegister(instruct.get_Operand()));
			break;

		case instruct.INDIRECTO:
			reg.set_Accumulator(reg.get_Accumulator() * reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand())));
			break;
	}
}




