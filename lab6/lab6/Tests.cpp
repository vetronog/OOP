#include "stdafx.h"
#include "../ConsoleApplication1/CUrl.h"
#include "../ConsoleApplication1/Parametres.h"
#include "../ConsoleApplication1/ParsingErrs.h"

void VerificationUrl(CUrl const& url,
	std::string const& urlStr,
	Protocol const& protocol,
	std::string const& domain,
	std::string const& document,
	unsigned short port)
{
	BOOST_CHECK(url.GetProtocol() == protocol);
	BOOST_CHECK_EQUAL(url.GetDomain(), domain);
	BOOST_CHECK_EQUAL(url.GetDocument(), document);
	BOOST_CHECK_EQUAL(url.GetPort(), port);
	BOOST_CHECK_EQUAL(url.GetUrl(), urlStr);
}

BOOST_AUTO_TEST_SUITE(CHttpURLTest)

BOOST_AUTO_TEST_SUITE(ParseUrl)

BOOST_AUTO_TEST_CASE(parse_url)
{
	{
		std::string testUrl = "https://tyt.by/page.php?id=25";
		VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTPS, "tyt.by", "/page.php?id=25", 443);
	}

	{
		std::string testUrl = "http://tyt.by/id153679";
		VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTP, "tyt.by", "/id153679", 80);
	}

	{
		std::string testUrl = "https://tyt.by:1500/id132524";
		VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTPS, "tyt.by", "/id132524", 1500);
	}
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ParseProtocol)

BOOST_AUTO_TEST_CASE(parse_protocol)
{
	BOOST_CHECK(CUrl("https://tyt.by/").GetProtocol() == Protocol::HTTPS);
	BOOST_CHECK(CUrl("http://tyt.by/").GetProtocol() == Protocol::HTTP);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(ParseDomain)

BOOST_AUTO_TEST_CASE(parse_domain)
{
	BOOST_CHECK(CUrl("https://tyt:1500").GetDomain() == "tyt");
	BOOST_CHECK(CUrl("http://tyt.by:266/index.html").GetDomain() == "tyt.by");
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(ParsePort)

BOOST_AUTO_TEST_CASE(parse_port)
{
	BOOST_CHECK(CUrl("https://tyt.by:1500").GetPort() == 1500);
	BOOST_CHECK(CUrl("https://tyt.by").GetPort() == 443);
	BOOST_CHECK(CUrl("http://tyt.by").GetPort() == 80);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(ParseDocument)

BOOST_AUTO_TEST_CASE(parse_document)
{
	BOOST_CHECK(CUrl("https://tyt.by").GetDocument() == "/");
	BOOST_CHECK(CUrl("https://tyt.by:1500").GetDocument() == "/");
	BOOST_CHECK(CUrl("http://tyt.by/01/doc.html").GetDocument() == "/01/doc.html");
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(GetUrl)

BOOST_AUTO_TEST_CASE(return_url)
{
	BOOST_CHECK(CUrl("https://tyt.by").GetUrl() == "https://tyt.by/");
	BOOST_CHECK(CUrl("http://tyt.by:1500/01/doc.html").GetUrl() == "http://tyt.by:1500/01/doc.html");
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CHttpUrl_cant_be_initialized_if)

BOOST_AUTO_TEST_CASE(input_is_empty)
{
	BOOST_CHECK_THROW(CUrl url(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(port_overflow)
{
	BOOST_CHECK_THROW(CUrl url("http://tyt.by:65540"), CUrlParsingError)
}

BOOST_AUTO_TEST_CASE(invalid_protocol)
{
	BOOST_CHECK_THROW(CUrl url("tyt.by"), CUrlParsingError);
	BOOST_CHECK_THROW(CUrl url("htp://tyt.by"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(empty_domain)
{
	BOOST_CHECK_THROW(CUrl url("http://"), CUrlParsingError);
	BOOST_CHECK_THROW(CUrl url("http:///page.php"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(invalid_port)
{
	BOOST_CHECK_THROW(CUrl url("http://tyt.by:"), CUrlParsingError);
	BOOST_CHECK_THROW(CUrl url("http://tyt.by:/"), CUrlParsingError);
	BOOST_CHECK_THROW(CUrl url("http://tyt.by:25a2"), CUrlParsingError);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()