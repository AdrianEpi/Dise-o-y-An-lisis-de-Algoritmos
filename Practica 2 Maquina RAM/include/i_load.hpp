/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     i_load.hpp                                         =
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

#include "instruction.hpp"
#include "registers.hpp"
#include "inputTape.hpp"
#include "outputTape.hpp"
#include "tagRegister.hpp"

/*------------------------------------------------*/

class I_Load
{
	public:
		/*----------  Builders & Destroyer  ----------*/
		I_Load(){};
		I_Load(Instruction& instruct, Registers& reg);
		~I_Load(){};

		/*----------  Functions  ----------*/
		void runProcess(Instruction& instruct, Registers& reg);
};