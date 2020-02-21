/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_sub.cpp                                          =
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
* @Date:   2020-02-18 12:38:00
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 09:59:49
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_sub.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct  The instruct
 * @param      reg       The register
 */
I_Sub::I_Sub(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

/**
 * @brief      Subs data from a register and accumulator
 *
 * @param      instruct  The instructions
 * @param      reg       The registers
 */
void I_Sub::runProcess(Instruction& instruct, Registers& reg)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
		std::cout << std::endl << "Restainm: " << reg.get_Accumulator() << " - " << instruct.get_Operand();
			reg.set_Accumulator(reg.get_Accumulator() - instruct.get_Operand());
	        break;

		case instruct.DIRECTO:
		std::cout << std::endl << "Restadir: " << reg.get_Accumulator() << " - " << reg.get_SpecificRegister(instruct.get_Operand());
			reg.set_Accumulator(reg.get_Accumulator() - reg.get_SpecificRegister(instruct.get_Operand()));
			break;

		case instruct.INDIRECTO:
				std::cout << std::endl << "Restaindir: " << reg.get_Accumulator() << " - " << reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand()));
			reg.set_Accumulator(reg.get_Accumulator() - reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand())));
			break;
	}
}



