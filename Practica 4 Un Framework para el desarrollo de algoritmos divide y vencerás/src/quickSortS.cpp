/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     quickSortS.cpp                                     =
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
* @Date:   2020-03-09 12:25:51
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 12:09:03
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/quickSortS.h"

/*-------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <iostream>

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
QuickSortS::QuickSortS() : Solucion::Solucion()
{
}

/**
 * @brief      Destroys the object.
 */
QuickSortS::~QuickSortS()
{
}

/**
 * @brief      Solves the problem
 */
void QuickSortS::resolver()
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
 * @brief      Attach the pieces of the problem
 *
 * @param[in]  subSoluciones  The sub soluciones
 */
void QuickSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{
	vector<int> subSol1 = (((QuickSortS *)subSoluciones.first))->vectorToSort;
	vector<int> subSol2 = ((QuickSortS *)subSoluciones.second)->vectorToSort;
	int firstVectorIterator = 0;
	int secondVectorIterator = 0;
	int resultVectorIterator = 0;
	vectorToSort.resize(subSol1.size() + subSol2.size());

	for (int i = 0; i < subSol1.size(); i++) 
	{
		vectorToSort[resultVectorIterator] = subSol1[i];
		resultVectorIterator++;
	}

	for (int j = 0; j < subSol2.size(); j++) 
	{
		vectorToSort[resultVectorIterator] = subSol2[j];
		resultVectorIterator++;
	}
}

/**
 * @brief      Gets the instance.
 *
 * @return     The instance.
 */
Solucion *QuickSortS::getInstance()
{
	return new QuickSortS();
}

/**
 * @brief      Sets the value.
 *
 * @param[in]  vector  The vector
 */
void QuickSortS::setValor(vector<int> vector)
{
	vectorToSort = vector;
}
