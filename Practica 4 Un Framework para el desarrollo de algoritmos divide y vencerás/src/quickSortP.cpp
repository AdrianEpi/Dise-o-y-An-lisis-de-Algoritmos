/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     quickSortP.cpp                                     =
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
* @Date:   2020-03-05 12:25:39
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 08:43:16
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/quickSortP.h"


/*-------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  vector  The vector
 */
QuickSortP::QuickSortP(vector<int> vector) : Problema::Problema()
{
	vectorToSort = vector;
}

/**
 * @brief      Destroys the object.
 */
QuickSortP::~QuickSortP()
{
	vectorToSort.clear();
}

/**
 * @brief      Determines if minimum case.
 *
 * @return     True if minimum case, False otherwise.
 */
bool QuickSortP::isCasoMinimo()
{
	return (vectorToSort.size() <= 2);
}

/**
 * @brief      Divides the problem
 *
 * @return     The problem divided
 */
pair<Problema *, Problema *> QuickSortP::descomponer()
{
	pair<Problema *, Problema *> subProblemas;
	vector<int> firstPart, secondPart;
	int start = 0;
	int end = vectorToSort.size() - 1;
	int pivot = vectorToSort[round(end / 2)];

	while (start <= end)
	{
		while (vectorToSort[start] < pivot)
			start++;
		
		while (vectorToSort[end] > pivot)
			end--;
		
		if (start <= end)
		{ 
			int temp = vectorToSort[start];
			vectorToSort[start] = vectorToSort[end];
			vectorToSort[end] = temp;
			start++;
			end--;
		}
	}

	for (int i = 0; i <= (start + end) / 2 ; i++)
		firstPart.push_back(vectorToSort[i]);
	
	for (int j = ((start + end) / 2) + 1; j < vectorToSort.size(); j++)
		secondPart.push_back(vectorToSort[j]);
	
	
	subProblemas.first = new QuickSortP(firstPart);
	subProblemas.second = new QuickSortP(secondPart);
	return subProblemas;
}

/**
 * @brief      Solves the problem
 *
 * @param      s     The solution
 */
void QuickSortP::solver(Solucion *s)
{
	if (vectorToSort.size() == 1)
		((QuickSortS *)s)->setValor(vectorToSort);
	
	else
	{
		if (vectorToSort[0] > vectorToSort[1])
		{
			int temp = vectorToSort[0];
			vectorToSort[0] = vectorToSort[1];
			vectorToSort[1] = temp;
		}
		((QuickSortS *)s)->setValor(vectorToSort);
	}
}
