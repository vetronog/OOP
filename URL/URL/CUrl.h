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
		unsigned port = static_cast< unsigned>(Protocol::HTTP)
	);
	std::string GetUrl() const;
	Protocol GetProtocol() const;
	std::string ProtocolToString() const;
	std::string GetDomain() const;
	unsigned GetPort() const;
	std::string GetDocument() const;
private:
	std::string document;
	std::string domain;
	unsigned port;
	Protocol protocol;

	Protocol ToProtocolType(std::string const& protocol) const;
	Protocol ParseProtocol(std::string & urlRef) const;
	void ValidateDomain(std::string const& domain) const;
	std::string ParseDomain(std::string & urlRef) const;

	std::string PortToString() const;
	unsigned ParsePort(std::string & urlRef) const;

	void ValidateDocument(std::string const& document) const;
};