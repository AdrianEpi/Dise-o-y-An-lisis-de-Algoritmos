#include <iostream>
#include "../includes/mergeSortS.h"

MergeSortS::MergeSortS() : Solucion::Solucion()
{
}

MergeSortS::~MergeSortS()
{
}

void MergeSortS::resolver()
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

void MergeSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{
  vector<int> subSol1 = (((MergeSortS *)subSoluciones.first))->vectorToSort;
  vector<int> subSol2 = ((MergeSortS *)subSoluciones.second)->vectorToSort;
  int firstVectorIterator = 0;
  int secondVectorIterator = 0;
  int resultVectorIterator = 0;
  vectorToSort.resize(subSol1.size() + subSol2.size());

  while ((firstVectorIterator < subSol1.size()) &&
         (secondVectorIterator < subSol2.size()))
  {
    if (subSol1[firstVectorIterator] < subSol2[secondVectorIterator])
    {
      vectorToSort[resultVectorIterator] = subSol1[firstVectorIterator];
      firstVectorIterator++;
    }
    else
    {
      vectorToSort[resultVectorIterator] = subSol2[secondVectorIterator];
      secondVectorIterator++;
    }
    resultVectorIterator++;
  }

  if (firstVectorIterator < subSol1.size())
  {
    for (; firstVectorIterator < subSol1.size(); firstVectorIterator++)
    {
      vectorToSort[resultVectorIterator] = subSol1[firstVectorIterator];
      resultVectorIterator++;
    }
  }
  else
  {
    for (; secondVectorIterator < subSol2.size(); secondVectorIterator++)
    {
      vectorToSort[resultVectorIterator] = subSol2[secondVectorIterator];
      resultVectorIterator++;
    }
  }
}

Solucion *MergeSortS::getInstance()
{
  return new MergeSortS();
}

void MergeSortS::setValor(vector<int> vector)
{
  vectorToSort = vector;
}
