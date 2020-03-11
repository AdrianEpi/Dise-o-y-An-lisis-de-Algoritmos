/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 5 Producto de polinomios DyV              =
    =            File name:     polinomio.hpp                                      =
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
#include "monomio.hpp"
#include <vector>
class Polinomio {

    private:
        std::vector<Monomio> polinomio_;

    public:
        // Builders & Destroyer
        Polinomio();
        Polinomio(Monomio mon);
        ~Polinomio();

        // Getters & Setters
        std::vector<Monomio> get_Polinomio(void) const;
        int get_Grade(void) const;
        Monomio get_Monomio(int grade) const;

        void set_Polinomio(std::vector<Monomio> polinomio);
        void set_Grade(void);
        void set_Monomio(Monomio mon);

        // Operators overload
        friend Polinomio operator +(const Polinomio& mon1, const Polinomio& mon2);
        friend Polinomio operator -(const Polinomio& mon1, const Polinomio& mon2);
        friend Polinomio operator *(const Polinomio& mon1, const Polinomio& mon2);
        void operator =(const Polinomio& mon1);
        friend std::ostream& operator <<(std::ostream& os, const Polinomio& mon);

        // Functions
        void resize(int size);
        void destroy(void);
        void introduceMonomio(Monomio mon);
        void eraseMonomio(Monomio mon);

        // Write
        void write(std::ostream& os);

};