/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_read.hpp                                         =
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

#include "i_div.hpp"

/*------------------------------------------------*/

class I_Read
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Read(){};
		I_Read(Instruction& instruct, Registers& reg, InputTape& input_tape);
		~I_Read(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, Registers& reg, InputTape& input_tape);
};