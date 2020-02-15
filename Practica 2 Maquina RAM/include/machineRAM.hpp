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

/*------------------------------------------------*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "inputTape.hpp"
#include "instruction.hpp"
#include "outputTape.hpp"
#include "registers.hpp"
#include "tagRegister.hpp"

/*------------------------------------------------*/


class MachineRAM
{
	private:
		/*----------  Attribs  ----------*/		
		InputTape inputTape_;
		OutputTape outputTape_;
		std::vector<Instruction> instruction_;
		Registers registers_;
		TagRegister tagRegister_;

		std::string instructionFileName_;
		std::string inputTapeFileName_;
		std::string outputTapeFileName_;

	public:
		/*----------  Builders & Destroyer  ----------*/		
		MachineRAM();
		~MachineRAM();

		/*----------  Getters & Setters  ----------*/		
		InputTape get_InputTape(void);
		OutputTape get_OutputTape(void);
		std::vector<Instruction> get_Instruction(void);	
		Registers get_Registers(void);
		TagRegister get_TagRegister(void);
		std::string get_InstructionFileName(void);
		std::string get_InputTapeFileName(void);
		std::string get_OutputTapeFileName(void);

		void  set_InputTape(InputTape inputTape);
		void  set_OutputTape(OutputTape outputTape);
		void  set_Instruction(std::vector<Instruction> instruction);	
		void  set_Registers(Registers registers);
		void  set_TagRegister(TagRegister tagRegister);
		void set_InstructionFileName(std::string instructionFileName);
		void set_InputTapeFileName(std::string intputTapeFileName);
		void set_OutputTapeFileName(std::string outputTapeFileName);	

		/*----------  Functions  ----------*/
		void initialize(void);
		void loadData(void);
		void loadInputTape(void);
		void loadOutputTape(void);
		void saveOutputTape(void);
		void cleanComments(void);

		
};