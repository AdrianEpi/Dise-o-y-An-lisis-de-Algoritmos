/*
* @Author: Adrián Epifanio
* @Date:   2020-03-27 10:25:12
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-27 11:45:58
*/
#include "../include/lcs.hpp"
LCS::LCS() {

}

LCS::LCS(std::string X, std::string Y) {
	LCSLength(X, Y);
}

LCS::~LCS() {

}

int LCS::LCSLength(std::string X, std::string Y) {
	std::vector<std::vector<int>> C;
	C.resize(X.size());
	for (int i = 0; i < X.size(); ++i) {
		C[i].resize(Y.size());
		C[i][0] = 0;
	}
	for (int i = 0; i < Y.size(); ++i) {
		C[0][i] = 0;
	}

	for (int i = 1; i < X.size(); ++i) {
		for (int j = 1; j < Y.size(); ++j) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else 
				C[i][j] = std::max(C[i][j - 1], C[i - 1][j]);
		}
	}
	std::cout << std::endl <<  C[X.size() - 1][Y.size() - 1] + 1 << std::endl;
	return (C[X.size() - 1][Y.size() - 1]) + 1;
}
