/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     Framework.hpp                                      =
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
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "graph.hpp"
#include "Algorithm.hpp"
#include "GreedyAlgorithm.hpp"
#include "AnotherGreedyAlgorithm.hpp"

/*------------------------------------------------*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>


/*------------------------------------------------*/

class FrameWork {
	
	private:
		Graph graph_;
		std::string textFile_;
		Algorithm* algorithm_;

	public:
		// Builders & Destroyer
		FrameWork ();
		FrameWork (std::string textFile);
		virtual ~FrameWork ();

		// Getters & Setters
		Graph get_Graph (void) const;
		std::string get_TextFile (void) const;
		Algorithm* get_Algorithm (void) const;

		void set_Graph (Graph graph);
		void set_TextFile (std::string textFile);
		void set_Algorithm (Algorithm* algorithm);

		// Function
		void initialize (void);
		int printMenu (void);

};