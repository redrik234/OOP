#pragma once
#include <string>

class CPoint final
{
public:
	CPoint() = default;
	~CPoint() = default;

	CPoint(double x0, double y0);

	std::string ToString() const;

	bool operator==(const CPoint &point) const;
	bool operator!=(const CPoint &point) const;

	double x;
	double y;
};