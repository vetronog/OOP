#include "stdafx.h"
#include "Control.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: shape.exe <input file>\n";
		return 1;
	}
	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for writing\n";
		return 1;
	}
	CRemoteControl control(inputFile, cout);
	while (!inputFile.eof() && !inputFile.fail())
	{
		if (!control.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	control.PrintInfo();
	return 0;
}