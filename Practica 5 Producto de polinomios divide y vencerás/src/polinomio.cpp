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
* @Last Modified time: 2020-03-11 23:03:36
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../include/polinomio.hpp"

/*-------------------------------------------------*/



Polinomio::Polinomio() {
	Monomio empty(0, 0);
	polinomio_.push_back(empty);
}

Polinomio::Polinomio(Monomio mon) {
	resize(mon.get_Grade() - 1);
	polinomio_.push_back(mon);
}

Polinomio::~Polinomio() {
}

std::vector<Monomio> Polinomio::get_Polinomio(void) const {
	return polinomio_;
}

int Polinomio::get_Grade(void) const {
	return polinomio_.size();
}

Monomio Polinomio::get_Monomio(int grade) const {
	return polinomio_[grade];
}

void Polinomio::set_Polinomio(std::vector<Monomio> polinomio) {
	destroy();
	resize(polinomio.size());

	polinomio_ = polinomio;
}

void Polinomio::set_Monomio(Monomio mon) {
	if(get_Grade() < mon.get_Grade())
		resize(mon.get_Grade());

	polinomio_[mon.get_Grade()] = mon;
}

Polinomio operator +(const Polinomio& polin1, const Polinomio& polin2) {
	int grade;
	if(polin1.get_Grade() >= polin2.get_Grade())
		grade = polin1.get_Grade();
	else
		grade = polin2.get_Grade();

	Polinomio aux;
	aux.resize(grade);
	for(int i = 0; i < grade; i++) {
		aux.get_Polinomio()[i] = polin1.get_Polinomio()[i] + polin2.get_Polinomio()[i];
	}
	return aux;
}

Polinomio operator -(const Polinomio& polin1, const Polinomio& polin2) {
	int grade;
	if(polin1.get_Grade() >= polin2.get_Grade())
		grade = polin1.get_Grade();
	else
		grade = polin2.get_Grade();

	Polinomio aux;
	aux.resize(grade);
	for(int i = 0; i < grade; i++) {
		aux.get_Polinomio()[i] = polin1.get_Polinomio()[i] - polin2.get_Polinomio()[i];
	}
	return aux;
}

Polinomio operator *(const Polinomio& polin1, const Polinomio& polin2) {

}

void Polinomio::operator =(const Polinomio& polin1) {
	destroy();
	polinomio_.resize(polin1.get_Grade());
	for(int i = 0; i < get_Grade(); i++) 
		polinomio_[i] = polin1.get_Polinomio()[i];
}

std::ostream& operator <<(std::ostream& os, const Polinomio& polin) {
	for(int i = 0; i < polin.get_Grade(); i++)
		if(polin.get_Polinomio()[i].get_Coefficient() != 0)
			os << " " << polin.get_Polinomio()[i];
}

void Polinomio::resize(int size) {
	while(get_Grade() <= size) {
		Monomio empty(0, 0);
		polinomio_.push_back(empty);
	}
}

void Polinomio::destroy(void) {
	polinomio_.resize(0);
}

void Polinomio::introduceMonomio(Monomio mon) {
	if(get_Grade() < mon.get_Grade())
		resize(mon.get_Grade());

	if(polinomio_[mon.get_Grade()].get_Coefficient() == 0)
		polinomio_[mon.get_Grade()] = mon;
	else {
		std::cout << std::endl << "Warning, esa posicion ya existe, se sumarán ambos monomios";
		polinomio_[mon.get_Grade()] = polinomio_[mon.get_Grade()] + mon;
	}
}

void Polinomio::eraseMonomio(Monomio mon) {
	if(mon.get_Grade() == get_Grade())
		polinomio_.resize(polinomio_.size() -1);
	else
		polinomio_[mon.get_Grade()].set_Coefficient(0);
}

void Polinomio::write(std::ostream& os) {
	os << *this;
}