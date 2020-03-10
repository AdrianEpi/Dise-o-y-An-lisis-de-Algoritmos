/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     mergeSortP.h                                       =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         05/03/2020                                         =
    =            Subject:       Diseño y Análisis de Algoritmos                    =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*-----------  FUNCTIONS DECLARATION  ------------*/

#ifndef MERGESORTP_H_
#define MERGESORTP_H_
#include "Problema.h"
#include "mergeSortS.h"
#pragma once

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <vector>
#include <cmath> 

/*------------------------------------------------*/


class MergeSortP : public Problema 
{

	private:
		vector<int> vectorToSort;
		
	public:
		MergeSortP(vector<int> vector);
		virtual ~MergeSortP();

		bool isCasoMinimo();
		pair<Problema *, Problema *> descomponer();
		void solver(Solucion *s);
};

#endif /* MERGESORTP_H_ */
