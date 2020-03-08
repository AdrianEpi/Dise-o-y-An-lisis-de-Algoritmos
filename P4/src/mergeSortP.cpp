#include "../includes/mergeSortP.h"

MergeSortP::MergeSortP(vector<int> vector) : Problema::Problema()
{
  vectorToSort = vector;
}

MergeSortP::~MergeSortP()
{
  vectorToSort.clear();
}

bool MergeSortP::isCasoMinimo()
{
  return (vectorToSort.size() <= 2);
}

pair<Problema *, Problema *> MergeSortP::descomponer()
{
  pair<Problema *, Problema *> subProblemas;
  vector<int> firstHalf, secondHalf;
  firstHalf.resize(round(vectorToSort.size() / 2));
  secondHalf.resize(vectorToSort.size() - firstHalf.size());

  for (int i = 0; i < firstHalf.size(); i++)
  {
    firstHalf[i] = vectorToSort[i];
  }

  for (int j = 0; j < secondHalf.size(); j++)
  {
    secondHalf[j] = vectorToSort[firstHalf.size() + j];
  }

  subProblemas.first = new MergeSortP(firstHalf);
  subProblemas.second = new MergeSortP(secondHalf);
  return subProblemas;
}

void MergeSortP::solver(Solucion *s)
{ 
  if (vectorToSort.size() == 1)
  {
    ((MergeSortS *)s)->setValor(vectorToSort);
  }
  else
  {
    if (vectorToSort[0] > vectorToSort[1])
    {
      int temp = vectorToSort[0];
      vectorToSort[0] = vectorToSort[1];
      vectorToSort[1] = temp;
    }
    ((MergeSortS *)s)->setValor(vectorToSort);
  }
}
