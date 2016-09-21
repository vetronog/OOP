// OOP lab 1 replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void FindAndReplace(ifstream &fileOfInput, ofstream &fileOfOutput, const string & searchString, const string & replaceString)
{
	size_t currentPosition = 0;
	size_t searchStringPosition = 0;
	string line;
	while (getline(fileOfInput, line))
	{
		currentPosition = 0;
		searchStringPosition = line.find(searchString, currentPosition);
		while (searchStringPosition != string::npos) 
		{
			line.replace(searchStringPosition, searchString.length(), replaceString);
			currentPosition = searchStringPosition + replaceString.length();
			searchStringPosition = line.find(searchString, currentPosition);
		}
		fileOfOutput << line << "\n";
	}
}
int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file><text to find> <text to replace>\n";
		return 1;
	}
	ifstream fileOfInput;
	fileOfInput.open (argv[1]);
	if (!fileOfInput.is_open()) 
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	if (fileOfInput.peek() == ifstream::traits_type::eof())
	{
		cout << "File " << argv[1] << " is empty!" << "\n";
		return 1;
	}

	ofstream output(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}
	string strToSearch = argv[3];
	if (strToSearch == "")
	{
		cout << "Text to find is empty string";
		return 1;
	}

	string srtToReplace = argv[4];

	FindAndReplace(fileOfInput, output, strToSearch, srtToReplace);

	if (!output.flush()) // Åñëè íå óäàëîñü ñáðîñèòü äàííûå íà äèñê
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}
	return 0;
}

