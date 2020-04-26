/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     main.cpp                                           =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         03/04/2020                                         =
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
* @Date:   2020-04-03 20:28:44
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-26 12:49:53
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/vertex.hpp"
#include "../include/edge.hpp"
#include "../include/graph.hpp"
#include "../include/Framework.hpp"

/*------------------------------------------------*/
int main() {
    srand(time(NULL));
    std::string asd = "../inputs/max-mean-div-20.txt";
    FrameWork a(asd);
    a.initialize();
    a.executeFrameWork();
}