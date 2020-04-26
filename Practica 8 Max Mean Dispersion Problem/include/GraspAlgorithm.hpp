/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     GraspAlgorithm.hpp                                 =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         17/04/2020                                         =
	=            Subject:       Diseño y Análisis de Algoritmos                    =
	=            Language:      C++                                                =
	=            Email:         alu0101158280@ull.edu.es                           =
	=            Place:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=========================================================================================
=======================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <chrono>
#include <ctime>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"
#define ITERATIONS 50
#define RLCSIZE 4

/*------------------------------------------------*/

class GraspAlgorithm : public Algorithm {

	public:
		// Builder & Destroyer
		GraspAlgorithm ();
		virtual ~GraspAlgorithm ();

		// Public Function
		void runAlgorithm (Graph& graph);

	private:
		// Private Functions
		void generateRLC (std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph);
};