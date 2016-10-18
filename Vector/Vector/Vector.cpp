#include "stdafx.h"
#include "ProcessVector.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int _tmain()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	/*while (!cin.eof())
	{
		double number;
		if (cin >> number)
		{
			numbers.push_back(number);
		}
		else
		{
			break;
		}
	}*/

	//copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));

	/*for (auto number : numbers)
	{
		cout << number << ", ";
	}*/
	ProcessVector(numbers);
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
	
	cout << "\nSize of vector: " << numbers.size() << "\n";
	return 0;
}