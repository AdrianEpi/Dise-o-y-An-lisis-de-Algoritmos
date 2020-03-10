/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     quickSortP.h                                       =
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

#ifndef QUICKSORTP_H_
#define QUICKSORTP_H_
#include "Problema.h"
#include "quickSortS.h"
#pragma once

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <vector>
#include <cmath> 

/*------------------------------------------------*/


class QuickSortP : public Problema
{
	
	private:
		vector<int> vectorToSort;

	public:
		QuickSortP(vector<int> vector);
		virtual ~QuickSortP();

		bool isCasoMinimo();
		pair<Problema *, Problema *> descomponer();
		void solver(Solucion *s);
};

#endif /* QUICKSORTP_H_ */
