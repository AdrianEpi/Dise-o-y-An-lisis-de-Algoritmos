/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 9 Maximum Diversity                       =
	=            File name:     BranchingAndPruningAlgorithm.hpp                   =
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
#include "Framework.hpp"

/*------------------------------------------------*/

class BranchingAndPruningAlgorithm : public Algorithm {

	private:   
		float upperBound_;
		float lowerBound_;
		int strategy_;  // 0 -> Expands the node with the lowest upperBound 
						// 1 -> Expands the deepest node
		std::vector<Vertex> tmpSolution_;
		std::vector<Vertex> possibleVertex_;

	public:
		// Builder & Destroyer
		BranchingAndPruningAlgorithm ();
		virtual ~BranchingAndPruningAlgorithm ();

		// Getters & Setters
		float get_UpperBound (void) const;
		float get_LowerBound (void) const;
		int get_Strategy (void) const;
		std::vector<Vertex> get_TmpSolution (void) const;
		std::vector<Vertex> get_PossibleVertex (void) const;

		void set_UpperBound (float bound);
		void set_LowerBound (float bound);
		void set_Strategy (int strategy);
		void set_TmpSolution (std::vector<Vertex> tmp);
		void set_PossibleVertex (std::vector<Vertex> possibilities);

		// Public Function
		void runAlgorithm (Graph& graph, Chrono& chrono);

	private:
		//void generateInitialSolution (int algorithm, Graph& graph);
		void expandNodeStrategy1 (std::vector<Vertex> tmp, int pos, float diversity);
		void expandNodeStrategy0 (std::vector<Vertex> tmp, int pos, float diversity);
		bool isValidSolution (std::vector<Vertex>& tmp);
};