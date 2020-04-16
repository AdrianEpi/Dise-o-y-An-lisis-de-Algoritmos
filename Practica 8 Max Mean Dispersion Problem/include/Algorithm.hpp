/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     Algorithm.hpp                                      =
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
#define STARTMEAN -9999999;

/*------------------------------------------------*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/

#include <string>
#include <algorithm>

/*------------------------------------------------*/

class Algorithm {

	private:
		std::vector<Vertex> solutions_;

	public:
		// Builders & Destroyer
		Algorithm ();
		virtual ~Algorithm ();

		// Getter & Setter
		std::vector<Vertex> get_Solution (void) const;

		void set_Solution (std::vector<Vertex> solution);

		// Functions
		virtual void runAlgorithm (Graph& graph);
		virtual std::ostream& printResult (std::ostream& os);
		float findMean (std::vector<Vertex> vertex, Graph& graph);
		void addVertex (Vertex newVertex);

};