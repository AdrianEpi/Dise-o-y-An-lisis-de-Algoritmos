/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     Problema.h                                         =
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

#ifndef PROBLEMA_H_
#define PROBLEMA_H_
#include"Solucion.h"
using namespace std;

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include<vector>
#include<utility>
#include<iostream>

/*------------------------------------------------*/


class Problema 
{

	public:
		Problema();
		virtual ~Problema();

		virtual bool isCasoMinimo();
		virtual pair<Problema*,Problema*> descomponer();
		virtual void solver(Solucion* s);
};

#endif /* PROBLEMA_H_ */
