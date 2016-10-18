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
	
	ProcessVector(numbers);
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
	
	cout << "\nSize of vector: " << numbers.size() << "\n";
	return 0;
}