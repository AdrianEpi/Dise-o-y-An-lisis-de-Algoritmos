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
* @Date:   2020-02-18 12:37:52
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-21 19:33:43
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_write.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 *
 * @param      instruct     The instruct
 * @param      reg          The register
 * @param      output_tape  The input tape
 */
I_Write::I_Write(Instruction& instruct, Registers& reg, OutputTape& output_tape)
{
	runProcess(instruct, reg, output_tape);
}

/**
 * @brief      Writes data from the imput tape and saves it on a register.
 *
 * @param      instruct     The instructions
 * @param      reg          The registers
 * @param      output_tape  The input tape
 */
void I_Write::runProcess(Instruction& instruct, Registers& reg, OutputTape& output_tape)
{
	switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			output_tape.add_Data(instruct.get_Operand());
			break;

		case instruct.DIRECTO:
			output_tape.add_Data(reg.get_SpecificRegister(instruct.get_Operand()));
			break;

		case instruct.INDIRECTO:
			output_tape.add_Data(reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand())));
			break;
	}
}





