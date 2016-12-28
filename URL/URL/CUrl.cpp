#include "stdafx.h"
#include "Parametres.h"
#include "ParsingErrs.h"
#include "CUrl.h"
using namespace std;

CUrl::CUrl(std::string const& url)
{
	std::string string(url);
	m_protocol = ParseProtocol(string);
	m_domain = ParseDomain(string);
	ValidateDomain(m_domain);
	m_port = ParsePort(string);
	ValidateDocument(string);
	m_document = (string[0] == '/') ? string : "/";
};

CUrl::CUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port
)
	:m_domain(domain)
	,m_document(document)
	,m_protocol(protocol)
	
{
	
	ValidateDomain(domain);
	ValidateDocument(document);
}

Protocol CUrl::GetProtocol() const
{
	return m_protocol;
}

string CUrl::GetDomain() const
{
	return m_domain;
}

unsigned short CUrl::GetPort() const
{
	return m_port;
}

string CUrl::GetDocument() const
{
	return m_document;
}

string CUrl::GetUrl() const
{
	return ProtocolToString() + "://" + m_domain + PortToString() + m_document;
}

std::string CUrl::PortToString() const
{
	if ((m_port == static_cast<unsigned short>(Protocol::HTTP)) ||
		(m_port == static_cast<unsigned short>(Protocol::HTTPS)))
	{
		return "";
	}
	else
	{
		return ":" + std::to_string(m_port);
	}
}

string CUrl::ProtocolToString() const
{
	string result;
	if (m_protocol == Protocol::HTTP)
	{
		result = "http";
	}
	else if (m_protocol == Protocol::HTTPS)
	{
		result  = "https";
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

Protocol CUrl::ParseProtocol(string &urlR) const
{
	auto pos = urlR.find(PROTOCOL_DELIMITER);
	if (pos != string::npos)
	{
		auto protocol = urlR.substr(0, pos);
		std::transform(protocol.begin(), protocol.end(), protocol.begin(), tolower);
		urlR = urlR.substr(pos + PROTOCOL_DELIMITER.size());
		return ToProtocolType(protocol);
	}
	throw CUrlParsingError(PROTOCOL_PARSING_ERROR);
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

string CUrl::ParseDomain(string &urlR) const
{
	auto pos = urlR.find(":");
	if (pos == string::npos)
	{
		pos = urlR.find("/");
	}
	auto domain = urlR.substr(0, pos);
	if (domain.empty())
	{
		throw CUrlParsingError(DOMAIN_PARSING_ERROR);
	}
	urlR = urlR.substr(domain.size());

	return domain;
}


unsigned short CUrl::ParsePort(string & urlR) const
{
	unsigned short port;
	if (urlR[0] == ':')
	{
		auto endPos = urlR.find('/');
		auto portStr = urlR.substr(1, endPos - 1);
		urlR = urlR.substr(portStr.size() + 1, urlR.size() - 1);
		if (portStr.empty())
			throw CUrlParsingError(PORT_PARSING_ERROR);
		try
		{
			port = (boost::lexical_cast<unsigned short>(portStr));
		}
		catch (boost::bad_lexical_cast const& error)
		{
			throw CUrlParsingError(error.what());
		}
		if (port == 0)
		{
			throw CUrlParsingError(PORT_PARSING_ERROR);
		}
	}
	else
	{
		port = static_cast<unsigned short>(m_protocol);
	}
	return port;
}


void CUrl::ValidateDocument(std::string const& document) const
{
	bool isValidDocument = document.find(" ") != std::string::npos;
	if (isValidDocument)
	{
		throw CUrlParsingError(INVALID_DOCUMENT);
	}
}



