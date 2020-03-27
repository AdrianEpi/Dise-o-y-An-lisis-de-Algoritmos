/*
* @Author: Adrián Epifanio
* @Date:   2020-03-27 10:24:01
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-27 13:42:50
*/
#include "../include/lcs.hpp"

int main(void) { 
	std::string string1 = " ", string2 = " ", aux;
	std::cout << std::endl << "Introduce the first secuence: ";
	std::cin >> aux;
	string1 += aux;
	std::cout << std::endl << "Introduce the second secuence: ";
	std::cin >> aux;
	string2 += aux;

	LCS test(string1, string2);
} 
