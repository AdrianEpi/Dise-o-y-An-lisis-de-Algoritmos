/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     Framework.hpp                                      =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         06/05/2020                                         =
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
#include "Chrono.hpp"
#include "Algorithm.hpp"
/*#include "GreedyAlgorithm.hpp"
#include "AnotherGreedyAlgorithm.hpp"
#include "GraspAlgorithm.hpp" */

/*------------------------------------------------*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>


/*------------------------------------------------*/

/**
 * @brief      This class describes a frame work.
 */
class FrameWork {
	
	private:
		Graph graph_;
		std::string textFile_;
		Algorithm* algorithm_;
		Chrono chrono_;

	public:
		// Builders & Destroyer
		FrameWork ();
		FrameWork (std::string textFile);
		virtual ~FrameWork ();

		// Getters & Setters
		Graph get_Graph (void) const;
		std::string get_TextFile (void) const;
		Algorithm* get_Algorithm (void) const;
		Chrono get_Chrono (void) const;

		void set_Graph (Graph graph);
		void set_TextFile (std::string textFile);
		void set_Algorithm (Algorithm* algorithm);
		void set_Chrono (Chrono chrono);

		// Function
		void initialize (void);
		void executeFrameWork (void);
		int printMenu (void);

};