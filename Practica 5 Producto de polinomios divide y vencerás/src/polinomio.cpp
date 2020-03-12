/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 5 Producto de polinomios DyV              =
    =            File name:     polinomio.cpp                                      =
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
/*
* @Author: Adrián Epifanio
* @Date:   2020-03-11 17:59:48
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-12 10:49:36
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../include/polinomio.hpp"

/*-------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Polinomio::Polinomio() {
	Monomio empty(0, 0);
	polinomio_.push_back(empty);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  mon   The monomial
 */
Polinomio::Polinomio(Monomio mon) {
	resize(mon.get_Grade() - 1);
	polinomio_.push_back(mon);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param      coef  The coefficients
 * @param[in]  tam   The size
 */
Polinomio::Polinomio(int coef[], const int tam) {
	resize(tam);
	for(int i = 0; i < tam; i++) {
		polinomio_[i].set_Coefficient(coef[i]);
		polinomio_[i].set_Grade(i);
	}
}
/**
 * @brief      Destroys the object.
 */
Polinomio::~Polinomio() {
	destroy();
}

/**
 * @brief      Gets the polinomio.
 *
 * @return     The polinomio.
 */
std::vector<Monomio> Polinomio::get_Polinomio(void) const {
	return polinomio_;
}

/**
 * @brief      Gets the grade.
 *
 * @return     The grade.
 */
int Polinomio::get_Grade(void) const {
	return polinomio_.size();
}

/**
 * @brief      Gets the monomio.
 *
 * @param[in]  grade  The grade
 *
 * @return     The monomio.
 */
Monomio Polinomio::get_Monomio(int grade) const {
	return polinomio_[grade];
}

/**
 * @brief      Sets the polinomio.
 *
 * @param[in]  polinomio  The polinomio
 */
void Polinomio::set_Polinomio(std::vector<Monomio> polinomio) {
	destroy();
	resize(polinomio.size());

	polinomio_ = polinomio;
}

/**
 * @brief      Sets the monomio.
 *
 * @param[in]  mon   The new value
 */
void Polinomio::set_Monomio(Monomio mon) {
	if(get_Grade() < mon.get_Grade())
		resize(mon.get_Grade());

	polinomio_[mon.get_Grade()] = mon;
}

/**
 * @brief      Addition operator.
 *
 * @param[in]  polyn1  The polynomial 1
 * @param[in]  polyn2  The polynomial 2
 *
 * @return     The result of the addition
 */
Polinomio operator +(const Polinomio& polyn1, const Polinomio& polyn2) {
	int grade;
	if(polyn1.get_Grade() >= polyn2.get_Grade())
		grade = polyn1.get_Grade();
	else
		grade = polyn2.get_Grade();

	Polinomio aux;
	aux.resize(grade);
	for(int i = 0; i < grade; i++) {
		aux.get_Polinomio()[i] = polyn1.get_Polinomio()[i] + polyn2.get_Polinomio()[i];
	}
	return aux;
}

/**
 * @brief      Subtraction operator.
 *
 * @param[in]  polyn1  The polynomial 1
 * @param[in]  polyn2  The polynomial 2
 *
 * @return     The result of the subtraction
 */
Polinomio operator -(const Polinomio& polyn1, const Polinomio& polyn2) {
	int grade;
	if(polyn1.get_Grade() >= polyn2.get_Grade())
		grade = polyn1.get_Grade();
	else
		grade = polyn2.get_Grade();

	Polinomio aux;
	aux.resize(grade);
	for(int i = 0; i < grade; i++) {
		aux.get_Polinomio()[i] = polyn1.get_Polinomio()[i] - polyn2.get_Polinomio()[i];
	}
	return aux;
}

/**
 * @brief      Multiplication operator.
 *
 * @param[in]  polyn1  The polynomial 1
 * @param[in]  polyn2  The polynomial 2
 *
 * @return     The result of the multiplication
 */
Polinomio operator *(const Polinomio& polyn1, const Polinomio& polyn2) {
	Polinomio aux;
	aux.resize(polyn1.get_Grade() + polyn2.get_Grade());
	for(int i = 0; i < polyn1.get_Grade(); i++) {
		for(int j = 0; j < polyn2.get_Grade(); j++) {
			Monomio mon;
			mon = polyn1.get_Polinomio()[i] * polyn2.get_Polinomio()[j];
			aux.introduceMonomio(mon);
		}
	}
	return aux;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  polyn1  The polynomial 1
 */
void Polinomio::operator =(const Polinomio& polyn1) {
	destroy();
	polinomio_.resize(polyn1.get_Grade());
	for(int i = 0; i < get_Grade(); i++) 
		polinomio_[i] = polyn1.get_Polinomio()[i];
}

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os     The output stream
 * @param[in]  polin  The polynomial
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator <<(std::ostream& os, const Polinomio& polin) {
	for(int i = polin.get_Grade() - 1; i >= 0; i--) {
		/*if((polin.get_Polinomio()[i].get_Coefficient() > 0) && (i != (polin.get_Grade() - 1)))
            os << " +";
        else if(polin.get_Polinomio()[i].get_Coefficient() < 0)
        	os << " -";*/
		if(polin.get_Polinomio()[i].get_Coefficient() != 0)
			os << " " << polin.get_Polinomio()[i];
	}
}

/**
 * @brief      Resizes the vector
 *
 * @param[in]  size  The size
 */
void Polinomio::resize(int size) {
	while(get_Grade() <= size) {
		Monomio empty(0, 0);
		polinomio_.push_back(empty);
	}
}

/**
 * @brief      Destroys the object.
 */
void Polinomio::destroy(void) {
	polinomio_.resize(0);
}

/**
 * @brief      Introduces a new monomial
 *
 * @param[in]  mon   The monomial
 */
void Polinomio::introduceMonomio(Monomio mon) {
	if(get_Grade() < mon.get_Grade())
		resize(mon.get_Grade());

	if(polinomio_[mon.get_Grade()].get_Coefficient() == 0)
		polinomio_[mon.get_Grade()] = mon;
	else {
		//std::cout << std::endl << "Warning, esa posicion ya existe, se sumarán ambos monomios";
		polinomio_[mon.get_Grade()] = polinomio_[mon.get_Grade()] + mon;
	}
}

/**
 * @brief      Erases a monomial from the polynomial
 *
 * @param[in]  mon   The monomial
 */
void Polinomio::eraseMonomio(Monomio mon) {
	if(mon.get_Grade() == get_Grade())
		polinomio_.resize(polinomio_.size() -1);
	else
		polinomio_[mon.get_Grade()].set_Coefficient(0);
}

/**
 * @brief      Writes the polynomial by screen
 *
 * @param      os    The output stream
 */
void Polinomio::write(std::ostream& os) {
	os << *this;
}