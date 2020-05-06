/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Practica 8 Max-Mean Problem                        =
    =            File name:     graph.cpp                                          =
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
* @Date:   2020-04-15 20:01:17
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-05-06 17:16:19
*/
/*----------  DECLARACION DE FUNCIONES  ----------*/

#include "../include/graph.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Graph::Graph() {
	//std::cout << std::endl << "ERROR, a Graph requires a texfile for a correct generation" << std::endl;
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  textFile  The text file
 */
Graph::Graph(std::string textFile) {
	set_TextFile(textFile);
}

/**
 * @brief      Destroys the object.
 */
Graph::~Graph() {
}

/**
 * @brief      Gets the vertex.
 *
 * @return     The vertex.
 */
std::vector<Vertex> Graph::get_Vertex(void) const {
	return vertex_;
}


/**
 * @brief      Gets the text file.
 *
 * @return     The text file.
 */
std::string Graph::get_TextFile(void) const {
	return textFile_;
}

/**
 * @brief      Gets the vertex number.
 *
 * @return     The vertex number.
 */
int Graph::get_VertexNum (void) const {
	return vertexNum_;
}

/**
 * @brief      Gets the coordinates number.
 *
 * @return     The coordinates number.
 */
int Graph::get_CoordinatesNum (void) const {
	return coordinatesNum_;
}

/**
 * @brief      Sets the vertex.
 *
 * @param[in]  vertex  The vertex
 */
void Graph::set_Vertex(std::vector<Vertex> vertex) {
	vertex_ = vertex;
}

/**
 * @brief      Sets the text file.
 *
 * @param[in]  textFile  The text file
 */
void Graph::set_TextFile(std::string textFile) {
	textFile_ = textFile;
}

/**
 * @brief      Sets the vertex number.
 *
 * @param[in]  vertexNum  The vertex number
 */
void Graph::set_VertexNum (int vertexNum) {
	vertexNum_ = vertexNum;
}

/**
 * @brief      Sets the coordinates number.
 *
 * @param[in]  coordinatesNum  The coordinates number
 */
void Graph::set_CoordinatesNum (int coordinatesNum) {
	coordinatesNum_ = coordinatesNum;
}

/**
 * @brief      Generates the graph from the textfile give to the constructor
 */
void Graph::generateGraph(void) {
	std::ifstream textfile;
	textfile.open(get_TextFile());
	int readInt;
	float readFloat;
	if (textfile.is_open()) {
		while (!textfile.eof()) {
			textfile >> readInt;
			assert(readInt > 0);
			set_VertexNum(readInt);
			textfile >> readInt;
			assert(readInt > 0);
			set_CoordinatesNum(readInt);
			for (int i = 0; i < get_VertexNum(); i++) {
				Vertex newVertex(i);
				for (int j = 0; j < get_CoordinatesNum(); j++) {
					textfile >> readFloat;
					newVertex.addCoordinate(readFloat);
				}
				vertex_.push_back(newVertex);
			}
		}
		textfile.close();
	}
	else {
		std::cout << std::endl << "Error 404, not file found" << std::endl;
		exit(0);
	}
}

/**
 * @brief      Prints the graph by console.
 */
void Graph::printGraph(void) {
	char LETTERS[] = {'x', 'y', 'z', 'w', 't', 's'};
	for (int i = 0; i < vertex_.size(); i++) {
		std::string node = vertex_[i].get_Name();
		node += "\n";
		for (int j = 0; j < get_CoordinatesNum(); j++) {
			char tmp = LETTERS[j];
			node = node + "\t\tCoordinate " + LETTERS[j] + " -> " + std::to_string(vertex_[i].get_Coordinates()[j]) + '\n';
		}
		node += "\n";
		std::cout << node;
	}
}
