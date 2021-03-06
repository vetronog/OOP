
#include "stdafx.h"
#include "CUrl.h"
#include "ParsingErrs.h"

using namespace std;

void PrintInfo(CUrl const& url)
{
	cout << "URL > " << url.GetUrl() << "\n";
	cout << "Protocol > " << url.ProtocolToString() << "\n";
	cout << "Domain > " << url.GetDomain() << "\n";
	cout << "Port > " << url.GetPort() << "\n";
	cout << "Document > " << url.GetDocument() << "\n";
}

int main()
{
	CUrl url1("ya.ru", "/doc1", Protocol::HTTPS);
	PrintInfo(url1);
	string url;
	while (getline(cin, url))
	{
		try
		{
			CUrl URL(url);
			PrintInfo(url);
		}
		catch(CUrlParsingError const& err)
		{
			cout << err.what() << "\n";
		}
	}
    return 0;
}

