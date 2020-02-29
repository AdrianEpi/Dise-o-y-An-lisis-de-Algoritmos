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
* @Last Modified time: 2020-02-29 18:17:00
*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "../include/machineRam.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
MachineRAM::MachineRAM()
{
	std::cout << "The machine RAM must be initialized with an input program, an input tap and an output tape." << std::endl;
	exit(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  program_file        The program file
 * @param[in]  inputTapeFileName   The input tape file name
 * @param[in]  outputTapeFileName  The output tape file name
 */
MachineRAM::MachineRAM(std::string program_file, std::string inputTapeFileName, std::string outputTapeFileName)
{
	initialize();
	instructionFileName_ = program_file;
	inputTapeFileName_ = inputTapeFileName;
	outputTapeFileName_ = outputTapeFileName;
	inputTape_.set_filename(inputTapeFileName_);
	outputTape_.set_filename(outputTapeFileName_);
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
 * @brief      Gets the instruction codes.
 *
 * @return     The instruction codes.
 */
Instruction MachineRAM::get_InstructionCodes(void)
{
	return instruction_codes_;
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
 * @brief      Gets the number of instructions.
 *
 * @return     The number of instructions.
 */
int MachineRAM::get_NumberOfInstructions(void)
{
	return number_of_instructions;
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
 * @brief      Sets the instruction codes.
 *
 * @param[in]  codes  The codes
 */
void MachineRAM::set_InstructionCodes(Instruction codes)
{
	instruction_codes_ = codes;
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
 * @brief      Sets the number of instructions.
 *
 * @param[in]  num   The new value
 */
void MachineRAM::set_NumberOfInstructions(int num)
{
	number_of_instructions = num;
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

/**
 * @brief      Loads the program data.
 */
void MachineRAM::loadData(void)
{
	std::string line, tag_name, operand;
	int code, line_number = 0, addresing, asdf;
	loadInputTape();

	std::ifstream file(instructionFileName_.c_str());
	if(file.is_open())
	{
		while(!file.eof())
		{
			getline(file, line);
			if(!isAComment(line))
			{
				eraseSpacesTabs(line);
				if(isTag(line))
				{
					tag_name.clear();
					tag_name = searchTag(line);
					toUpperCase(tag_name);
					if(tagRegister_.findPos(tag_name) == -1)
						tagRegister_.add_Pos(tag_name, line_number);
					else
						tagRegister_.insertTag(tag_name, line_number);
				}
				line_number++;
			}
		}
		file.clear();	// Cleans the file pointer
		file.seekg(0, file.beg); 	// Restart the file counter so it can be readed again
		line_number = 0;
		while(!file.eof())
		{
			getline(file, line);
			if(!isAComment(line))
			{
				eraseSpacesTabs(line);
				if(isTag(line))
				{
					tag_name.clear();
					tag_name = searchTag(line);
				}
				if(line.size() > 1) //If there's anything else on the line
				{
					code = searchInstructionCode(line);
					if(code == instruction_codes_.HALT)
					{
						Instruction new_instruction(code, line_number);
						instruction_.push_back(new_instruction);
					}
					else
					{
						addresing = searchAddressing(line);
						asdf = searchOperand(line);
						Instruction new_instruction(code, addresing, line_number, asdf);
						instruction_.push_back(new_instruction);
					}
				}
				line_number++;
			}
		}
		file.close();

		loadInputTape();
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
	inputTape_.load(inputTape_.get_filename());
}

/**
 * @brief      Loads an output tape.
 */
void MachineRAM::loadOutputTape(void)
{
	outputTape_.load(outputTape_.get_filename());
}

/**
 * @brief      Saves an output tape.
 */
void MachineRAM::saveOutputTape(void)
{
	outputTape_.write(outputTape_.get_filename());
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
	if(aux[0] == '#' || aux[0] == '\n')
		return true;
	return false;
}

/**
 * @brief      Searchs the tag name.
 *
 * @param      line  The line
 *
 * @return     The tag name.
 */
std::string MachineRAM::searchTag(std::string &line)
{
	std::string tag_name;
	int pos;
	pos = line.find(':'); //We search for the tag end position
	tag_name = line.substr(0, pos);
	line.erase(0, pos+1);
	eraseSpacesTabs(line);
	return tag_name;
}

/**
 * @brief      Searchs the operand.
 *
 * @param      line  The line
 *
 * @return     The operand.
 */
int MachineRAM::searchOperand(std::string &line)
{
	if(isdigit(line[0]))
	{
		int aux = stoi(line);
		return aux;
	}

	else
	{
		toUpperCase(line);
		line = line.substr(0, line.size()-1);
		int aux = tagRegister_.findCode(line);
		if(aux == -1)
		{
			std::cout << "ERROR, tag not defined in program." << std::endl;
			exit(0);
		}
		return aux;
	}
}

/**
 * @brief      Searchs the addressing code.
 *
 * @param[in]  line  The line
 *
 * @return     The code.
 */
int MachineRAM::searchAddressing(std::string &line)
{
	int pos;
	pos = line.find(' ');
	if(line[pos+1] == '=')
	{
		line.erase(pos, pos + 2);
		return instruction_codes_.INMEDIATO;
	}
	else if(line[pos+1] == '*')
	{
		line.erase(pos, pos + 2);
		return instruction_codes_.INDIRECTO;
	}
	else
	{
		line.erase(pos, pos + 1);
		return instruction_codes_.DIRECTO;
	}
}

/**
 * @brief      Erase the initial spaces and tabs of the line.
 *
 * @param      line  The line
 */
void MachineRAM::eraseSpacesTabs(std::string &line)
{
	char aux;
	int space = 0;
	aux = line[space];
	while(aux == ' ' || aux == '\t')
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
	for(int i = 0; i < line.size(); i++)
		if(line[i] == ':')
			return true;
	
	if(pos > 0)
		return true;
	else
		return false;
}

/**
 * @brief      Gives the instruction code.
 *
 * @param[in]  line  The line
 *
 * @return     The code.
 */
int MachineRAM::searchInstructionCode(std::string &line)
{
	std::string code;
	int pos = line.size();
	if(line.find(' '))
	{
		pos = line.find(' '); // Search where does the instruction name end
		code = line.substr(0, pos);
		line.erase(0, pos);
	}
	else
		code = line;
	
	if(code == "LOAD" || code == "load")
		return instruction_codes_.LOAD;
	else if(code == "STORE" || code == "store")
		return instruction_codes_.STORE;
	else if(code == "ADD" || code == "add")
		return instruction_codes_.ADD;
	else if(code == "SUB" || code == "sub")
		return instruction_codes_.SUB;
	else if(code == "MULT" || code == "mult")
		return instruction_codes_.MULT;
	else if(code == "DIV" || code == "div")
		return instruction_codes_.DIV;
	else if(code == "READ" || code == "read")
		return instruction_codes_.READ;
	else if(code == "WRITE" || code == "write")
		return instruction_codes_.WRITE;
	else if(code == "JUMP" || code == "jump")
		return instruction_codes_.JUMP;
	else if(code == "JGTZ" || code == "jgtz")
		return instruction_codes_.JGTZ;
	else if(code == "JZERO" || code == "jzero")
		return instruction_codes_.JZERO;
	else if(code == "HALT" || code == "halt")
		return instruction_codes_.HALT;
	else
	{
		std::cout << "Error, instruction not found" << std::endl;
		exit(0);
	}
}

/**
 * @brief      Writes the program data, instructions, registers, input and output tapes.
 *
 * @param      cout  The cout
 *
 * @return     Prints by console.
 */
std::ostream& MachineRAM::writeProgram(std::ostream& cout)
{
	std::cout << std::endl << "Number\tInstruction\tCodification\tAddresing Mode\tOperand" << std::endl;
	std::cout << "__________________________________________________________________________________________" << std::endl;
	for(int i = 0; i < instruction_.size(); i++)
	{
		std::cout << i << "\t" << instruction_[i].transformCode(instruction_[i].get_OperationCode()) << "\t\t";
		std::cout << instruction_[i].get_OperationCode() << "\t\t" << instruction_[i].transformAddressing(instruction_[i].get_AddressingMode());
		if(instruction_[i].get_AddressingMode() == 101)
			std::cout << std::setw(10);
		else
			std::cout << std::setw(8);
		if(instruction_[i].get_Operand() != -1)
			std::cout << instruction_[i].get_Operand() << std::endl;
	}
	std::cout << std::endl << "Input Tape: " << std::endl;
	inputTape_.write();
	std::cout << std::endl << "Registers: " << std::endl;
	registers_.write();
	std::cout << std::endl;
	tagRegister_.write();
	std::cout << std::endl << "Output Tape: " << std::endl;
	outputTape_.write();

}

/*----------  Run functions  ----------*/

/**
 * @brief      Runs Load instruction
 */
void MachineRAM::runLoad(void)
{
	I_Load load(instruction_[program_counter_], registers_);
}

/**
 * @brief      Runs Store instruction
 */
void MachineRAM::runStore(void)
{
	I_Store store(instruction_[program_counter_], registers_);
}

/**
 * @brief      Runs Add instruction
 */
void MachineRAM::runAdd(void)
{
	I_Add add(instruction_[program_counter_], registers_);
}

void MachineRAM::runSub(void)
{
	I_Sub sub(instruction_[program_counter_], registers_);
}

/**
 * @brief      Runs Mult instruction
 */
void MachineRAM::runMult(void)
{
	I_Mult mult(instruction_[program_counter_], registers_);
}

/**
 * @brief      Runs Div instruction
 */
void MachineRAM::runDiv(void)
{
	I_Div div(instruction_[program_counter_], registers_);
}

/**
 * @brief      Runs Read instruction
 */
void MachineRAM::runRead(void)
{
	I_Read read(instruction_[program_counter_], registers_, inputTape_);
}

/**
 * @brief      Runs Write instruction
 */
void MachineRAM::runWrite(void)
{
	I_Write write(instruction_[program_counter_], registers_, outputTape_);
}

/**
 * @brief      Runs Jump instruction
 */
void MachineRAM::runJump(void)
{
	I_Jump jump(instruction_[program_counter_], tagRegister_, program_counter_);
}

/**
 * @brief      Runs Jgtz instruction
 */
void MachineRAM::runJgtz(void)
{
	I_Jgtz jgtz(instruction_[program_counter_], tagRegister_, registers_, program_counter_);
}

/**
 * @brief      Runs Jzero instruction
 */
void MachineRAM::runJzero(void)
{
	I_Jzero jzero(instruction_[program_counter_], tagRegister_, registers_, program_counter_);
}

/**
 * @brief      Runs and excutes the program
 */
void MachineRAM::runProgram(void)
{
	bool stop = false;
	set_ProgramCounter(0);
	set_NumberOfInstructions(0);
	Instruction aux;
	int mem;
	char c;

	while(!stop)
	{
		aux = instruction_[program_counter_];
		switch(aux.get_OperationCode())
		{
			case instruction_codes_.LOAD:
				runLoad();						
				break;

			case instruction_codes_.STORE:
				runStore();
				break;

			case instruction_codes_.ADD:
				runAdd();
				break;

			case instruction_codes_.SUB:
				runSub();
				break;

			case instruction_codes_.MULT:
				runMult();
				break;

			case instruction_codes_.DIV:
				runDiv();
				break;

			case instruction_codes_.READ:
				runRead();
				break;

			case instruction_codes_.WRITE:
				runWrite();
				break;

			case instruction_codes_.JUMP:
				runJump();
				break;

			case instruction_codes_.JGTZ:
				runJgtz();
				break;

			case instruction_codes_.JZERO:
				runJzero();
				break;

			case instruction_codes_.HALT:
				stop = true;
				break;

			default:
				std::cout << "Error running program." << std::endl;
				exit(0);
				break;
		}
		program_counter_++;
		number_of_instructions++;
		if(program_counter_ == instruction_.size())
			stop = true;
	}
	saveOutputTape();
	inputTape_.set_head(0);
}

/**
 * @brief      Runs and excutes the program while its printing on screen
 */
void MachineRAM::runTraza(void)
{
	bool stop = false;
	set_ProgramCounter(0);
	set_NumberOfInstructions(0);
	Instruction aux;
	int mem;
	char c;
	std::cout << std::endl << "Number\tInstruction\tCodification\tAddresing Mode\tOperand" << std::endl;
	std::cout << "__________________________________________________________________________________________" << std::endl;
	while(!stop)
	{
		aux = instruction_[program_counter_];
		switch(aux.get_OperationCode())
		{
			case instruction_codes_.LOAD:
				runLoad();						
				break;

			case instruction_codes_.STORE:
				runStore();
				break;

			case instruction_codes_.ADD:
				runAdd();
				break;

			case instruction_codes_.SUB:
				runSub();
				break;

			case instruction_codes_.MULT:
				runMult();
				break;

			case instruction_codes_.DIV:
				runDiv();
				break;

			case instruction_codes_.READ:
				runRead();
				break;

			case instruction_codes_.WRITE:
				runWrite();
				break;

			case instruction_codes_.JUMP:
				runJump();
				break;

			case instruction_codes_.JGTZ:
				runJgtz();
				break;

			case instruction_codes_.JZERO:
				runJzero();
				break;

			case instruction_codes_.HALT:
				stop = true;
				break;

			default:
				std::cout << "Error running program." << std::endl;
				exit(0);
				break;
		}
		// Print on screen
		std::cout << number_of_instructions << "\t" << instruction_[program_counter_].transformCode(instruction_[program_counter_].get_OperationCode()) << "\t\t";
		std::cout << instruction_[program_counter_].get_OperationCode() << "\t\t" << instruction_[program_counter_].transformAddressing(instruction_[program_counter_].get_AddressingMode());
		if(instruction_[program_counter_].get_AddressingMode() == 101)
			std::cout << std::setw(10);
		else
			std::cout << std::setw(8);
		if(instruction_[program_counter_].get_Operand() != -1)
			std::cout << instruction_[program_counter_].get_Operand() << std::endl;

		program_counter_++;
		number_of_instructions++;
		if(program_counter_ == instruction_.size())
			stop = true;
	}
	saveOutputTape();
	inputTape_.set_head(0);
}