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
	private:
		enum code_
		{
			LOAD = 0000,
			STORE = 0001,
			ADD = 0010,
			SUB = 0011,
			MULT = 0100,
			DIV = 0101,
			READ = 0110,
			WRITE = 0111,
			JUMP = 1000,
			JGTZ = 1001,
			JZERO = 1010,
			HALT = 1011
		};
		enum mode_
		{
			INMEDIATO = 00,
			DIRECTO = 01,
			INDIRECTO = 10
		};
		int operation_code_;
		int addressing_mode_;
		int line_number_;
		std::string operand_;

	public:
		Instruction();
		Instruction(int code, int line);
		Instruction(int code, int mode, int line, std::string operand);
		~Instruction(){};

		int get_OperationCode(void);
		int get_AddressingMode(void);
		int get_LineNumber(void);
		std::string get_Operand(void);

		void set_OperationCode(int operation_code);
		void set_AddressingMode(int addressing_mode);
		void set_LineNumber(int line_number);
		void set_Operand(std::string operand);

		void initialize(void);
		std::string writeString(void);
};
