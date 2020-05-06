/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     Algorithm.hpp                                      =
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
#define STARTMEAN -9999999;

/*------------------------------------------------*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>
#include <algorithm>

/*------------------------------------------------*/

class Algorithm {

	private:
		std::vector<Vertex> solutions_;
		float maxMean_;

	public:
		// Builders & Destroyer
		Algorithm ();
		virtual ~Algorithm ();

		// Getter & Setter
		std::vector<Vertex> get_Solution (void) const;
		float get_MaxMean (void) const;

		void set_Solution (std::vector<Vertex> solution);
		void set_MaxMean (float mean);

		// Functions
		virtual void runAlgorithm (Graph& graph, Chrono& chrono);
		std::ostream& printResult (std::ostream& os, Chrono& chrono);
		float findDiversity (std::vector<Vertex>& vertex);
		std::vector<float> generateGravityCenter (std::vector<Vertex>& vertex);
};