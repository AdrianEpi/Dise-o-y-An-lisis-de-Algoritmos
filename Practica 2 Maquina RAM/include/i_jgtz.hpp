/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_jgtz.hpp                                         =
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
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "i_jump.hpp"

/*------------------------------------------------*/

class I_Jgtz
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Jgtz(){};
		I_Jgtz(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter);
		~I_Jgtz(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter);
};