/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 5 Producto de polinomios DyV              =
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
* @Date:   2020-03-11 17:59:57
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-17 08:23:54
*/
#include "../include/polinomio.hpp"
#include <ctime>
#include <chrono>

void help(void);
Polinomio constructPolinomo(int size);

int main(int argc, char *argv[]) {
	if (argc != 4) {
		help();
		exit(0);
	}
	int algoritmo = atoi(argv[3]);
	Polinomio p;
	Polinomio q;
	srand(time(NULL));
	p = constructPolinomo(atoi(argv[1]));
	q = constructPolinomo(atoi(argv[2]));
	std::cout << std::endl << "P(x) = ";
	std::cout << p;
	std::cout << std::endl << "Q(x) = ";
	std::cout << q;
	std::cout << std::endl;
	Polinomio r;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	switch(algoritmo) {
		case 1:
			start = std::chrono::system_clock::now();
			r = p * q;
			end = std::chrono::system_clock::now();
			std::cout << std::endl << "R(x) = ";
			std::cout << r;
			break;

		case 2:
			r.resize(q.get_Grade() + p.get_Grade());
			r.algorithmDyV(p, q, 0, r.get_Grade() - 1);
			break;

		default:
			std::cout << std::endl <<  "Error, el algoritmo seleccionado es incorrecto." << std::endl;
			exit(0);
	}
	int elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "\nCálculo por columnas terminado  " << ctime(&end_time) << "tiempo transcurrido: " << elapsed_seconds << "microsegundos\n";
	

}

void help(void) {
	std::cout << std::endl << "Manual de ayuda al usuario";
	std::cout << std::endl << "Introduzca como parámetros los tamaños de los dos polinomios seguido del tipo de algoritmo";
	std::cout << std::endl << "1 -> Algoritmo clásico.";
	std::cout << std::endl << "2 -> Algoitmo Divide y vencerás.";
	std::cout << std::endl << std::endl << "\t Ejemplo de uso:";
	std::cout << std::endl << "../bin/polinomio tamaño1 tamaño2 tipoAlgoritmo";
	std::cout << std::endl;
}

Polinomio constructPolinomo(int size) {
	int coef[size];
	
	int ramdom_number;
	for (int i = 0; i < size; i++)
		coef[i] = rand() % 20 + 1;
	
	Polinomio polym(coef, size);
	return polym;
}