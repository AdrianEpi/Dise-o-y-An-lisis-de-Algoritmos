#ifndef MERGESORTP_H_
#define MERGESORTP_H_

#include <vector>
#include <cmath> 
#include "../framework/Problema.h"
#include "mergeSortS.h"

#pragma once

class MergeSortP : public Problema
{
public:
  MergeSortP(vector<int> vector);
  virtual ~MergeSortP();

  bool isCasoMinimo();
  pair<Problema *, Problema *> descomponer();
  void solver(Solucion *s);

private:
  vector<int> vectorToSort;
};

#endif /* MERGESORTP_H_ */
