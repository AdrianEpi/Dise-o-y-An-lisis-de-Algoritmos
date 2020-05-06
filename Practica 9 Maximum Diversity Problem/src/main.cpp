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
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-06 16:25:44
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Framework.hpp"

/*------------------------------------------------*/
int main(int argc, char *argv[]) {
    srand(time(NULL));
    if((argc != 2)) {
        std::cout << std::endl << "Error en la entrada del programa" << std::endl;
        exit(0);
    }
    std::string fileName(argv[1]);
    FrameWork maxMeanDispersionProblem(fileName);
    maxMeanDispersionProblem.initialize();
    //maxMeanDispersionProblem.executeFrameWork();
}