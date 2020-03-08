#ifndef MERGESORTS_H_
#define MERGESORTS_H_

#include <vector>

#include "../framework/Solucion.h"

#pragma once

class MergeSortS: public Solucion {
public:
	MergeSortS();
	virtual ~MergeSortS();

	void resolver();
	void mezcla(pair<Solucion*,Solucion*>);
	Solucion* getInstance();

	void setValor(vector<int> vector);

private:
	vector<int> vectorToSort;

};

#endif /* MERGESORTS_H_ */
