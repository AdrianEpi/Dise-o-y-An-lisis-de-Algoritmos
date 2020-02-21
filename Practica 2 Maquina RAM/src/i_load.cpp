/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_load.cpp                                         =
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
* @Date:   2020-02-18 12:38:41
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 09:12:49
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_load.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct  The instruct
 * @param      reg       The register
 */
I_Load::I_Load(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

/**
 * @brief      Load data in the accumulator
 *
 * @param      instruct  The instructions
 * @param      reg       The registers
 */
void I_Load::runProcess(Instruction& instruct, Registers& reg)
{
	int aux;
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			aux = instruct.get_Operand();
			reg.set_Accumulator(aux);
			break;

		case instruct.DIRECTO:
			aux = reg.get_SpecificRegister(instruct.get_Operand());
			reg.set_Accumulator(aux);
			break;

		case instruct.INDIRECTO:
			aux = reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand()));
			reg.set_Accumulator(aux);
	}
}


