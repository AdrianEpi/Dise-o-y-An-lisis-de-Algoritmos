/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     machineRam.hpp                                     =
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
/*------------  LIBRARY DECLARATION  ------------*/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>


/*------------------------------------------------*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "i_jzero.hpp"

/*------------------------------------------------*/
enum mode_
{
	INMEDIATO = 100,
	DIRECTO = 101,
	INDIRECTO = 110
};

class MachineRAM
{
	private:
		/*----------  Attribs  ----------*/		
		InputTape inputTape_;
		OutputTape outputTape_;
		std::vector<Instruction> instruction_;
		Instruction instruction_codes_;
		Registers registers_;
		TagRegister tagRegister_;

		int program_counter_;
		int number_of_instructions;
		std::string instructionFileName_;
		std::string inputTapeFileName_;
		std::string outputTapeFileName_;

	public:
		/*----------  Builders & Destroyer  ----------*/		
		MachineRAM();
		MachineRAM(std::string program_file, std::string intputTapeFileName, std::string outputTapeFileName);
		~MachineRAM(){};

		/*----------  Getters & Setters  ----------*/		
		InputTape get_InputTape(void);
		OutputTape get_OutputTape(void);
		std::vector<Instruction> get_Instruction(void);	
		Instruction get_InstructionCodes(void);
		Registers get_Registers(void);
		TagRegister get_TagRegister(void);
		int get_NumberOfInstructions(void);
		int get_ProgramCounter(void);
		std::string get_InstructionFileName(void);
		std::string get_InputTapeFileName(void);
		std::string get_OutputTapeFileName(void);

		void set_InputTape(InputTape inputTape);
		void set_OutputTape(OutputTape outputTape);
		void set_Instruction(std::vector<Instruction> instruction);	
		void set_InstructionCodes(Instruction codes);
		void set_Registers(Registers registers);
		void set_TagRegister(TagRegister tagRegister);
		void set_NumberOfInstructions(int number);
		void set_ProgramCounter(int pc);
		void set_InstructionFileName(std::string instructionFileName);
		void set_InputTapeFileName(std::string intputTapeFileName);
		void set_OutputTapeFileName(std::string outputTapeFileName);	

		/*----------  Basic Functions  ----------*/
		void initialize(void);
		void loadData(void);
		void loadInputTape(void);
		void loadOutputTape(void);
		void saveOutputTape(void);

		/*----------  File Functions  ----------*/
		void eraseSpacesTabs(std::string &line);		
		bool isAComment(std::string line);
		bool isTag(std::string &line);
		std::string searchTag(std::string &line);
		int searchOperand(std::string &line);
		int searchAddressing(std::string &line);		
		int searchInstructionCode(std::string &line);
		void toUpperCase(std::string &word)
		{
			  for (int i = 0; i < word.length(); i++) {
			    word[i] = toupper(word[i]);
			  }
		}

		/*----------  Read & Write  ----------*/
		std::ostream& writeProgram(std::ostream& cout);

		/*----------  RUN  ----------*/
		void runLoad(void);
		void runStore(void);
		void runAdd(void);
		void runSub(void);
		void runMult(void);
		void runDiv(void);
		void runRead(void);
		void runWrite(void);
		void runJump(void);
		void runJgtz(void);
		void runJzero(void);

		void runProgram(void);
		void runTraza(void);
};