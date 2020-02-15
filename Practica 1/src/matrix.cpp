#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <chrono> 
#include <ctime>
#include "../include/matrix.hpp"

using namespace std;

Matrix::Matrix(char filename[]) 
{
	ifstream textfile;
	textfile.open(filename);
	if (textfile.is_open())
	{
		textfile >> rows_[0];
		textfile >> columns_[0];
		for (int i = 0; i < rows_[0]; i++)
			for (int j = 0; j < columns_[0]; j++)
				textfile >> matrix_A[i][j];
		textfile >> rows_[1];
		textfile >> columns_[1];
		for (int i = 0; i < rows_[1]; i++)
			for (int j = 0; j < columns_[1]; j++)
				textfile >> matrix_B[i][j];
	}
	rows_[2] = rows_[1];
	columns_[2] = columns_[0];
	for (int i = 0; i < rows_[2]; i++)
		for (int j = 0; j < columns_[2]; j++)
			matrix_C[i][j] = 0;

	tras_.trasponer(matrix_B, rows_, columns_);
}
