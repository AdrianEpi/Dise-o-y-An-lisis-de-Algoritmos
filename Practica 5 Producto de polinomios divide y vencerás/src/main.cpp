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
* @Last Modified time: 2020-03-11 23:04:05
*/
#include "../include/polinomio.hpp"
int main() {
	Monomio a(5 ,3);
	Monomio b(5, 4);
	Monomio c;
	a.write(std::cout);
	b.write(std::cout);
	c = (a + b);
	c.write(std::cout);
	std::cout << std::endl << a << std::endl << b * c;
	Polinomio p;
	p.introduceMonomio(a);
	p.introduceMonomio(b);
	p.introduceMonomio(b*c);
	std::cout << std::endl << p;	
}