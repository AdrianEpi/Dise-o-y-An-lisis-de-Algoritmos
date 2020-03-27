#include <vector>
#include <string>
#include <cmath>
#include <iostream>
class LCS {

	private:
		char X_[];
		char Y_[];
		std::vector<std::vector<int>> table_;

	public:
		LCS();
		LCS(std::string X, std::string Y);
		~LCS();

		int LCSLength(std::string X, std::string Y);
		//void backTrack(char C[][], char str1[], char str2[], int i, int j);
};