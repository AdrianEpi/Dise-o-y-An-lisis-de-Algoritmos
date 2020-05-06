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
#include <vector>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

/**
 * @brief      This class describes a vertex.
 */
class Vertex {
	
	private:
		int number_;
		std::string name_;
		std::vector<float> coordinates_;

	public: 
		// Builders & Destroyer
		Vertex ();
		Vertex (int number);
		~Vertex ();

		// Getters & Setters
		int get_Number (void) const;
		std::string get_Name (void) const;
		std::vector<float> get_Coordinates (void) const;

		void set_Number (int number);
		void set_Name (std::string name);
		void set_Coordinates (std::vector<float> coordinates);

		// Operator Overload
		void operator= (const Vertex& vertex);

		// Functions
		void generateName (void);
		void addCoordinate (float coordinate);

};