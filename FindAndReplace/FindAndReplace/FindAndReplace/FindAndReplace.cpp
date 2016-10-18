// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProcessFindAndReplace.h"

using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		return 1;
	}
	string search = argv[1];
	if (search == "")
	{
		cout << "Text to find is empty string";
		return 1;
	}

	string replace = argv[2];
	string subject;

	while (getline(cin, subject))
	{
		cout << FindAndReplace(subject, search, replace) << "\n";
	}

	return 0;
}
	
	
	

