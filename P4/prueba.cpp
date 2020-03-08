#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int getPivot(vector<int> x)
{
  int numberOfSmallerElements = 0;
  int numberOfBiggerElements = 0;

  for (int i = 0; i < x.size(); i++)
  {
    numberOfSmallerElements = 0;
    numberOfBiggerElements = 0;
    for (int j = 0; j < x.size(); j++)
    {
      if (i != j)
      {
        if (x[i] >= x[j])
        {
          numberOfSmallerElements++;
        }
        else if (x[i] < x[j])
        {

          numberOfBiggerElements++;
        }
      }
    }
    if (numberOfSmallerElements == floor(x.size() / 2))
    {
      return x[i];
    }
  }
}

bool isInVector(vector<int> vectorToSort, int value)
{
	for (int i = 0; i < vectorToSort.size(); i++)
	{
		if (vectorToSort[i] == value)
		{
			return true;
		}
	}
	return false;
}
int main(int argc, char *argv[])
{
  time_t t;
	srand((unsigned)time(&t));
	vector<int> vectorToSort;
	vectorToSort.resize(atoi(argv[1]));
  int evitarRepetidos;

	for (int i = 0; i < vectorToSort.size(); i++)
	{
		evitarRepetidos = rand() % 100 + 1;
		if (isInVector(vectorToSort, evitarRepetidos))
		{
			evitarRepetidos = (evitarRepetidos * rand()) % 100 + 1;
		}

		vectorToSort[i] = evitarRepetidos;

		if (i == 0)
		{
			cout << "[ ";
		}
		if (i == vectorToSort.size() - 1)
		{
			cout << vectorToSort[i] << " ]" << endl;
		}
		else
		{
			cout << vectorToSort[i] << ", ";
		}
	}

  cout << getPivot(vectorToSort) << endl;
}