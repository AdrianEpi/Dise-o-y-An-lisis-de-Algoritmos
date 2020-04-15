/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     vertex.hpp                                         =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         03/04/2020                                         =
    =            Subject:       Diseño y Análisis de Algoritmos                    =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <cassert>
#include <string>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

class Vertex {
	
	private:
		int number_;
		std::string name_;

	public: 
		// Builders & Destroyer
		Vertex ();
		Vertex (int number);
		~Vertex ();

		// Getters & Setters
		int get_Number (void) const;
		std::string get_Name (void) const;

		void set_Number (int number);
		void set_Name (std::string name);

		// Functions
		void generateName (void);

};