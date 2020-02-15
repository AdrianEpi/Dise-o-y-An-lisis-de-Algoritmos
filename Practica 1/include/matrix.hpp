using namespace std;
#define MAX_AMMOUNT 501
#include "../src/matrixTrans.cpp"

// The 'Matrix' Class
class Matrix
{
	public:
		// Atributos
		int matrix_A[MAX_AMMOUNT][MAX_AMMOUNT];
		int matrix_B[MAX_AMMOUNT][MAX_AMMOUNT];
		int matrix_C[MAX_AMMOUNT][MAX_AMMOUNT];
		int rows_[2];
		int columns_[2];
		Traspuesta tras_;

	public:
		// Constructor
		Matrix(char filename[]) ;

		~Matrix(){}
};