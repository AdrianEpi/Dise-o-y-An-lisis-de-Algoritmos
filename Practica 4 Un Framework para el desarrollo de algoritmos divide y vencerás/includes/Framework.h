/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     Framework.h                                        =
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

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_
#include "Problema.h"
#include "Solucion.h"
using namespace std;

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include<vector>
#include <utility>
#include<iostream>

/*------------------------------------------------*/


class Framework 
{
	public:
		Framework();
		virtual ~Framework();

		void divideyVenceras(Problema* p, Solucion* s);
};

#endif /* FRAMEWORK_H_ */
