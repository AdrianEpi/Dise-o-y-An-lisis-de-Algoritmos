/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     instruction.hpp                                    =
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


class Instruction
{
	public:
		/*----------  Attribs  ----------*/		
		enum code_
		{
			LOAD = 10000,
			STORE = 10001,
			ADD = 10010,
			SUB = 10011,
			MULT = 10100,
			DIV = 10101,
			READ = 10110,
			WRITE = 10111,
			JUMP = 11000,
			JGTZ = 11001,
			JZERO = 11010,
			HALT = 11011
		};
		enum mode_
		{
			INMEDIATO = 100,
			DIRECTO = 101,
			INDIRECTO = 110
		};

	private:
		/*----------  Attribs  ----------*/		
		
		int operation_code_;
		int addressing_mode_;
		int line_number_;
		std::string operand_;

	public:
		/*----------  Builders & Destroyer  ----------*/		
		Instruction();
		Instruction(int code, int line);
		Instruction(int code, int mode, int line, std::string operand);
		~Instruction(){};

		/*----------  Getters & Setters  ----------*/		
		int get_OperationCode(void);
		int get_AddressingMode(void);
		int get_LineNumber(void);
		std::string get_Operand(void);

		void set_OperationCode(int operation_code);
		void set_AddressingMode(int addressing_mode);
		void set_LineNumber(int line_number);
		void set_Operand(std::string operand);

		/*----------  Functions  ----------*/		
		void initialize(void);
		std::string writeString(void);
		std::string transformCode(int code);
		std::string transformAddressing(int code);
};
