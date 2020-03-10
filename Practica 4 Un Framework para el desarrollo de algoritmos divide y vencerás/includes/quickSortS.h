/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     quickSortS.h                                       =
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

#ifndef QUICKSORTS_H_
#define QUICKSORTS_H_
#include "Solucion.h"
#pragma once

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <vector>


/*------------------------------------------------*/


class QuickSortS: public Solucion 
{
	
	private:
		vector<int> vectorToSort;

	public:
		QuickSortS();
		virtual ~QuickSortS();

		void resolver();
		void mezcla(pair<Solucion*,Solucion*>);
		Solucion* getInstance();

		void setValor(vector<int> vector);
};

#endif /* QUICKSORTS_H_ */
