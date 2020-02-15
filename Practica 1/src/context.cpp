#include "../include/context.hpp"
// The 'Context' class

Context::Context(Strategy *strategy) {
	_strategy = strategy;
}

void Context::MultiplyInterface(int matrix_A[][MAX_AMMOUNT], int matrix_B[][MAX_AMMOUNT], int matrix_C[][MAX_AMMOUNT], int rows_[], int columns_[]) 
{
    _strategy -> AlgorithmInterface(matrix_A, matrix_B, matrix_C, rows_, columns_);
}
