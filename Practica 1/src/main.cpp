#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <chrono> 
#include <ctime>
#include "matrix.cpp"
#include "context.cpp"
#include "multiplyRows.cpp"
#include "multiplyColumns.cpp"
#include "multiplyTrans.cpp"
using namespace std;
int main(int argc, char *argv[])
{
	int sentinela = 0;
	char filename[85];
	string filename2;
	if (argc == 1)
		cout << "Entrada sin comandos...\n Por favor escriba como argumento el nombre de fichero de texto .txt de entrada" << endl << endl << "Un ejemplo sería:\n ./prueba entrada.txt" << endl << endl;
	else if (argc == 2)
	{
		filename2 = argv[1];
		strcpy(filename, filename2.c_str()); //strcpy para pasar un string a cadena de char
		sentinela = 1;
	}
	else
		cout << endl << "Error con el fichero de entrada" << endl;


	Matrix Z(filename);
	Context *multiplicacion_a, *multiplicacion_b, *multiplicacion_c;
	multiplicacion_a = new Context(new Multiply_Rows());
	multiplicacion_b = new Context(new Multiply_Columns());
	multiplicacion_c = new Context(new Multiply_Trans());

	{
		chrono::time_point<chrono::system_clock> start, end;
		start = chrono::system_clock::now();
		multiplicacion_a -> MultiplyInterface(Z.matrix_A, Z.matrix_B, Z.matrix_C, Z.rows_, Z.columns_);
		end = chrono::system_clock::now();
		int elapsed_seconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
		time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "\nCálculo por filas terminado  " << ctime(&end_time) << "tiempo transcurrido: " << elapsed_seconds << "microsegundos\n";
	}

	{
		chrono::time_point<chrono::system_clock> start, end;
		start = chrono::system_clock::now();
		multiplicacion_b -> MultiplyInterface(Z.matrix_A, Z.matrix_B, Z.matrix_C, Z.rows_, Z.columns_);
		end = chrono::system_clock::now();
		int elapsed_seconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
		time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "\nCálculo por columnas terminado  " << ctime(&end_time) << "tiempo transcurrido: " << elapsed_seconds << "microsegundos\n";
	}

	{
		chrono::time_point<chrono::system_clock> start, end;
		start = chrono::system_clock::now();
		multiplicacion_c -> MultiplyInterface(Z.matrix_A, Z.tras_.newMatrix, Z.matrix_C, Z.rows_, Z.columns_);
		end = chrono::system_clock::now();
		int elapsed_seconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
		time_t end_time = chrono::system_clock::to_time_t(end);
		cout << "\nCálculo traspuesta terminado  " << ctime(&end_time) << "tiempo transcurrido: " << elapsed_seconds << "microsegundos\n";
	}
}