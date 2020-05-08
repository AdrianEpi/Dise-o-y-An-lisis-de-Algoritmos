/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 9 Maximum Diversity                       =
    =            File name:     Framework.cpp                                      =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         06/05/2020                                         =
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
* @Date:   2020-04-16 13:28:27
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-08 07:58:02
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/Framework.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
FrameWork::FrameWork () {
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  textFile  The text file
 */
FrameWork::FrameWork (std::string textFile) {
	set_TextFile(textFile);
}

/**
 * @brief      Destroys the object.
 */
FrameWork::~FrameWork () {
}

/**
 * @brief      Gets the graph.
 *
 * @return     The graph.
 */
Graph FrameWork::get_Graph (void) const {
	return graph_;
}

/**
 * @brief      Gets the text file.
 *
 * @return     The text file.
 */
std::string FrameWork::get_TextFile (void) const {
	return textFile_;
}

/**
 * @brief      Gets the algorithm.
 *
 * @return     The algorithm.
 */
Algorithm* FrameWork::get_Algorithm (void) const {
	return algorithm_;
}

/**
 * @brief      Gets the chrono.
 *
 * @return     The chrono.
 */
Chrono FrameWork::get_Chrono (void) const {
	return chrono_;
}

/**
 * @brief      Gets the solution size.
 *
 * @return     The solution size.
 */
int FrameWork::get_SolutionSize (void) const {
	return solutionSize_;
}

/**
 * @brief      Sets the graph.
 *
 * @param[in]  graph  The graph
 */
void FrameWork::set_Graph (Graph graph) {
	graph_ = graph;
}

/**
 * @brief      Sets the text file.
 *
 * @param[in]  textFile  The text file
 */
void FrameWork::set_TextFile (std::string textFile) {
	textFile_ = textFile;
}

/**
 * @brief      Sets the algorithm.
 *
 * @param      algorithm  The algorithm
 */
void FrameWork::set_Algorithm (Algorithm* algorithm) {
	algorithm_ = algorithm;
}

/**
 * @brief      Sets the chrono.
 *
 * @param[in]  chrono  The chrono
 */
void FrameWork::set_Chrono (Chrono chrono) {
	chrono_ = chrono;
}

/**
 * @brief      Sets the solution size.
 *
 * @param[in]  size  The size
 */
void FrameWork::set_SolutionSize (int size) {
	solutionSize_ = size;
}

/**
 * @brief      Initializes the object.
 */
void FrameWork::initialize (void) {
	graph_.set_TextFile(get_TextFile());
	graph_.generateGraph();
	graph_.printGraph();
	int choice = printMenu();
	switch (choice) {
		case 1:
			algorithm_ = new GreedyAlgorithm();
			break;

		case 2:
			algorithm_ = new AnotherGreedyAlgorithm();
			break;

		case 3:
			int RLC, iterations;
			std::cout << std::endl << "Introduce the Restricted Cantidates List (RLC) size: ";
			std::cin >> RLC;
			std::cout << std::endl << "Introduce the number of iterations: ";
			std::cin >> iterations;
			algorithm_ = new GraspAlgorithm(RLC, iterations);
			break;


		case 0:
			std::cout << std::endl << "Aborting program . . ." << std::endl;
			exit(0);
			break;

		default:
			std::cout << std::endl << "Error selecting Algorithm" << std::endl;
			exit(0);
			break;
	}
}

void FrameWork::executeFrameWork (void) {
	algorithm_ -> set_SolutionSize(3);
	algorithm_ -> runAlgorithm(graph_, chrono_);
	algorithm_ -> printResult(std::cout, chrono_);
}

int FrameWork::printMenu (void) {
	std::cout << std::endl << "Please select one of the following Algorithms: ";
	std::cout << std::endl << "\t 1. Greedy Algorithm (Figure)";
	std::cout << std::endl << "\t 2. Greedy Algorithm (Own)";
	std::cout << std::endl << "\t 3. GRASP Algorithm";
	std::cout << std::endl << "\t 0. Abort program";
	std::cout << std::endl;
	int selector;
	std::cin >> selector;
	return selector;
}
