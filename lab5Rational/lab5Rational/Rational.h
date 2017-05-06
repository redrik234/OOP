#pragma once

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator()const;

	int GetDenominator()const;

	double ToDouble()const;

	void Normalize();

	const CRational operator+()const;
	const CRational operator-()const;

	const CRational & operator+=(const CRational & subtrahend);
	const CRational & operator-=(const CRational & subtrahend);
	const CRational & operator*=(CRational const& r);
	const CRational & CRational::operator/=(CRational const& r);
private:
	int m_numerator;
	int m_denominator;
};

int GetGCD(int a, int b);

const CRational operator+(const CRational & lValue, const CRational & rValue);
const CRational operator-(const CRational & lValue, const CRational & rValue);
const CRational operator*(const CRational & lValue, const CRational & rValue);
const CRational operator/(const CRational & lValue, const CRational & rValue);

const bool operator==(const CRational & lValue, const CRational & rValue);
const bool operator!=(const CRational & lValue, const CRational & rValue);
const bool operator<(const CRational & lValue, const CRational & rValue);
const bool operator>(const CRational & lValue, const CRational & rValue);
const bool operator<=(const CRational & lValue, const CRational & rValue);
const bool operator>=(const CRational & lValue, const CRational & rValue);

std::istream & operator>>(std::istream & input, CRational & rational);
std::ostream & operator<<(std::ostream & output, CRational & rational);
