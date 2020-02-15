/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     tagRegister.hpp                                    =
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

#include <iostream>
#include <vector>

/*------------------------------------------------*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#include "tag.hpp"

/*------------------------------------------------*/

class TagRegister
{
	private:
		/*----------  Attribs  ----------*/		
		std::vector<Tag> tags_;

	public:
		/*----------  Builder & Destroyer  ----------*/
		TagRegister(){}
		~TagRegister(){}

		/*----------  Getter & Setter  ----------*/		
		std::vector<Tag> get_Tags(void);
		void set_Tags(std::vector<Tag> tags);

		/*----------  Functions  ----------*/
		int findPos(std::string name);
		void insertTag(std::string name, int pos);

		/*----------  Write  ----------*/		
		void write(void);
};