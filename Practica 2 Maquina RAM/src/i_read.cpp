/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_read.cpp                                         =
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
* @Date:   2020-02-18 12:38:24
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-22 12:13:06
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_read.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct    The instruct
 * @param      reg         The register
 * @param      input_tape  The input tape
 */
I_Read::I_Read(Instruction& instruct, Registers& reg, InputTape& input_tape)
{
	runProcess(instruct, reg, input_tape);
}

/**
 * @brief      Reads data from the imput tape and saves it on a register.
 *
 * @param      instruct    The instructions
 * @param      reg         The registers
 * @param      input_tape  The input tape
 */
void I_Read::runProcess(Instruction& instruct, Registers& reg, InputTape& input_tape)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			std::cout << std::endl << "Error, mode INMEDIATO not allowed in READ" << std::endl;
			exit(0);
			break;
			
		case instruct.DIRECTO:
			reg.set_SpecificRegister(input_tape.read(), instruct.get_Operand());
			break;

		case instruct.INDIRECTO:
			reg.set_SpecificRegister(input_tape.read(), reg.get_SpecificRegister(instruct.get_Operand()));
			break;
	}
}




