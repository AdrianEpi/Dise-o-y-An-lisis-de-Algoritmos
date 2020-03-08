#ifndef MAIN_
#define MAIN_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>

#include "framework/Framework.h"
#include "includes/mergeSortP.h"
#include "includes/mergeSortS.h"
#include "includes/quickSortP.h"
#include "includes/quickSortS.h"
using namespace std;

void help()
{
	cout << "Se requiere de 2 parámetros:" << endl;
	cout << "\tParámetro 1. Tipo de ordenación:" << endl;
	cout << "\t\t1. MergeSort" << endl;
	cout << "\t\t2. QuickSort" << endl;
	cout << "\tParámetro 2. Tamaño del vector a ordenar" << endl;
	cout << "./sort <ordenacion> <tamaño>" << endl;
}

bool isInVector(vector<int> vectorToSort, int value)
{
	for (int i = 0; i < vectorToSort.size(); i++)
	{
		if (vectorToSort[i] == value)
		{
			return true;
		}
	}
	return false;
}

void mergeSort(vector<int> vectorToSort)
{
	Problema *problema = new MergeSortP(vectorToSort);
	Solucion *solucion = new MergeSortS();
	Framework *framework = new Framework();

	framework->divideyVenceras(problema, solucion);
	cout << "Resultado:" << endl;
	solucion->resolver();
}

void quickSort(vector<int> vectorToSort)
{
	Problema *problema = new QuickSortP(vectorToSort);
	Solucion *solucion = new QuickSortS();
	Framework *framework = new Framework();

	framework->divideyVenceras(problema, solucion);
	cout << "Resultado:" << endl;
	solucion->resolver();
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		help();
		exit(-1);
	}

	time_t t;
	srand((unsigned)time(&t));
	vector<int> vectorToSort;
	vectorToSort.resize(atoi(argv[2]));
	int ordenacion = atoi(argv[1]);

	chrono::time_point<chrono::system_clock> start, end;
	int elapsed_seconds;

	cout << "Vector a ordenar:" << endl;
	int evitarRepetidos;
	for (int i = 0; i < vectorToSort.size(); i++)
	{
		evitarRepetidos = rand() % 100 + 1;
		if (isInVector(vectorToSort, evitarRepetidos))
		{
			evitarRepetidos = (evitarRepetidos * rand()) % 100 + 1;
		}

		vectorToSort[i] = evitarRepetidos;

		if (i == 0)
		{
			cout << "[ ";
		}
		if (i == vectorToSort.size() - 1)
		{
			cout << vectorToSort[i] << " ]" << endl;
		}
		else
		{
			cout << vectorToSort[i] << ", ";
		}
	}

	switch (ordenacion)
	{
	case 1:
		cout << "\n----MergeSort---- " << endl;

		start = chrono::system_clock::now();
		mergeSort(vectorToSort);
		end = chrono::system_clock::now();
		elapsed_seconds = chrono::duration_cast<chrono::microseconds>(end - start).count();

		cout << "\nTiempo transcurrido: " << elapsed_seconds << " microsegundos" << endl;
		break;

	case 2:
		cout << "\n----QuickSort---- " << endl;

		start = chrono::system_clock::now();
		quickSort(vectorToSort);
		end = chrono::system_clock::now();
		elapsed_seconds = chrono::duration_cast<chrono::microseconds>(end - start).count();

		cout << "\nTiempo transcurrido: " << elapsed_seconds << " microsegundos" << endl;
		break;

	default:
		cout << "Opción no reconocida" << endl;
		help();
	}
};

#endif /* MAIN_ */
