// The 'Strategy' abstract class
class Strategy
{
	public: 
	virtual void AlgorithmInterface(int matrix_A[][MAX_AMMOUNT], int matrix_B[][MAX_AMMOUNT], int matrix_C[][MAX_AMMOUNT], int rows_[], int columns_[]) = 0;
};