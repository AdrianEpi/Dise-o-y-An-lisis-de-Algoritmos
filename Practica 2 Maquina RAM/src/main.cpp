/*
* @Author: Adrián Epifanio
* @Date:   2020-02-15 10:32:10
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-29 17:07:39
*/

#include "../include/machineRAM.hpp"
#include "functions.cpp"

int main(int argc, char *argv[])
{
	std::string aux(argv[4]);
	if((argc != 5) || ((aux != "1") && (aux != "0")))
	{
		std::cout << std::endl << "Error en la entrada del programa" << std::endl;
		help();
	}
	else
	{
		std::string instructionFileName(argv[1]);
		std::string inputTapeFileName(argv[2]);
		std::string outputTapeFileName(argv[3]);
		MachineRAM ram(instructionFileName, inputTapeFileName, outputTapeFileName);
		if(aux == "1")
			menu(ram);
		else
		{
			ram.loadData();
			ram.runProgram();
			std::cout << std::endl << "El numero total de instrucciones ejecutadas es: " << ram.get_NumberOfInstructions() << std::endl;
		}

	}
}



