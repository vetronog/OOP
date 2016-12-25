#include "stdafx.h"
#include "ParsingErrs.h"

using namespace std;

CUrlParsingError::CUrlParsingError(std::string const& message)
	:std::invalid_argument(message)
{
}