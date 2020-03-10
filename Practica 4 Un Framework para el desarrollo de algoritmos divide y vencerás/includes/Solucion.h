/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     Solucion.h                                         =
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

#ifndef SOLUCION_H_
#define SOLUCION_H_
using namespace std;

/*------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include<vector>
#include <utility>
#include<iostream>

/*------------------------------------------------*/


class Solucion 
{
	
	public:
		Solucion();
		virtual ~Solucion();

		virtual void resolver();
		virtual void mezcla(pair<Solucion*,Solucion*>);
		virtual Solucion* getInstance();
};

#endif /* SOLUCION_H_ */
