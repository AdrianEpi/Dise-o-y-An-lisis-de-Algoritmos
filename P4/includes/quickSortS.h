#ifndef QUICKSORTS_H_
#define QUICKSORTS_H_

#include <vector>

#include "../framework/Solucion.h"

#pragma once

class QuickSortS: public Solucion {
public:
	QuickSortS();
	virtual ~QuickSortS();

	void resolver();
	void mezcla(pair<Solucion*,Solucion*>);
	Solucion* getInstance();

	void setValor(vector<int> vector);

private:
	vector<int> vectorToSort;

};

#endif /* QUICKSORTS_H_ */
