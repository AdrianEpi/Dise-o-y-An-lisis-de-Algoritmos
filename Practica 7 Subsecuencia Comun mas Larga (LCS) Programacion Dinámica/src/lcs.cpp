/*
* @Author: Adrián Epifanio
* @Date:   2020-03-27 10:25:12
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-27 13:42:28
*/
#include "../include/lcs.hpp"

/**
 * @brief      Constructs a new instance.
 */
LCS::LCS() {

}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  X     String X
 * @param[in]  Y     String Y
 */
LCS::LCS(std::string X, std::string Y) {
	LCSLength(X, Y);
	std::string subsecuence = backTrack(C, X, Y, X.size(), Y.size());
	std::cout << "Subsecuence: " << subsecuence << std::endl;
}

/**
 * @brief      Destroys the object.
 */
LCS::~LCS() {

}

/**
 * @brief      Calculates the length of the subsecuence
 *
 * @param[in]  X     String X
 * @param[in]  Y     String Y
 *
 * @return     LCS length
 */
int LCS::LCSLength(std::string X, std::string Y) {
	C.resize(X.size());
	for (int i = 0; i < X.size(); ++i) {
		C[i].resize(Y.size());
		C[i][0] = 0;
	}
	for (int i = 0; i < Y.size(); ++i) 
		C[0][i] = 0;

	for (int i = 1; i < X.size(); ++i) { 
		for (int j = 1; j < Y.size(); ++j) {
			if (X[i] == Y[j]) 
				C[i][j] = C[i - 1][j - 1] + 1;
			else 
				C[i][j] = std::max(C[i][j - 1], C[i - 1][j]);
		}
	}
	std::cout << std::endl << "Subsecuence size: " << C[X.size() - 1][Y.size() - 1] << std::endl;
	return (C[X.size() - 1][Y.size() - 1]);
}

/**
 * @brief      Calculates the subsecuence of 2 strings
 *
 * @param[in]  C     Vector C
 * @param[in]  X     String X
 * @param[in]  Y     String Y
 * @param[in]  i     Position i
 * @param[in]  j     Position j
 *
 * @return     subsecuence
 */
std::string LCS::backTrack(std::vector<std::vector<int>> C, std::string X, std::string Y, int i, int j) {
	if ((i == 0) || (j == 0)) 
		return "";
	else if (X[i] == Y[j])
		return backTrack(C, X, Y, i - 1, j - 1) + X[i];
	else {
		if (C[i][j - 1] > C[i - 1][j])
			return backTrack(C, X, Y, i, j - 1);
		else
			return backTrack(C, X, Y, i - 1, j);
	}
}
