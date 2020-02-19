/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     registers.hpp                                      =
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

#define MAX_REGISTERS 20
#include <vector>
#include <cassert>
#include <iostream>

/*------------------------------------------------*/


class Registers
{
	private:
		/*----------  Attribs  ----------*/		
		std::vector<int> registers_;

	public:
		/*----------  Builders & Destroyer  ----------*/		
		Registers(void);
		Registers(std::vector<int> registers);
		~Registers(){};

		/*----------  Getter & Setter  ----------*/
		std::vector<int> get_Registers(void);
		int get_SpecificRegister(int number);
		int get_Accumulator(void);
		
		void set_Registers(std::vector<int> registers);
		void set_SpecificRegister(int data, int number);
		void set_Accumulator(int data);

		/*----------  Functions  ----------*/		
		void initialize(void);

		/*----------  Write  ----------*/		
		void write(void);
};