#include "stdafx.h"
#include "ProcessFindAndReplace.h"


string FindAndReplace(string const& subject, string const& search, string  const& replace)
{
	size_t currentPosition = 0;
	size_t searchStringPosition = subject.find(search);
	string line = "";
	while ((searchStringPosition != string::npos) && (search != replace))
	{
		line += subject.substr(currentPosition, searchStringPosition - currentPosition) + replace;
		currentPosition = searchStringPosition + search.length();
		searchStringPosition = subject.find(search, currentPosition);
	}
	line += subject.substr(currentPosition);
	return line;
}