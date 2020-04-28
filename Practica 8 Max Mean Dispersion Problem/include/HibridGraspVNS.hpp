/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     HibridGraspVNS.hpp                                   =
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
#include <cmath>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class HibridGraspVNS : public Algorithm {

	public:
		// Builder & Destroyer
		HibridGraspVNS ();
		virtual ~HibridGraspVNS ();

		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		// Private Functions
		void genertePossiblesChanges (std::vector<Vertex>& possibilities, std::vector<Vertex>& solution, Graph& graph);
		void structures (std::vector<Vertex>& possibilities, std::vector<Vertex>& tempSolution, int& swapsNum);
		void selectData (int& iterations, int& stopMode);
};