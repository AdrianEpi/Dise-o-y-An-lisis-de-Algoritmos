/*
* @Author: Adrián Epifanio
* @Date:   2020-03-27 10:24:01
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-27 11:47:45
*/
#include "../include/lcs.hpp"
#include <iostream>
#include <cstring>
int main() 
{ 
	std::string string1, string2;
	std::cout << std::endl << "Introduce the first secuence: ";
	std::cin >> string1;
	std::cout << std::endl << "Introduce the second secuence: ";
	std::cin >> string2;

	LCS test(string1, string2);
} 
