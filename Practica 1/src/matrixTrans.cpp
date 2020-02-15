using namespace std;
#define MAX_AMMOUNT 501
// The 'Matrix' Class
class Traspuesta
{
	public:
		int newMatrix[MAX_AMMOUNT][MAX_AMMOUNT];

	public:

		void trasponer(int matrix_B[][MAX_AMMOUNT], int rows_[], int columns_[])
		{
			for (int i = 0; i < columns_[1]; i++)
			{
				for (int j = 0; j < rows_[1]; j++)
				{
					newMatrix[j][i] = matrix_B[i][j];
				}
			}
		};
};