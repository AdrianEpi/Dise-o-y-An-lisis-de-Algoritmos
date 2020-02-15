#include "../include/multiplyColumns.hpp"

void Multiply_Columns::AlgorithmInterface(int matrix_A[][MAX_AMMOUNT], int matrix_B[][MAX_AMMOUNT], int matrix_C[][MAX_AMMOUNT], int rows_[], int columns_[]) 
{
	for (int i = 0; i < columns_[1]; i++)
		for (int j = 0; j < columns_[1]; j++)
			for (int k = 0; k < rows_[1]; k++)
				matrix_C[k][j] = matrix_C[k][j] + matrix_A[k][i] * matrix_B[i][j];

	/*for(int x=0;x<3;x++)  // loop 3 times for three lines
	{
		for(int y=0;y<3;y++)  // loop for the three elements on the line
		{
			cout<< matrix_C[x][y] << " ";  // display the current element out of the array
		}
	cout<<endl;  // when the inner loop is done, go to a new line
	}
	*/
}