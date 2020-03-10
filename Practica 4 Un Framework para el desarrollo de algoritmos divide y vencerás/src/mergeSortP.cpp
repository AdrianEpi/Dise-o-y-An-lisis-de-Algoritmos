/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     mergeSortp.cpp                                     =
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
* @Date:   2020-03-05 12:25:17
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 08:41:02
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/mergeSortP.h"

/*-------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  vector  The vector
 */
MergeSortP::MergeSortP(vector<int> vector) : Problema::Problema()
{
	vectorToSort = vector;
}

/**
 * @brief      Destroys the object.
 */
MergeSortP::~MergeSortP()
{
	vectorToSort.clear();
}

/**
 * @brief      Determines if minimum case.
 *
 * @return     True if minimum case, False otherwise.
 */
bool MergeSortP::isCasoMinimo()
{
	return (vectorToSort.size() <= 2);
}

/**
 * @brief      Divides the problem in 2 halfs
 *
 * @return     The 2 subProblems divided
 */
pair<Problema *, Problema *> MergeSortP::descomponer()
{
	pair<Problema *, Problema *> subProblem;
	vector<int> primeraMitad, segundaMitad;
	primeraMitad.resize(round(vectorToSort.size() / 2));
	segundaMitad.resize(vectorToSort.size() - primeraMitad.size());

	for (int i = 0; i < primeraMitad.size(); i++)
		primeraMitad[i] = vectorToSort[i];

	for (int j = 0; j < segundaMitad.size(); j++)
		segundaMitad[j] = vectorToSort[primeraMitad.size() + j];

	subProblem.first = new MergeSortP(primeraMitad);
	subProblem.second = new MergeSortP(segundaMitad);
	return subProblem;
}

/**
 * @brief      Solves the problem
 *
 * @param      s     The solution
 */
void MergeSortP::solver(Solucion *s)
{ 
	if (vectorToSort.size() == 1)
		((MergeSortS *)s)->setValor(vectorToSort);

	else
	{
		if (vectorToSort[0] > vectorToSort[1])
		{
			int temp = vectorToSort[0];
			vectorToSort[0] = vectorToSort[1];
			vectorToSort[1] = temp;
		}
		((MergeSortS *)s)->setValor(vectorToSort);
	}
}
