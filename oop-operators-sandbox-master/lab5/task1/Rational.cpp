#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////

double CRational::ToDouble() const
{
	return static_cast<double> (m_numerator) / (m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator +() const
{
	return *this;
}

CRational const CRational::operator -()
{
	m_numerator = -m_numerator;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////

CRational const operator+(CRational const& rational1, CRational const& rational2)
{
	int numerator = rational1.GetNumerator() * rational2.GetDenominator() + rational1.GetDenominator() * rational2.GetNumerator();
	int denomirator = rational1.GetDenominator() * rational2.GetDenominator();
	return CRational(numerator, denomirator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////


CRational const operator-(CRational const& rational1, CRational const& rational2)
{
	int numerator = rational1.GetNumerator() * rational2.GetDenominator() - rational1.GetDenominator() * rational2.GetNumerator();
	int denomirator = rational1.GetDenominator() * rational2.GetDenominator();
	return CRational(numerator, denomirator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator +=(CRational const& rational1)
{
	*this = *this + rational1;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator -=(CRational const& rational1)
{
	*this = *this - rational1;
	return *this;
}

CRational const operator *(CRational const& rational1, CRational const& rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetNumerator()),
					 (rational1.GetDenominator() * rational2.GetDenominator()));
}

CRational const operator /(CRational const& rational1, CRational const& rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetDenominator()),
		(rational1.GetDenominator() * rational2.GetNumerator()));
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////


CRational const CRational::operator *=(CRational const& rational1)
{
	*this = *this * rational1;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator /=(CRational const& rational1)
{
	*this = *this / rational1;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator ==(CRational const& rational1, CRational const& rational2)
{
	return (rational1.GetNumerator() == rational2.GetNumerator()) &&
		(rational1.GetDenominator() == rational2.GetDenominator());
}

bool const operator !=(CRational const& rational1, CRational const& rational2)
{
	return (rational1.GetNumerator() != rational2.GetNumerator()) ||
		(rational1.GetDenominator() != rational2.GetDenominator());
}
//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const operator <(CRational const& rational1, CRational const& rational2)
{
	return ((rational1.GetNumerator() * rational2.GetDenominator()) < (rational1.GetDenominator() * rational2.GetNumerator()));
}



bool const operator >(CRational const& rational1, CRational const& rational2)
{
	return ((rational1.GetNumerator() * rational2.GetDenominator()) > (rational1.GetDenominator() * rational2.GetNumerator()));
}
bool const operator <=(CRational const& rational1, CRational const& rational2)
{
	return !(rational1 > rational2);
}

bool const operator >=(CRational const& rational1, CRational const& rational2)
{
	return !(rational1 < rational2);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

std::ostream & operator <<(std::ostream &stream, CRational const& rational)
{
	return(stream << rational.GetNumerator() << '/'
		  << rational.GetDenominator()
		);
	
}



//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////

std::istream & operator >> (std::istream &stream, CRational & rational)
{
	unsigned numerator = 0;
	unsigned denominator = 1;
	if (
		(stream >> numerator) && (stream.get() == '/') &&
		(stream >> denominator)
		)
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}