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
* @Last Modified time: 2020-02-19 19:22:19
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/i_load.hpp"

/*------------------------------------------------*/
I_Load::I_Load(Instruction& instruct, Registers& reg)
{
	runProcess(instruct, reg);
}

void I_Load::runProcess(Instruction& instruct, Registers& reg)
{
	/*switch(instruct.get_AddressingMode())
	{
		case instruct.INMEDIATO:
			reg.set_Accumulator(instruct.get_Operand());
			break;

		case instruct.DIRECTO:
			reg.set_Accumulator(reg.get_SpecificRegister(instruct.get_Operand()));
			break;

		case instruct.INDIRECTO:
			reg.set_Accumulator(reg.get_SpecificRegister(reg.get_SpecificRegister(instruct.get_Operand())));
	}*/
}


