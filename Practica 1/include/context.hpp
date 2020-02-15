#include "strategy.hpp"
// The 'Context' class
class Context 
{
    private:
		Strategy *_strategy;
    public:
        // Constructor
        Context(Strategy *strategy);
 
		void MultiplyInterface(int matrix_A[][MAX_AMMOUNT], int matrix_B[][MAX_AMMOUNT], int matrix_C[][MAX_AMMOUNT], int rows_[], int columns_[]);

};