#include <iostream>
#include "../includes/quickSortS.h"

QuickSortS::QuickSortS() : Solucion::Solucion()
{
}

QuickSortS::~QuickSortS()
{
}

void QuickSortS::resolver()
{
  for (int i = 0; i < vectorToSort.size(); i++)
  {
    if (i == 0)
    {
      cout << "[ ";
    }
    if (i == vectorToSort.size() - 1)
    {
      cout << vectorToSort[i] << " ]";
    }
    else
    {
      cout << vectorToSort[i] << ", ";
    }
  }
  cout << endl;
}

void QuickSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{
  vector<int> subSol1 = (((QuickSortS *)subSoluciones.first))->vectorToSort;
  vector<int> subSol2 = ((QuickSortS *)subSoluciones.second)->vectorToSort;
  int firstVectorIterator = 0;
  int secondVectorIterator = 0;
  int resultVectorIterator = 0;
  vectorToSort.resize(subSol1.size() + subSol2.size());

  for (int i = 0; i < subSol1.size(); i++) {
    vectorToSort[resultVectorIterator] = subSol1[i];
    resultVectorIterator++;
  }

  for (int j = 0; j < subSol2.size(); j++) {
    vectorToSort[resultVectorIterator] = subSol2[j];
    resultVectorIterator++;
  }
}

Solucion *QuickSortS::getInstance()
{
  return new QuickSortS();
}

void QuickSortS::setValor(vector<int> vector)
{
  //cout << "Llega a setValor" << endl;
  vectorToSort = vector;
}
