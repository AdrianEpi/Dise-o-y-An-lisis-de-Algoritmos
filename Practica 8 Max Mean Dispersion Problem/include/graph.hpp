/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     graph.hpp                                          =
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

#include <iostream>
#include <vector>
#include <fstream>

/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#pragma once
#include "vertex.hpp"
#include "edge.hpp"

/*------------------------------------------------*/


/**
 * @brief      This class describes a graph.
 */
class Graph {

	private:
		std::vector<Vertex> vertex_;
		std::vector<Edge> edges_;
		std::string textFile_;
		int vertexNum_;


	public:
		// Builders & Destroyer
		Graph ();
		Graph (std::string textFile);
		~Graph ();

		// Getters & Setters
		std::vector<Vertex> get_Vertex (void) const;
		std::vector<Edge> get_Edges (void) const;
		std::string get_TextFile (void) const;
		int get_VertexNum (void) const;

		void set_Vertex (std::vector<Vertex> vertex);
		void set_Edges (std::vector<Edge> edge);
		void set_TextFile (std::string textFile);
		void set_VertexNum (int vertexNum);

		// Functions
		void generateGraph (void);

		// Write
		void printGraph (void);


};