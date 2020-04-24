/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 8 Max-Mean Problem                        =
	=            File name:     VNSAlgorithm.hpp                                   =
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
#define ITERATIONS 30

/*------------------------------------------------*/

class VNSAlgorithm : public Algorithm {

	private:
		int neighbourHoodSize_;
	public:
		// Builder & Destroyer
		VNSAlgorithm ();
		virtual ~VNSAlgorithm ();

		// Getter & Setter
		int get_NeighbourHoodSize (void);
		void set_NeighbourHoodSize (int size);

		// Public Function
		void runAlgorithm (Graph& graph);

	private:
		// Private Functions
		void generateNeighbourHoodStructure (std::vector<Vertex>& RLC, std::vector<Vertex> solution, Graph graph, int neighbourHoodSelector);
		int getRandomVertex (std::vector<Vertex> RLC);
		void initialSolution (Graph& graph, std::vector<Vertex>& vertex);
};