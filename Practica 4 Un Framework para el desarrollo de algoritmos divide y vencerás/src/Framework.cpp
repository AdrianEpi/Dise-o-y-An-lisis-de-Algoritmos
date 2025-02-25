/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     Framework.cpp                                      =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-05 08:29:24
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 08:32:45
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/Framework.h"

/*-------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Framework::Framework() 
{
}


/**
 * @brief      Destroys the object.
 */
Framework::~Framework() 
{
}


/**
 * @brief      Divide and Conquer framework to solve the problem
 *
 * @param      p     Problem object
 * @param      s     Solution object
 */
void Framework::divideyVenceras(Problema* p, Solucion* s)
{
	if (p->isCasoMinimo())
		p->solver(s);

	else
	{
		pair<Problema*,Problema*> subProblemas;
		pair<Solucion*,Solucion*> subSoluciones;
		subProblemas = p->descomponer();
		subSoluciones.first = s->getInstance();
		subSoluciones.second = s->getInstance();
		divideyVenceras(subProblemas.first, subSoluciones.first);  //.1
		divideyVenceras(subProblemas.second, subSoluciones.second);  //.2
		s->mezcla(subSoluciones);
	}
};

