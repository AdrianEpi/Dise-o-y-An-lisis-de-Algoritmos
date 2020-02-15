/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     machineRam.cpp                                     =
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
* @Date:   2020-02-14 09:41:49
* @Last Modified by:   adria
* @Last Modified time: 2020-02-15 12:17:46
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/machineRam.hpp"

/*------------------------------------------------*/

/**
 * @brief      Gets the input tape.
 *
 * @return     The input tape.
 */
InputTape MachineRAM::get_InputTape(void)
{
	return inputTape_;
}

/**
 * @brief      Gets the output tape.
 *
 * @return     The output tape.
 */
OutputTape MachineRAM::get_OutputTape(void)
{
	return	outputTape_;
}

/**
 * @brief      Gets the instruction.
 *
 * @return     The instruction.
 */
std::vector<Instruction> MachineRAM::get_Instruction(void)
{
	return instruction_;
}	

/**
 * @brief      Gets the registers.
 *
 * @return     The registers.
 */
Registers MachineRAM::get_Registers(void)
{
	return registers_;
}

/**
 * @brief      Gets the tag register.
 *
 * @return     The tag register.
 */
TagRegister MachineRAM::get_TagRegister(void)
{
	return tagRegister_;
}

/**
 * @brief      Gets the instruction file name.
 *
 * @return     The instruction file name.
 */
std::string MachineRAM::get_InstructionFileName(void)
{
	return instructionFileName_;
}

/**
 * @brief      Gets the input tape file name.
 *
 * @return     The input tape file name.
 */
std::string MachineRAM::get_InputTapeFileName(void)
{
	return inputTapeFileName_;
}

/**
 * @brief      Gets the output tape file name.
 *
 * @return     The output tape file name.
 */
std::string MachineRAM::get_OutputTapeFileName(void)
{
	return outputTapeFileName_;
}

/**
 * @brief      Sets the input tape.
 *
 * @param[in]  inputTape  The input tape
 */
void  MachineRAM::set_InputTape(InputTape inputTape)
{
	inputTape_ = inputTape;
}

/**
 * @brief      Sets the output tape.
 *
 * @param[in]  outputTape  The output tape
 */
void  MachineRAM::set_OutputTape(OutputTape outputTape)
{
	outputTape_ = outputTape;
}

/**
 * @brief      Sets the instruction.
 *
 * @param[in]  instruction  The instruction
 */
void  MachineRAM::set_Instruction(std::vector<Instruction> instruction)
{
	instruction_ = instruction;
}	

/**
 * @brief      Sets the registers.
 *
 * @param[in]  registers  The registers
 */
void  MachineRAM::set_Registers(Registers registers)
{
	registers_ = registers;
}

/**
 * @brief      Sets the tag register.
 *
 * @param[in]  tagRegister  The tag register
 */
void  MachineRAM::set_TagRegister(TagRegister tagRegister)
{
	tagRegister_ = tagRegister;
}	

/**
 * @brief      Sets the instruction file name.
 *
 * @param[in]  instructionFileName  The instruction file name
 */
void MachineRAM::set_InstructionFileName(std::string instructionFileName)
{
	instructionFileName_ = instructionFileName;
}

/**
 * @brief      Sets the input tape file name.
 *
 * @param[in]  intputTapeFileName  The intput tape file name
 */
void MachineRAM::set_InputTapeFileName(std::string inputTapeFileName)
{
	inputTapeFileName_ = inputTapeFileName;
}

/**
 * @brief      Sets the output tape file name.
 *
 * @param[in]  outputTapeFileName  The output tape file name
 */
void MachineRAM::set_OutputTapeFileName(std::string outputTapeFileName)
{
	outputTapeFileName_ = outputTapeFileName;
}


/*----------  Functions  ----------*/
void MachineRAM::initialize(void)
{

}

void MachineRAM::loadData(void)
{

}

void MachineRAM::loadInputTape(void)
{

}

void MachineRAM::loadOutputTape(void)
{

}

void MachineRAM::saveOutputTape(void)
{

}

void MachineRAM::cleanComments(void)
{

}
