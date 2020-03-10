/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     mergeSortS.cpp                                     =
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
* @Date:   2020-03-05 12:25:26
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 12:09:43
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/mergeSortS.h"

/*-------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <iostream>

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
MergeSortS::MergeSortS() : Solucion::Solucion()
{
}

/**
 * @brief      Destroys the object.
 */
MergeSortS::~MergeSortS()
{
}

/**
 * @brief      Prints on screen the merge sorted vector
 */
void MergeSortS::resolver()
{
	for (int i = 0; i < vectorToSort.size(); i++)
		if(vectorToSort[i] < vectorToSort[i - 1])
		{
			std::cout <<  "Error, mal ordenado";
			exit(0);
		}
	
	cout << "[ ";
	for (int i = 0; i < vectorToSort.size(); i++)
	{
		cout << vectorToSort[i];
		if(i != vectorToSort.size() - 1)
			std::cout <<  ", ";
	}
		
	cout << " ]" << endl;
}


/**
 * @brief      Attach the 2 solutions
 *
 * @param[in]  subSoluciones  The sub solutions
 */
void MergeSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{
	vector<int> solution1 = (((MergeSortS *)subSoluciones.first))->vectorToSort;
	vector<int> solution2 = ((MergeSortS *)subSoluciones.second)->vectorToSort;
	int firstVectorIterator = 0;
	int secondVectorIterator = 0;
	int resultVectorIterator = 0;
	vectorToSort.resize(solution1.size() + solution2.size());

	while ((firstVectorIterator < solution1.size()) && (secondVectorIterator < solution2.size()))
	{
		if (solution1[firstVectorIterator] < solution2[secondVectorIterator])
		{
			vectorToSort[resultVectorIterator] = solution1[firstVectorIterator];
			firstVectorIterator++;
		}
		else
		{
			vectorToSort[resultVectorIterator] = solution2[secondVectorIterator];
			secondVectorIterator++;
		}
		resultVectorIterator++;
	}

	if (firstVectorIterator < solution1.size())
	{
		for (; firstVectorIterator < solution1.size(); firstVectorIterator++)
		{
			vectorToSort[resultVectorIterator] = solution1[firstVectorIterator];
			resultVectorIterator++;
		}
	}
	else
	{
		for (; secondVectorIterator < solution2.size(); secondVectorIterator++)
		{
			vectorToSort[resultVectorIterator] = solution2[secondVectorIterator];
			resultVectorIterator++;
		}
	}
}

/**
 * @brief      Gets the instance.
 *
 * @return     The instance.
 */
Solucion *MergeSortS::getInstance()
{
	return new MergeSortS();
}

/**
 * @brief      Sets the value.
 *
 * @param[in]  vector  The vector
 */
void MergeSortS::setValor(vector<int> vector)
{
	vectorToSort = vector;
}
