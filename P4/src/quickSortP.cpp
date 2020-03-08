#include "../includes/quickSortP.h"

QuickSortP::QuickSortP(vector<int> vector) : Problema::Problema()
{
  vectorToSort = vector;
  //pivot_ = getPivot();
}

QuickSortP::~QuickSortP()
{
  vectorToSort.clear();
}

bool QuickSortP::isCasoMinimo()
{
  return (vectorToSort.size() <= 2);
}

// int QuickSortP::getPivot()
// {
//   int numberOfSmallerElements = 0;
//   int numberOfBiggerElements = 0;

//   for (int i = 0; i < vectorToSort.size(); i++)
//   {
//     numberOfSmallerElements = 0;
//     numberOfBiggerElements = 0;
//     for (int j = 0; j < vectorToSort.size(); j++)
//     {
//       if (i != j)
//       {
//         if (vectorToSort[i] >= vectorToSort[j])
//         {
//           numberOfSmallerElements++;
//         }
//         else if (vectorToSort[i] < vectorToSort[j])
//         {

//           numberOfBiggerElements++;
//         }
//       }
//     }
//     if (numberOfSmallerElements == floor(vectorToSort.size() / 2))
//     {
//       return vectorToSort[i];
//     }
//   }
// }

pair<Problema *, Problema *> QuickSortP::descomponer()
{
  pair<Problema *, Problema *> subProblemas;
  vector<int> firstPart, secondPart;
  int start = 0;
  int end = vectorToSort.size() - 1;
  int pivot = vectorToSort[round(end / 2)];

  while (start <= end)
  {
    while (vectorToSort[start] < pivot)
    {
      start++;
    }
    while (vectorToSort[end] > pivot)
    {
      end--;
    }
    if (start <= end)
    { 
      int temp = vectorToSort[start];
      vectorToSort[start] = vectorToSort[end];
      vectorToSort[end] = temp;
      start++;
      end--;
    }
  }

  for (int i = 0; i <= (start + end) / 2 ; i++)
  {
    firstPart.push_back(vectorToSort[i]);
  }
  for (int j = ((start + end) / 2) + 1; j < vectorToSort.size(); j++)
  {
    secondPart.push_back(vectorToSort[j]);
  }
  
  subProblemas.first = new QuickSortP(firstPart);
  subProblemas.second = new QuickSortP(secondPart);
  return subProblemas;
}

void QuickSortP::solver(Solucion *s)
{
  if (vectorToSort.size() == 1)
  {
    ((QuickSortS *)s)->setValor(vectorToSort);
  }
  else
  {
    if (vectorToSort[0] > vectorToSort[1])
    {
      int temp = vectorToSort[0];
      vectorToSort[0] = vectorToSort[1];
      vectorToSort[1] = temp;
    }
    ((QuickSortS *)s)->setValor(vectorToSort);
  }
}
