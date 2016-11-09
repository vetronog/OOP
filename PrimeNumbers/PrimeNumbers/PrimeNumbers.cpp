// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
#include "ProcessPrimeNumbers.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		return 1;
	}
	int number = atoi(argv[1]);
	if ((number < 2) && (number > 100000000))
	{
		cout << "Invalid input number";
		return 1;
	}
	set<int> numbers = GeneratePrimeNumbersSet(number);
	//copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << "Size of set:" << numbers.size();
	return 0;
}

