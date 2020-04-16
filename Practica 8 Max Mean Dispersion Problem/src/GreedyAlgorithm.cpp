/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     GreedyAlgorith.cpp                                 =
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
* @Date:   2020-04-03 20:29:34
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-16 18:47:28
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/GreedyAlgorithm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
GreedyAlgorithm::GreedyAlgorithm () {
}

/**
 * @brief      Destroys the object.
 */
GreedyAlgorithm::~GreedyAlgorithm () {
}

/**
 * @brief      Executes the Greedy algorithm
 *
 * @param      graph  The graph
 */
void GreedyAlgorithm::runAlgorithm (Graph& graph) {
    std::vector<Vertex> tempSolution;
    int vertexNumber = findMaxDistance(graph, tempSolution);
    bool found = false;
    
    if (vertexNumber >= 0) {
        tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
    }
    else {
        std::cout << std::endl << "ERROR in GreedyAlgorithm" << std::endl;
    }
    while (found != true) {
        std::cout <<"\n value:" << graph.get_Vertex()[vertexNumber].get_Number();
        vertexNumber = findMaxDistance(graph, tempSolution);
        tempSolution.push_back(graph.get_Vertex()[vertexNumber]);
        if (findMean(tempSolution, graph) < findMean(graph.get_Vertex(), graph)) {
            found = true;
            tempSolution.pop_back();
        }
    }
    set_Solution(tempSolution);
}

/**
 * @brief      Finds a the maximum vertex distance witout being in vector.
 *
 * @param      graph   The graph
 * @param[in]  vertex  The vertex
 *
 * @return     The number of the vertex
 */
int GreedyAlgorithm::findMaxDistance (Graph& graph, std::vector<Vertex> vertex) {
    int vertexNumber = -1;
    int tempMaxMean = STARTMEAN;
    for (int i = 0; i < graph.get_Vertex().size(); i++) {
        for (int edge = 0; edge < graph.get_Edges().size(); edge++) {
            if ((graph.get_Vertex()[i].get_Number() == graph.get_Edges()[edge].get_VertexA())) {
                if (isInVector(graph.get_Vertex()[i].get_Number(), vertex) == false) {
                    if (graph.get_Edges()[edge].get_Distance() > tempMaxMean) {
                        tempMaxMean = graph.get_Edges()[edge].get_Distance();
                        vertexNumber = i;
                    }
                }
            }
        }
    }
    return vertexNumber;
}

/**
 * @brief      Determines if a vertex is in vector.
 *
 * @param[in]  number  The number
 * @param[in]  vertex  The vertex
 *
 * @return     True if in vector, False otherwise.
 */
bool GreedyAlgorithm::isInVector (int number, std::vector<Vertex> vertex) {
    for (int i = 0; i < vertex.size(); i++) {
        if (vertex[i].get_Number() == number) {
            return true;
        }
    }
    return false;
}

std::ostream& GreedyAlgorithm::printResult (std::ostream& os) {
    os << std::endl << get_Solution().size();
    os << std::endl << "Solution: { ";
    for (int i = 0; i < get_Solution().size() - 1; i++) {
        os << get_Solution()[i].get_Number() << ", ";
    }
    os << get_Solution()[get_Solution().size()].get_Number() << " }" << std::endl;
}
