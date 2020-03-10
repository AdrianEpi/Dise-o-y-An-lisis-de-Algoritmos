/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 4 Framework para desarrollo de DyV        =
    =            File name:     main.cpp                                           =
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
* @Date:   2020-03-05 08:39:02
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-10 12:25:58
*/ 
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../includes/Framework.h"
#include "../includes/mergeSortP.h"
#include "../includes/mergeSortS.h"
#include "../includes/quickSortP.h"
#include "../includes/quickSortS.h"

/*-------------------------------------------------*/
/*------------  LIBRARY DECLARATION  ------------*/

#ifndef MAIN_
#define MAIN_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>

/*------------------------------------------------*/

void help();
void mergeSort(vector<int> vectorToSort);
void quickSort(vector<int> vectorToSort);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		help();
		exit(0);
	}

	vector<int> vectorToSort;
	vectorToSort.resize(atoi(argv[2]));
	int ordenacion = atoi(argv[1]);
	srand(time(NULL));
	chrono::time_point<chrono::system_clock> start, end;
	int timer;
	cout << "Vector a ordenar:" << endl << "[ ";
	int ramdom_number;

	for (int i = 0; i < vectorToSort.size(); i++)
	{
		ramdom_number = rand() % 1000;		
		vectorToSort[i] = ramdom_number;			

		cout << vectorToSort[i];
		if(i != vectorToSort.size() - 1)
			cout <<  ", ";
	}
	cout << " ]" << endl;

	switch (ordenacion)
	{
	case 1:
		cout << "\n Merge Sort  " << endl;
		start = chrono::system_clock::now();
		mergeSort(vectorToSort);
		end = chrono::system_clock::now();
		timer = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << "\nTiempo transcurrido: " << timer << " microsegundos" << endl;
		break;

	case 2:
		cout << "\n Quick Sort  " << endl;
		start = chrono::system_clock::now();
		quickSort(vectorToSort);
		end = chrono::system_clock::now();
		timer = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << "\nTiempo transcurrido: " << timer << " microsegundos" << endl;
		break;

	default:
		cout << "Opción no reconocida" << endl;
		help();
	}
};


/**
 * @brief      Prints on screen the help option of the program
 */
void help()
{
	cout << "Se requiere de 2 parámetros:" << endl;
	cout << "\tParámetro 1. Tipo de ordenación:" << endl;
	cout << "\t\t1. MergeSort" << endl;
	cout << "\t\t2. QuickSort" << endl;
	cout << "\tParámetro 2. Tamaño del vector a ordenar" << endl;
	cout << "./framework <ordenacion> <tamaño>" << endl;
}


/**
 * @brief      Solves the problem using mergeSort
 *
 * @param[in]  vectorToSort  The vector to sort
 */
void mergeSort(vector<int> vectorToSort)
{
	Problema *problema = new MergeSortP(vectorToSort);
	Solucion *solucion = new MergeSortS();
	Framework *framework = new Framework();
	framework -> divideyVenceras(problema, solucion);
	cout << "Resultado:" << endl;
	solucion -> resolver();
}


/**
 * @brief      Solves the problem using quickSort
 *
 * @param[in]  vectorToSort  The vector to sort
 */
void quickSort(vector<int> vectorToSort)
{
	Problema *problema = new QuickSortP(vectorToSort);
	Solucion *solucion = new QuickSortS();
	Framework *framework = new Framework();

	framework -> divideyVenceras(problema, solucion);
	cout << "Resultado:" << endl;
	solucion -> resolver();
}


#endif /* MAIN_ */