#include "stdafx.h"
#include "CCircle.h"

#define _USE_MATH_DEFINES
#include "math.h"

CCircle::CCircle(CPoint center, double radius, string outlineColor, string fillColor)
	: CSolidShape("circle", outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return (M_PI * m_radius * m_radius);
}

double CCircle::GetPerimeter() const
{
	return (2 * M_PI * m_radius);
}

string CCircle::GetOutlineColor() const
{
	return CSolidShape::GetOutlineColor();
}

string CCircle::GetFillColor() const
{
	return CSolidShape::GetFillColor();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::AppendProperties(ostream & strm) const
{
	strm << "\nRadius = " << m_radius
		<< "\nCenter = " << m_center.PointToString()
		<< "\nFill color = " << GetFillColor();
}