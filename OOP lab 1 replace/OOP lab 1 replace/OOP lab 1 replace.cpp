// OOP lab 1 replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
		   	 << "Usage: copyfile.exe <input file> <output file><text to find> <text to replace>\n";
		return 1;
	}
	ifstream fileOfInput;
	unsigned int currPosition = 0;
	fileOfInput.open (argv[1]);
	if (!fileOfInput.is_open()) 
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
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

	size_t textPosition = 0;
	std::string line;
	while (std::getline(fileOfInput, line))
	{
		currPosition = 0;
		textPosition = line.find(argv[3], currPosition);
		while (textPosition != string::npos) 
		{
			line.replace(textPosition, std::string(argv[3]).length(), argv[4]);
			currPosition = textPosition + std::string(argv[4]).length();
			textPosition = line.find(argv[3], currPosition);
		}
		output << line << "\n";
	}

	if (!output.flush()) // Если не удалось сбросить данные на диск
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}
	return 0;
}

