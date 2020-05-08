/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 9 Maximum Diversity                       =
	=            File name:     GraspAlgorithm.hpp                                 =
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
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <chrono>
#include <ctime>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "Framework.hpp"

/*------------------------------------------------*/

class GraspAlgorithm : public Algorithm {

	private:
		int RLC_;
		int iterations_;

	public:
		// Builder & Destroyer
		GraspAlgorithm ();
		GraspAlgorithm (int RLC, int iterations);
		virtual ~GraspAlgorithm ();

		// Getters & Setters
		int get_RLC (void) const;
		int get_Iterations (void) const;

		void set_RLC (int RLC);
		void set_Iterations (int iterations);
		
		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		// Private Functions
		void generateRLC (std::vector<Vertex>& RLCvector, std::vector<Vertex>& solution);
};