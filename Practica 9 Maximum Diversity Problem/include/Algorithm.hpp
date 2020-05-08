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
		float diversity_;
		std::vector<Vertex> freeVertex_;
		int solutionSize_;

	public:
		// Builders & Destroyer
		Algorithm ();
		virtual ~Algorithm ();

		// Getter & Setter
		std::vector<Vertex> get_Solution (void) const;
		float get_Diversity (void) const;
		std::vector<Vertex>& get_FreeVertex (void);
		int get_SolutionSize (void) const;

		void set_Solution (std::vector<Vertex> solution);
		void set_Diversity (float diversity);
		void set_FreeVertex (std::vector<Vertex> freeElements);
		void set_SolutionSize (int size);

		// Functions
		virtual void runAlgorithm (Graph& graph, Chrono& chrono);
		std::ostream& printResult (std::ostream& os, Chrono& chrono);
		float findDiversity (std::vector<Vertex>& vertex);
		Vertex generateGravityCenter (std::vector<Vertex>& vertex);
		int findFurthestFromGravityCenter (std::vector<Vertex>& vertex, Vertex& gravityCenter);
		int getPositionFromVector (std::vector<Vertex>& vertex, int vertexNum);

		// Enviroment Structures
		void addition (std::vector<Vertex>& vertex, int& vertexNum);
		void swap (std::vector<Vertex>& vertex, int& vertexNum, int& freeVertexNum);
		void extraction (std::vector<Vertex>& vertex, int& vertexNum);
		int getRandomVertex (std::vector<Vertex>& vector);
};