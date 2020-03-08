#ifndef QUICKSORTP_H_
#define QUICKSORTP_H_

#include <vector>
#include <cmath> 
#include "../framework/Problema.h"
#include "quickSortS.h"

#pragma once

class QuickSortP : public Problema
{
public:
  QuickSortP(vector<int> vector);
  virtual ~QuickSortP();

  bool isCasoMinimo();
  pair<Problema *, Problema *> descomponer();
  void solver(Solucion *s);

private:
  vector<int> vectorToSort;
  //int pivot_;

  //int getPivot();
};

#endif /* QUICKSORTP_H_ */
