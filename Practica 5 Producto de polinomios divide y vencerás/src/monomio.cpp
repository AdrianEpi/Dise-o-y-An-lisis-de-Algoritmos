/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 5 Producto de polinomios DyV              =
    =            File name:     monomio.cpp                                        =
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
* @Date:   2020-03-11 17:59:36
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-11 22:44:16
*/
/*------------  FUNCTIONS DECLARATION  ------------*/

#include "../include/monomio.hpp"

/*-------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Monomio::Monomio() {
    set_Grade(0);
    set_Coefficient(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  grade        The grade
 * @param[in]  coefficient  The coefficient
 */
Monomio::Monomio(int grade, int coefficient) {
    assert(grade >= 0);
    set_Grade(grade);
    set_Coefficient(coefficient);
}

/**
 * @brief      Destroys the object.
 */
Monomio::~Monomio() {
}

/**
 * @brief      Gets the grade.
 *
 * @return     The grade.
 */
int Monomio::get_Grade(void) const {
    return grade_;
}

/**
 * @brief      Gets the coefficient.
 *
 * @return     The coefficient.
 */
int Monomio::get_Coefficient(void) const {
    return coefficient_;
}

/**
 * @brief      Sets the grade.
 *
 * @param[in]  grade  The grade
 */
void Monomio::set_Grade(int grade) {
    grade_ = grade;
}

/**
 * @brief      Sets the coefficient.
 *
 * @param[in]  coefficient  The coefficient
 */
void Monomio::set_Coefficient(int coefficient) {
    coefficient_ = coefficient;
}

/**
 * @brief      Addition operator.
 *
 * @param[in]  mon1  The monomial 1
 * @param[in]  mon2  The monomial 2
 *
 * @return     The result of the addition
 */
Monomio operator +(const Monomio& mon1, const Monomio& mon2) {
    Monomio aux;
    if(mon1.get_Grade() == mon2.get_Grade()) {
        aux.set_Coefficient(mon1.get_Coefficient() + mon2.get_Coefficient());
        aux.set_Grade(mon1.get_Grade());
    }
    else 
        std::cout << std::endl << "Error, estos monomios no tienen el mismo grado, por lo tanto no se pueden sumar." << std::endl;
    
    return aux; 
}

/**
 * @brief      Subtraction operator.
 *
 * @param[in]  mon1  The monomial 1
 * @param[in]  mon2  The monomial 2
 *
 * @return     The result of the subtraction
 */
Monomio operator -(const Monomio& mon1, const Monomio& mon2) {
    Monomio aux;
    if(mon1.get_Grade() == mon2.get_Grade()) {
        aux.set_Coefficient(mon1.get_Coefficient() - mon2.get_Coefficient());
        aux.set_Grade(mon1.get_Grade());
    }
    else 
        std::cout << std::endl << "Error, estos monomios no tienen el mismo grado, por lo tanto no se pueden sumar." << std::endl;
    
    return aux; 
}

/**
 * @brief      Multiplication operator.
 *
 * @param[in]  mon1  The monomial 1
 * @param[in]  mon2  The monomial 2
 *
 * @return     The result of the multiplication
 */
Monomio operator *(const Monomio& mon1, const Monomio& mon2) {
    Monomio aux;
    aux.set_Grade(mon1.get_Grade() + mon2.get_Grade());
    aux.set_Coefficient(mon1.get_Coefficient() * mon2.get_Coefficient());
    return aux; 
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  mon1  The monomial 1
 */
void Monomio::operator =(const Monomio& mon1) {
    set_Coefficient(mon1.get_Coefficient());
    set_Grade(mon1.get_Grade());
}

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os    The output stream.
 * @param[in]  mon   The monomial
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator <<(std::ostream& os, const Monomio& mon) {
    if(mon.get_Grade() > 1)
        os << mon.get_Coefficient() << "x^" << mon.get_Grade();
    else if(mon.get_Grade() == 1)
        os << mon.get_Coefficient() << "x";
    else if(mon.get_Coefficient() != 0)
        os << mon.get_Coefficient();
}

/**
 * @brief      Writes the monomial
 *
 * @param      os    The output stream.
 */
void Monomio::write(std::ostream& os) {
    os << *this;
}
