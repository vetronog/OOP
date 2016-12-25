
#include "stdafx.h"
#include "CUrl.h"
#include "ParsingErrs.h"

using namespace std;

void PrintInfo(CUrl const& url)
{
	cout << "Protocol > " << url.ProtocolToString() << "\n";
	cout << "Domain > " << url.GetDomain() << "\n";
	cout << "Port > " << url.GetPort() << "\n";
	cout << "Document > " << url.GetDocument() << "\n";
}

int main()
{
	string url;
	while (getline(cin, url))
	{
		try
		{
			CUrl URL(url);
			PrintInfo(url);
		}
		catch (CUrlParsingError const& err)
		{
			cout << err.what() << "\n";
		}
	}
	return 0;
}

