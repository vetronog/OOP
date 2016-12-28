#pragma once

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CUrl
{
public:
	CUrl(std::string const& url);
	CUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = static_cast<unsigned>(Protocol::HTTP)
	);
	std::string GetUrl() const;
	Protocol GetProtocol() const;
	std::string ProtocolToString() const;
	std::string GetDomain() const;
	unsigned short GetPort() const;
	std::string GetDocument() const;
private:
	std::string m_document;
	std::string m_domain;
	unsigned short m_port;
	Protocol m_protocol;

	Protocol ToProtocolType(std::string const& protocol) const;
	Protocol ParseProtocol(std::string & urlRef) const;
	void ValidateDomain(std::string const& domain) const;
	std::string ParseDomain(std::string & urlRef) const;

	std::string PortToString() const;
	unsigned short ParsePort(std::string & urlRef) const;

	void ValidateDocument(std::string const& document) const;
};