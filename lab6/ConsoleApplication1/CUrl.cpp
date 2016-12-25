#include "stdafx.h"
#include "Parametres.h"
#include "ParsingErrs.h"
#include "CUrl.h"
using namespace std;

CUrl::CUrl(std::string const& url)
{
	std::string string(url);
	protocol = ParseProtocol(string);
	domain = ParseDomain(string);
	ValidateDomain(domain);
	port = ParsePort(string);
	ValidateDocument(string);
	document = (string[0] == '/') ? string : "/";
};

Protocol CUrl::GetProtocol() const
{
	return protocol;
}

string CUrl::GetDomain() const
{
	return domain;
}

unsigned CUrl::GetPort() const
{
	return port;
}

string CUrl::GetDocument() const
{
	return document;
}

string CUrl::GetUrl() const
{
	return ProtocolToString() + "://" + domain + PortToString() + document;
}

string CUrl::ProtocolToString() const
{
	string result;
	if (protocol == Protocol::HTTP)
	{
		result = "http";
	}
	else if (protocol == Protocol::HTTPS)
	{
		result = "https";
	}
	return result;
}

Protocol CUrl::ToProtocolType(std::string const& protocol) const
{
	if (protocol == "http")
	{
		return Protocol::HTTP;
	}
	if (protocol == "https")
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError(INVALID_PROTOCOL);
}

std::string CUrl::PortToString() const
{
	if ((port == static_cast<unsigned>(Protocol::HTTP)) ||
		(port == static_cast<unsigned>(Protocol::HTTPS)))
	{
		return "";
	}
	else
	{
		return std::to_string(port);
	}
}

void CUrl::ValidateDomain(std::string const& domain) const
{
	bool isInvalidCharDomain =
		(domain.find(" ") != std::string::npos) ||
		(domain.find("\'") != std::string::npos) ||
		(domain.find("\"") != std::string::npos);
	if (isInvalidCharDomain)
	{
		throw CUrlParsingError(INVALID_DOMAIN);
	}
}

void CUrl::ValidateDocument(std::string const& document) const
{
	bool isValidDocument = document.find(" ") != std::string::npos;
	if (isValidDocument)
	{
		throw CUrlParsingError(INVALID_DOCUMENT);
	}
}

Protocol CUrl::ParseProtocol(string &url) const
{
	auto pos = url.find(PROTOCOL_DELIMITER);
	if (pos != string::npos)
	{
		auto protocol = url.substr(0, pos);
		url = url.substr(pos + PROTOCOL_DELIMITER.size());
		return ToProtocolType(protocol);
	}
	throw CUrlParsingError(PROTOCOL_PARSING_ERROR);
}

string CUrl::ParseDomain(string &url) const
{
	auto pos = url.find(":");
	if (pos = string::npos)
	{
		pos = url.find("/");
	}
	auto domain = url.substr(0, pos);
	if (domain.empty())
	{
		throw CUrlParsingError(DOMAIN_PARSING_ERROR);
	}
	url = url.substr(domain.size());

	return domain;
}

unsigned CUrl::ParsePort(string & url) const
{
	unsigned port;
	if (url[0] == ':')
	{
		auto endPos = url.find('/');
		auto portStr = url.substr(1, endPos - 1);
		url = url.substr(portStr.size() + 1, url.size() - 1);
		if (portStr.empty())
			throw CUrlParsingError(PORT_PARSING_ERROR);
		try
		{
			port = boost::lexical_cast<unsigned short>(portStr);
		}
		catch (boost::bad_lexical_cast const& error)
		{
			throw CUrlParsingError(error.what());
		}
	}
	else
	{
		port = static_cast<unsigned>(protocol);
	}
	return port;
}