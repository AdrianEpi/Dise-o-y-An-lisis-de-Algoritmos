#include <vector>
#include <string>
#include <cmath>
#include <iostream>
class LCS {

	private:
		char X_[];
		char Y_[];
		std::vector<std::vector<int>> C;

	public:
		LCS();
		LCS(std::string X, std::string Y);
		~LCS();

		int LCSLength(std::string X, std::string Y);
		std::string backTrack(std::vector<std::vector<int>> C, std::string X, std::string Y, int i, int j);
};