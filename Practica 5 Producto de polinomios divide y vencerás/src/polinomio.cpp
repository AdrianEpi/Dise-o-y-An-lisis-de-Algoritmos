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
* @Last Modified time: 2020-03-16 17:17:02
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
 * @brief      Constructs a new instance.
 *
 * @param[in]  polyn  The polyn
 * @param[in]  i      Vector initial position
 * @param[in]  j      Vector final position
 */
Polinomio::Polinomio(std::vector<Monomio> polyn, int i, int j) {
	resize(j - i);
	for(int k = 0; k < (j - i); k++) {
		polinomio_[k].set_Coefficient(polyn[k + i].get_Coefficient());
		polinomio_[k].set_Grade(polyn[k + i].get_Grade());
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
	return (polinomio_.size() - 1);
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
	Polinomio aux;
	aux.resize(std::max(polyn1.get_Grade(), polyn2.get_Grade()));
	for(int i = 0; i < polyn1.get_Grade(); i++) 
		for(int j = 0; j < polyn2.get_Grade(); j++) 
			if(polyn1.get_Polinomio()[i].get_Grade() == polyn2.get_Polinomio()[j].get_Grade()) {
				Monomio mon;
				mon = polyn1.get_Polinomio()[i] + polyn2.get_Polinomio()[j];
				aux.introduceMonomio(mon);
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
	Polinomio aux;
	aux.resize(std::max(polyn1.get_Grade(), polyn2.get_Grade()));
	for(int i = 0; i < polyn1.get_Grade(); i++) 
		for(int j = 0; j < polyn2.get_Grade(); j++) 
			if(polyn1.get_Polinomio()[i].get_Grade() == polyn2.get_Polinomio()[j].get_Grade()) {
				Monomio mon;
				mon = polyn1.get_Polinomio()[i] - polyn2.get_Polinomio()[j];
				aux.introduceMonomio(mon);
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
std::ostream& operator <<(std::ostream& os, const Polinomio& polyn) {
	for(int i = polyn.get_Grade() - 1; i >= 0; i--) {
		if(polyn.get_Polinomio()[i].get_Coefficient() != 0)
			os << " " << polyn.get_Polinomio()[i];
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


Polinomio Polinomio::algorithmDyV(const Polinomio& polyn1, const Polinomio& polyn2, int i, int j) {
	Polinomio aux;
	if((j - i) <= 1) {
		std::cout << std::endl << "caso base" << i << " " << j << std::endl;
		Monomio mon;
		mon = polyn1.get_Polinomio()[i] * polyn2.get_Polinomio()[i];
		aux.introduceMonomio(mon);
		aux.write(std::cout);
	}
	else {

		int half = round((std::max(polyn2.get_Grade(), polyn1.get_Grade()) / 2));
		Polinomio pl(polyn1.get_Polinomio(), i, polyn1.get_Grade() / 2);
		Polinomio ph(polyn1.get_Polinomio(), (polyn1.get_Grade() / 2), polyn1.get_Grade());
		Polinomio ql(polyn2.get_Polinomio(), i, polyn2.get_Grade() / 2);
		Polinomio qh(polyn2.get_Polinomio(), (polyn2.get_Grade() / 2), polyn2.get_Grade());
		
		std::cout << std::endl << "pl: " << std::endl;
		pl.write(std::cout);
		std::cout << std::endl << "ph: " <<  std::endl;
		ph.write(std::cout);
		std::cout << std::endl << "ql: " << std::endl;
		ql.write(std::cout);
		std::cout << std::endl << "qh: " << std::endl;
		qh.write(std::cout);
		std::cout << std::endl << std::endl;
		
		char z;
		std::cin >> z;
		Polinomio p, q, r;
		p.algorithmDyV(pl, ql, i, half);
		q.algorithmDyV(ph, qh, half + 1, j);
		r.algorithmDyV((pl + ph), (ql + qh), i, j);
		aux = p + (r - p - q) + q;
	}
	return aux;
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