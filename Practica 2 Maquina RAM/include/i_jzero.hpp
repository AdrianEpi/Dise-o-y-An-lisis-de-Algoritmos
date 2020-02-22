/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_jzero.hpp                                        =
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

#include "i_jgtz.hpp"

/*------------------------------------------------*/

class I_Jzero
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Jzero(){};
		I_Jzero(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter);
		~I_Jzero(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, TagRegister& tag_reg, Registers& reg, int& program_counter);
};