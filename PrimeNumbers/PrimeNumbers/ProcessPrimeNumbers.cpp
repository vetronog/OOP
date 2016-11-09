#include <set>
#include <vector>
#include "stdafx.h"

using namespace std;

void DeleteOddsNumbers(int number, vector<bool> &isPrimeNumber)
{
	for (int i = 2; i < number - 1; i += 2)
	{
		isPrimeNumber[i] = false;
	}
}

void FindPrimeNumber(int number, vector<bool> &isPrimeNumber)
{
	int limit = int(sqrt(number));
	DeleteOddsNumbers(number,isPrimeNumber);
	for (int i = 1; i < limit; i += 2)
	{
		if (isPrimeNumber[i])
		{
			for (int j = i; j < number - 1; j += i + 2)
			{
				if ((j != i) && (isPrimeNumber[j]))
				{
					isPrimeNumber[j] = false;
				}
			}
		}
	}
}

set<int> CreateSetPrimeNumbers(int number, vector<bool> &isPrimeNumber)
{
	set<int> primeNumbers;
	for (int i = 0; i < number - 1; i++)
	{
		if (isPrimeNumber[i])
		{
			primeNumbers.emplace(i + 2);
		}
	}
	return primeNumbers;
}

set<int> GeneratePrimeNumbersSet(int number)
{
	vector<bool> isPrimeNumber(number - 1, true);
	FindPrimeNumber(number, isPrimeNumber);
	set<int> numbers = CreateSetPrimeNumbers(number, isPrimeNumber);
	return numbers;
}
