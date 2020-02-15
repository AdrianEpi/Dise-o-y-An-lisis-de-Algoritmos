// A 'MultiplyStrategy' class
class Multiply_Trans : public Strategy  
{
	void AlgorithmInterface(int matrix_A[][MAX_AMMOUNT], int matrix_B[][MAX_AMMOUNT], int matrix_C[][MAX_AMMOUNT], int rows_[], int columns_[]) 
	{
		int a = rows_[1];
		rows_[1] = columns_[1];
		columns_[1] = a;
		for (int i = 0; i < rows_[0]; i++)
			for (int j = 0; j < rows_[1]; j++)
				for (int k = 0; k < columns_[0]; k++)
					matrix_C[i][j] = matrix_C[i][j] + matrix_A[i][k] * matrix_B[k][j];

	    /* for(int x=0;x<3;x++)  // loop 3 times for three lines
		{
			for(int y=0;y<3;y++)  // loop for the three elements on the line
			{
				cout<< matrix_C[x][y] << " ";  // display the current element out of the array
			}
		cout<<endl;  // when the inner loop is done, go to a new line
		}*/
	}
};