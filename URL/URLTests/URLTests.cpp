#include "stdafx.h"
#include "../url/CUrl.h"
#include "../url/Parametres.h"
#include "../url/ParsingErrs.h"

void VerificationUrl(CUrl url,
	std::string const& urlStr,
	Protocol protocol,
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


BOOST_AUTO_TEST_SUITE(CURLTest)

	BOOST_AUTO_TEST_SUITE(ParseUrl)
	
		BOOST_AUTO_TEST_CASE(parse_url)
		{
			{
				std::string testUrl = "https://hamer.by/page.php?id=2135";
				VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTPS, "hamer.by", "/page.php?id=2135", 443);
			}
		
			{
				std::string testUrl = "http://geer.by/id12535279";
				VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTP, "geer.by", "/id12535279", 80);
			}
		
			{
				std::string testUrl = "https://seerd.by:1461/id132524";
				VerificationUrl(CUrl(testUrl), testUrl, Protocol::HTTPS, "seerd.by", "/id132524", 1461);
			}
		}
		BOOST_AUTO_TEST_SUITE_END()
		
	BOOST_AUTO_TEST_SUITE(ParseProtocol)
		
		BOOST_AUTO_TEST_CASE(parse_protocol)
		{
			BOOST_CHECK(CUrl("https://hjhghjg.by/").GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK(CUrl("http://tagabr.by/").GetProtocol() == Protocol::HTTP);
		}
		BOOST_AUTO_TEST_SUITE_END()
		
		
		BOOST_AUTO_TEST_SUITE(ParseDomain)
		
		BOOST_AUTO_TEST_CASE(parse_domain)
		{
			BOOST_CHECK(CUrl("https://retard:1500").GetDomain() == "retard");
			BOOST_CHECK(CUrl("http://gerad.com:266/index.html").GetDomain() == "gerad.com");
		}
	BOOST_AUTO_TEST_SUITE_END()
		
		
	BOOST_AUTO_TEST_SUITE(ParsePort)
		
		BOOST_AUTO_TEST_CASE(parse_port)
		{
		 	BOOST_CHECK(CUrl("https://kert.by:1426").GetPort() == 1426);
			BOOST_CHECK(CUrl("https://kert.by").GetPort() == 443);
			BOOST_CHECK(CUrl("http://kert.cpm").GetPort() == 80);
		}
	BOOST_AUTO_TEST_SUITE_END()
		
		
	BOOST_AUTO_TEST_SUITE(ParseDocument)
		
		BOOST_AUTO_TEST_CASE(parse_document)
		{
			BOOST_CHECK(CUrl("https://kemr.by").GetDocument() == "/");
			BOOST_CHECK(CUrl("https://kemr.by:1500").GetDocument() == "/");
			BOOST_CHECK(CUrl("http://kemr.by/01/doc.yxy").GetDocument() == "/01/doc.yxy");
		}
	BOOST_AUTO_TEST_SUITE_END()
		
		
	BOOST_AUTO_TEST_SUITE(GetUrl)
		
		BOOST_AUTO_TEST_CASE(return_url)
		{
			BOOST_CHECK(CUrl("https://vk.com/im?sel=77578425").GetUrl() == "https://vk.com/im?sel=77578425");
			BOOST_CHECK(CUrl("https://ficbook.net/").GetUrl() == "https://ficbook.net/");
			BOOST_CHECK(CUrl("HTTPS://ficbook.net/").GetUrl() == "https://ficbook.net/");
		}
	BOOST_AUTO_TEST_SUITE_END()
		
	BOOST_AUTO_TEST_SUITE(CHttpUrl_cant_be_initialized_if)
		
		BOOST_AUTO_TEST_CASE(input_is_empty)
		{
			BOOST_CHECK_THROW(CUrl url(""), std::invalid_argument);
		}
		
		BOOST_AUTO_TEST_CASE(port_overflow)
		{
			BOOST_CHECK_THROW(CUrl url("http://adfed.by:65540"), CUrlParsingError);
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

			BOOST_CHECK_THROW(CUrl url("http://adet.by:0"), CUrlParsingError);
			BOOST_CHECK_THROW(CUrl url("http://adet.by:"), CUrlParsingError);
			BOOST_CHECK_THROW(CUrl url("http://adet.by:/"), CUrlParsingError);
			BOOST_CHECK_THROW(CUrl url("http://tyt.by:63aa"), CUrlParsingError);
		}
		
	BOOST_AUTO_TEST_SUITE_END()
	
BOOST_AUTO_TEST_SUITE_END()
