/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     outputTape.hpp                                     =
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

#include <vector>
#include <iostream>
#include <fstream>

/*------------------------------------------------*/


class OutputTape
{
	private:
		/*----------  Attribs  ----------*/		
		std::vector<int> tape_;
		std::string filename_;

	public:
		/*----------  Builder & Destroyer  ----------*/
		OutputTape();
		~OutputTape(){};


		/*----------  Getter & Setter  ----------*/
		std::vector<int> get_tape(void);
		std::string get_filename(void);

		void set_tape(std::vector<int> tape);
		void set_filename(std::string filename);

		/*----------  Functions  ----------*/
		void initialize(void);
		void load(std::string filename);
		void add_Data(int data);

		/*----------  Write  ----------*/		
		void write(void); //Print on screen
		void write(std::string filename); //Write in file
};