/*
* @Author: adria
* @Date:   2020-02-15 10:32:10
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-17 12:13:36
*/

#include "../include/machineRAM.hpp"


int main(int argc, char *argv[])
{
	std::string instructionFileName(argv[1]);
	std::string inputTapeFileName(argv[2]);
	std::string outputTapeFileName(argv[3]);
	MachineRAM ram(instructionFileName, inputTapeFileName, outputTapeFileName);
	ram.loadData();
	ram.writeProgram(std::cout);
}
