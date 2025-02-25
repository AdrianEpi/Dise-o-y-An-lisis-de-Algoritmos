/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     MultiBootAlgorithm.hpp                             =
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
#define MODE 1

/*------------------------------------------------*/

class MultiBootAlgorithm : public Algorithm {

	public:
		// Builder & Destroyer
		MultiBootAlgorithm ();
		virtual ~MultiBootAlgorithm ();

		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		// Private Functions
		void runAlgorithmMode1 (Graph& graph, Chrono& chrono);
		void runAlgorithmMode2 (Graph& graph, Chrono& chrono);
		void generateRLC (std::vector<Vertex>& RLC, std::vector<Vertex>& solution, Graph& graph);
		void selectData (int& RLCSize, int& iterations, int& stopMode); 
};