#pragma once
#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> GeneratePrimeNumbersSet(int number);
set<int> CreateSetPrimeNumbers(int number, vector<bool> isPrimeNumber);
void DeleteOddsNumbers(int number, vector<bool> isPrimeNumber);
void FindPrimeNumber(int number, vector<bool> isPrimeNumber);