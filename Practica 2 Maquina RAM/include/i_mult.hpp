/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_mult.hpp                                         =
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

#include "i_sub.hpp"

/*------------------------------------------------*/

class I_Mult
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Mult(){};
		I_Mult(Instruction& instruct, Registers& reg);
		~I_Mult(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, Registers& reg);
};