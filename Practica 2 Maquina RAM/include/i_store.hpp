/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_store.hpp                                        =
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

#include "i_load.hpp"

/*------------------------------------------------*/

class I_Store
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Store(){};
		I_Store(Instruction& instruct, Registers& reg);
		~I_Store(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, Registers& reg);
};