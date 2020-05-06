/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     edge.hpp                                           =
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

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once

/*------------------------------------------------*/

/**
 * @brief      This class describes an edge.
 */
class Edge {

	private:
		float distance_;
		int vertexA_;
		int vertexB_;

	public:
		// Builders & Destroyer
		Edge ();
		Edge (int vertexA, int vertexB, float  distance);
		~Edge ();

		// Getters & Setters
		float get_Distance (void) const;
		int get_VertexA (void) const;
		int get_VertexB (void) const;

		void set_Distance (float distance);
		void set_VertexA (int vertexA);
		void set_VertexB (int vertexB);
};