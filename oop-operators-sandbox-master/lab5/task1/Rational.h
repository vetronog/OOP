﻿#pragma once


/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	double ToDouble() const;

	CRational const operator +() const;
	CRational const operator -();

	CRational const operator +=(CRational const& rational1);
	CRational const operator -=(CRational const& rational1);

	CRational const operator *=(CRational const& rational1);
	CRational const operator /=(CRational const& rational1);

	//////////////////////////////////////////////////////////////////////////
	// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
	//	std::ostream в формате <числитель>/<знаменатель>, 
	//	например: 7/15
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
	//	std::istream в формате <числитель>/<знаменатель>, 
	//	например: 7/15
	//////////////////////////////////////////////////////////////////////////
private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий делитель (greatest common denominator) чисел a и b
unsigned GCD(unsigned a, unsigned b);
CRational const operator +(CRational const& rational1, CRational const& rational2);
CRational const operator -(CRational const& rational1, CRational const& rational2);
CRational const operator *(CRational const& rational1, CRational const& rational2);
CRational const operator /(CRational const& rational1, CRational const& rational2);
bool const operator ==(CRational const& rational1, CRational const& rational2);
bool const operator !=(CRational const& rational1, CRational const& rational2);

bool const operator <(CRational const& rational1, CRational const& rational2);
bool const operator >(CRational const& rational1, CRational const& rational2);
bool const operator <=(CRational const& rational1, CRational const& rational2);
bool const operator >=(CRational const& rational1, CRational const& rational2);
bool const operator >=(CRational const& rational1, CRational const& rational2);

std::ostream & operator <<(std::ostream &stream, CRational const& rational);
std::istream & operator >>(std::istream &stream, CRational & rational);