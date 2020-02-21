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
		void runLoad(void)
		{
			I_Load load(instruction_[program_counter_], registers_);
		}
		void runStore(void)
		{
			I_Store store(instruction_[program_counter_], registers_);
		}
		void runAdd(void)
		{
			I_Add add(instruction_[program_counter_], registers_);
		}
		void runSub(void)
		{
			I_Sub sub(instruction_[program_counter_], registers_);
		}
		void runMult(void)
		{
			I_Mult mult(instruction_[program_counter_], registers_);
		}
		void runDiv(void)
		{
			I_Div div(instruction_[program_counter_], registers_);
		}
		void runRead(void)
		{
			I_Read read(instruction_[program_counter_], registers_, inputTape_);
		}
		void runWrite(void)
		{
			I_Write write(instruction_[program_counter_], registers_, outputTape_);
		}
		void runJump(void)
		{
			I_Jump jump(instruction_[program_counter_], tagRegister_, program_counter_);
		}
		void runJgtz(void)
		{
			I_Jgtz jgtz(instruction_[program_counter_], tagRegister_, registers_, program_counter_);
		}
		void runJzero(void)
		{
			I_Jzero jzero(instruction_[program_counter_], tagRegister_, registers_, program_counter_);
		}
		void runProgram(void)
		{
			bool stop = false;
			set_ProgramCounter(0);
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

						break;
				}
				program_counter_++;
				if(program_counter_ == instruction_.size())
					stop = true;
			}
		}		
};