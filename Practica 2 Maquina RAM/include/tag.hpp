/*===================================================================================
=====================================================================================
	=                                                                              =
	=            Proyect:       Practica 2 Simulador de la maquina RAM             =
	=            File name:     tag.hpp                                            =
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

/*------------------------------------------------*/


class Tag
{
	private:
		/*----------  Attribs  ----------*/
		std::string name_;
		int pos_;

	public:
		/*----------  Builders & Destroyer  ----------*/
		Tag(){}
		Tag(std::string name, int pos);
		~Tag(){}

		/*----------  Getters & Setters  ----------*/		
		std::string get_Name(void);
		int get_Pos(void);

		void set_Name(std::string name);
		void set_Pos(int pos);
};