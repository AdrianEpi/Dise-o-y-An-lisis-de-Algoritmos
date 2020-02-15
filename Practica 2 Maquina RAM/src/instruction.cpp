/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     instruction.cpp                                    =
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
* @Date:   2020-02-14 09:40:00
* @Last Modified by:   adria
* @Last Modified time: 2020-02-14 21:28:46
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/instruction.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Instruction::Instruction()
{
	initialize();
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  code  The code
 * @param[in]  line  The line
 */
Instruction::Instruction(int code, int line)
{
	initialize();
	set_OperationCode(code);
	set_LineNumber(line);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  code     The code
 * @param[in]  mode     The mode
 * @param[in]  line     The line
 * @param[in]  operand  The operand
 */
Instruction::Instruction(int code, int mode, int line, std::string operand)
{
	initialize();
	set_OperationCode(code);
	set_AddressingMode(mode);
	set_LineNumber(line);
}

/**
 * @brief      Gets the operation code.
 *
 * @return     The operation code.
 */
int Instruction::get_OperationCode(void)
{
	return operation_code_;
}

/**
 * @brief      Gets the addressing mode.
 *
 * @return     The addressing mode.
 */
int Instruction::get_AddressingMode(void)
{
	return addressing_mode_;
}

/**
 * @brief      Gets the line number.
 *
 * @return     The line number.
 */
int Instruction::get_LineNumber(void)
{
	return line_number_;
}

/**
 * @brief      Gets the operand.
 *
 * @return     The operand.
 */
std::string Instruction::get_Operand(void)
{
	return operand_;
}

/**
 * @brief      Sets the operation code.
 *
 * @param[in]  operation_code  The operation code
 */
void Instruction::set_OperationCode(int operation_code)
{
	operation_code_ = operation_code;
}

/**
 * @brief      Sets the addressing mode.
 *
 * @param[in]  addressing_mode  The addressing mode
 */
void Instruction::set_AddressingMode(int addressing_mode)
{
	addressing_mode_ = addressing_mode;
}

/**
 * @brief      Sets the line number.
 *
 * @param[in]  line_number  The line number
 */
void Instruction::set_LineNumber(int line_number)
{
	line_number_ = line_number;
}

/**
 * @brief      Sets the operand.
 *
 * @param[in]  operand  The operand
 */
void Instruction::set_Operand(std::string operand)
{
	operand_ = operand;
}

/**
 * @brief      Initializes the object.
 */
void Instruction::initialize(void)
{
	set_Operand("");
	set_LineNumber(0);
	set_AddressingMode(-1); //Because we don't know which one is
	set_OperationCode(1011); //HALT

}

/**
 * @brief      Writes a string with the instruction, mode and operand (LOAD * 7).
 *
 * @return     The string.
 */
std::string Instruction::writeString(void)
{
	std::string aux, aux2;

	switch(operation_code_)
	{
		case LOAD:
			aux = "LOAD";
			break;

		case STORE:
			aux = "STORE";
			break;

		case ADD:
			aux = "ADD";
			break;

		case SUB:
			aux = "SUB";
			break;

		case MULT:
			aux = "MULT";
			break;

		case DIV:
			aux = "DIV";
			break;

		case READ:
			aux = "READ";
			break;

		case WRITE:
			aux = "WRITE";
			break;

		case JUMP:
			aux = "JUMP";
			break;

		case JGTZ:
			aux = "JGTZ";
			break;

		case JZERO:
			aux = "JZERO";
			break;

		case HALT:
			aux = "HALT";
			break;
	}

	switch(addressing_mode_) 
	{
		case INMEDIATO:
			aux2 = " =";
			break;

		case DIRECTO:
			aux2 = " ";
			break;

		case INDIRECTO:
			aux2 = " *";
			break;
	}

	return (aux + aux2 + get_Operand());
}
