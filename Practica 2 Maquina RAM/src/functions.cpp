/*
* @Author: Adrián Epifanio
* @Date:   2020-02-29 16:22:54
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-02-29 18:19:06
*/

void help(void) 
{
	std::cout << std::endl << "MANUAL DE AYUDA AL USUARIO" << std::endl << std::endl;
	std::cout << std::endl << "  El simulador debe ejecutarse del siguiente modo:" << std::endl;
	std::cout << "\t./ram_sim ram_program.ram  input_tape.in output_tape.out debug" << std::endl;
	std::cout << std::endl << " + ram_program.ram: fichero con el programa RAM" << std::endl;
	std::cout << " + input_tape.in: fichero con el contenido de la cinta de entrada" << std::endl;
	std::cout << " + output_tape.out: fichero con el contenido de la cinta de salida." << std::endl;
	std::cout << " + debug: Si el valor de este parámetro es 1, se presentará un menú de" << std::endl;
	std::cout << "\tcaracterísticas similares al siguiente figura y, permitirá ejecutar cada una" << std::endl;
	std::cout << "\tde sus opciones, mostrando en cada paso de ejecución la instrucción" << std::endl;
	std::cout << "\tejecutada y el estado de la máquina." << std::endl;
	std::cout << "\tEl valor 0 lleva a cabo la simulación completa. Al finalizar la misma, sólo" << std::endl;
	std::cout << "\tdeberá mostrarse por consola el número total de instrucciones ejecutadas." << std::endl << std::endl;
	std::cout << std::endl << "  Deben leerse la instrucciones desde el ram_program.ram y comprobar que sean" << std::endl;
	std::cout << "\tlegales. La instrucciones deben ser implementadas con los direccionamientos" << std::endl;
	std::cout << "\tpermitidos." << std::endl;
	std::cout << std::endl << "  Las instrucciones del programa pueden estar escritas en mayúscula o en" << std::endl;
	std::cout << "\tminúscula y se utilizará el símbolo # (hashtag) para introducir comentarios." << std::endl;
	std::cout << std::endl << "  Debe comprobarse que no se intente realizar una división por cero." << std::endl;
	std::cout << std::endl << "  Ante alguno de los errores anteriores se debe imprimir por pantalla un mensaje y" << std::endl;
	std::cout << "\tla posición de memoria de la instrucción que lo produjo y dejar la máquina RAM" << std::endl;
	std::cout << "\ten estado halt." << std::endl;
	std::cout << std::endl << "  Cuando se entra en estado halt se debe descargar el contenido de la cinta de" << std::endl;
	std::cout << "\tsalida en el fichero correspondiente." << std::endl;
	std::cout << std::endl << "  El simulador deberá funcionar con los ejemplos de test que se proporcionan en el" << std::endl;
	std::cout << "\taula virtual." << std::endl;
}

void menu(MachineRAM& ram)
{
	char selector;
	ram.loadData();
	while(selector != 'X')
	{
		std::cout << std::endl << std::endl << "Menu de la Máquina RAM" << std::endl;
		std::cout << "____________________________________" << std::endl;
		std::cout << "R: Ver los registros" << std::endl;
		std::cout << "T: Mostrar traza del programa" << std::endl;
		std::cout << "E: Ejecutar programa" << std::endl;
		std::cout << "S: Desensamblar programa" << std::endl;
		std::cout << "I: Ver cinta de entrada" << std::endl;
		std::cout << "O: Ver cinta de salida" << std::endl;
		std::cout << "H: Mostrar ayuda al usuario" << std::endl;
		std::cout << "X: Salir del programa" << std::endl;
		std::cin >> selector;
		switch(selector)
		{
			case 'R':
				std::cout << std::endl << "Registers: " << std::endl;
				ram.get_Registers().write();
				break;

			case 'T':
				std::cout << std::endl << "Traza: " << std::endl;
				ram.runTraza();
				break;

			case 'E':
				ram.runProgram();
				std::cout << std::endl << "Program finished correctly " << std::endl;
				break;

			case 'S':
				std::cout << std::endl << "Disassembling: " << std::endl;
				ram.writeProgram(std::cout);
				break;

			case 'I':
				std::cout << std::endl << "Input tape: " << std::endl;
				ram.get_InputTape().write();
				break;

			case 'O':
				std::cout << std::endl << "Output tape: " << std::endl;
				ram.get_OutputTape().write();
				break;

			case 'H':
				help();
				break;

			case 'X':
				std::cout << std::endl << "Exit program . . ." << std::endl;
				exit(0);
				break;

			default:
				system("clear");
				break;
		}
	}
}