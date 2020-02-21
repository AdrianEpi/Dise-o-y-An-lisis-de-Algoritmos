/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     inputTape.hpp                                      =
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

class InputTape
{
	private:
		/*----------  Attribs  ----------*/		
		unsigned head_;
		std::vector<int> tape_;
		std::string filename_;

	public:
		/*----------  Builders & Destroyer  ----------*/		
		InputTape();
		InputTape(std::vector<int> tape, std::string filename);
		~InputTape(){};

		/*----------  Getters & Setters  ----------*/		
		unsigned get_head(void);
		std::vector<int> get_tape(void);
		std::string get_filename(void);

		void set_head(unsigned head);
		void set_tape(std::vector<int> tape);
		void set_filename(std::string filename);

		/*----------  Functions  ----------*/		
		void initialize(void);
		void load(std::string filename);

		/*----------  Read & Write  ----------*/		
		int read(void);
		void write(void);
};