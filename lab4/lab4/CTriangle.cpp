#include "stdafx.h"
#include "CTriangle.h"
#include "CLineSegment.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, string outlineColor, string fillColor)
	:CSolidShape("triangle", outlineColor, fillColor)
{
	m_vertices.push_back(vertex1);
	m_vertices.push_back(vertex2);
	m_vertices.push_back(vertex3);
}

double GetSideLength(const CPoint &point1, const CPoint &point2)
{
	double vectorX = point2.x - point1.x;
	double vectorY = point2.y - point1.y;
	double length = sqrt(vectorX * vectorX + vectorY * vectorY);
	return length;
}

double CTriangle::GetPerimeter() const
{
	return (GetSideLength(m_vertices[0], m_vertices[1])
		+ GetSideLength(m_vertices[1], m_vertices[2])
		+ GetSideLength(m_vertices[2], m_vertices[0]));
}

double CTriangle::GetArea() const
{
	double semiperimeter = GetPerimeter() / 2;
	return std::sqrt(semiperimeter *
		(semiperimeter - hypot(m_vertices[1].x - m_vertices[0].x, m_vertices[1].y - m_vertices[0].y)) *
		(semiperimeter - hypot(m_vertices[2].x - m_vertices[1].x, m_vertices[2].y - m_vertices[1].y)) *
		(semiperimeter - hypot(m_vertices[0].x - m_vertices[2].x, m_vertices[0].y - m_vertices[2].y))
	);
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertices[2];
}

void CTriangle::AppendProperties(std::ostream & strm) const
{
	strm << "\nVertex1 = " << m_vertices[0].ToString()
		<< "\nVertex2 = " << m_vertices[1].ToString()
		<< "\nVertex3 = " << m_vertices[2].ToString()
		<< "\nFill color = " << GetFillColor();
}