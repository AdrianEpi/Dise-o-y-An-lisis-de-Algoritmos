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
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-15 20:08:43
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/machineRam.hpp"

/*------------------------------------------------*/
MachineRAM::MachineRAM()
{
	std::cout << "The machine RAM must be initialized with an input program, an input tap and an output tape." << std::endl;
	exit(0);
}

MachineRAM::MachineRAM(std::string program_file, std::string inputTapeFileName, std::string outputTapeFileName)
{
	instructionFileName_ = program_file;
	inputTapeFileName_ = inputTapeFileName;
	outputTapeFileName_ = outputTapeFileName;
}
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
 * @brief      Gets the program counter.
 *
 * @return     The program counter.
 */
int MachineRAM::get_ProgramCounter(void)
{
	return program_counter_;
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
 * @brief      Sets the program counter.
 *
 * @param[in]  pc    The new value
 */
void MachineRAM::set_ProgramCounter(int pc)
{
	program_counter_ = pc;
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
 * @param[in]  inputTapeFileName  The input tape file name
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
	set_ProgramCounter(0);
	instruction_.clear();
	inputTape_.initialize();
	outputTape_.initialize();
	registers_.initialize();
}

void MachineRAM::loadData(void)
{
	std::string line, tag_name, operand;
	int code, line_number = 0;

	std::ifstream file(instructionFileName_.c_str());
	if(file.is_open())
	{
		while(!file.eof())
		{
			getline(file, line);
			if(!isAComment(line))
			{
				tag_name.clear();
			}
		}
	}
	else
	{
		std::cout << "Error while opening program file." << std::endl;
		exit(0);
	}
}

/**
 * @brief      Loads an input tape.
 */
void MachineRAM::loadInputTape(void)
{
	inputTape_.load(inputTapeFileName_);
}

/**
 * @brief      Loads an output tape.
 */
void MachineRAM::loadOutputTape(void)
{
	outputTape_.load(outputTapeFileName_);
}

/**
 * @brief      Saves an output tape.
 */
void MachineRAM::saveOutputTape(void)
{
	outputTape_.write(outputTapeFileName_);
}

/**
 * @brief      Determines whether the specified line is a comment.
 *
 * @param[in]  line  The line
 *
 * @return     True if the specified line is a comment, False otherwise.
 */
bool MachineRAM::isAComment(std::string line)
{
	char aux[line.size()];
	strcpy(aux, line.c_str());
	if(aux[0] == '#')
		return true;
	return false;
}
////////////////////////////////////////////////////////////7
std::string MachineRAM::searchTag(std::string &line)
{
	std::string tag_name;
	int pos;
	eraseSpacesTabs(line);



}

/**
 * @brief      Erase the initial spaces and tabs of the line
 *
 * @param      line  The line
 */
void MachineRAM::eraseSpacesTabs(std::string &line)
{
	char aux;
	int space = 0;
	aux = line[space];
	while(aux != ' ' || aux != '\t')
		aux = line[space++];
	line.erase(0, space-1); //Erases all the spaces and tabs from start to the first letter
}

/**
 * @brief      Determines whether the specified line is tag.
 *
 * @param      line  The line
 *
 * @return     True if the specified line is tag, False otherwise.
 */
bool MachineRAM::isTag(std::string &line)
{
	int pos = 0;
	pos = line.find(':');
	if(pos > 0)
		return true;
	else
		return false;
}
