/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_store.cpp                                        =
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
* @Date:   2020-02-18 12:38:13
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-22 12:12:41
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_store.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct  The instruct
 * @param      reg       The register
 */
I_Store::I_Store(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

/**
 * @brief      Stores data on a register
 *
 * @param      instruct  The instructions
 * @param      reg       The registers
 */
void I_Store::runProcess(Instruction& instruct, Registers& reg)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			std::cout << std::endl << "Error, mode INMEDIATO not allowed in STORE" << std::endl;
			exit(0);
			break;
			
		case instruct.DIRECTO:
			reg.set_SpecificRegister(reg.get_Accumulator(), instruct.get_Operand());
			break;

		case instruct.INDIRECTO:
			reg.set_SpecificRegister(reg.get_Accumulator(), reg.get_SpecificRegister(instruct.get_Operand()));
			break;
	}
}

