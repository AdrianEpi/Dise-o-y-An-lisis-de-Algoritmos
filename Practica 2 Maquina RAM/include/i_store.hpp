/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     load.hpp                                           =
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
//#include "instruction.hpp"
class I_Store
{
	private:
		int addressing_;
		int operand_;

	public:
		I_Store(){};
		//I_Store(int addressing, int operand, Registers& registers);
		//I_Store(Instruction& instruc);
		~I_Store(){};

		int get_Addressing(void);
		int get_Operand(void);
		int asdas(Instruction asdas);

		void set_Addressing(int addressing);
		void set_Operand(int operand);
};