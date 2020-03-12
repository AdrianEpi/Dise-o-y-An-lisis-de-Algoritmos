/*=======================================================================================
=========================================================================================
	=                                                                              =
	=            Proyect:       Practica 5 Producto de polinomios DyV              =
	=            File name:     monomio.hpp                                        =
	=            Author:        Adrián Epifanio Rodríguez Hernández                =
	=            Fecha:         11/03/2020                                         =
	=            Subject:       Diseño y Análisis de Algoritmos                    =
	=            Language:      C++                                                =
	=            Email:         alu0101158280@ull.edu.es                           =
	=            Place:         Universidad De La Laguna                           =
	=                           Escuela Superior de Ingeniería y Tecnología        =
	=                                                                              =
=========================================================================================
=======================================================================================*/
/*------------  LIBRARY DECLARATION  ------------*/

#include <iostream>
#include <cassert>
#include <math.h>

/*------------------------------------------------*/

class Monomio {

	private:
		int grade_;
		int coefficient_;

	public:
		// Builders & Destroyer
		Monomio();
		Monomio(int grade, int coefficient);
		~Monomio();

		// Getters & Setters
		int get_Grade(void) const;
		int get_Coefficient(void) const;

		void set_Grade(int grade);
		void set_Coefficient(int coefficient);

		// Operators overload
		friend Monomio operator +(const Monomio& mon1, const Monomio& mon2);
		friend Monomio operator -(const Monomio& mon1, const Monomio& mon2);
		friend Monomio operator *(const Monomio& mon1, const Monomio& mon2);
		void operator =(const Monomio& mon1);
		friend std::ostream& operator <<(std::ostream& os, const Monomio& mon);
		friend std::istream& operator >>(std::istream& is, Monomio& mon);

		// Functinos
		int evaluar(int xValue) const;

		// Write
		void write(std::ostream& os);

};