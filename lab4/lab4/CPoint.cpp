#include "stdafx.h"
#include "CPoint.h"
#include <string>

using namespace std;

CPoint::CPoint(double x0, double y0)
	: x(x0)
	, y(y0)
{
}

string CPoint::ToString() const
{
	return std::to_string(x) + " " + std::to_string(y);
}

bool CPoint::operator==(const CPoint &point) const
{
	return ((x == point.x) && (y == point.y));
}

bool CPoint::operator!=(const CPoint &point) const
{
	return !(*this == point);
}