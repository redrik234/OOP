#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, string outlineColor)
	: CShape("line segment", outlineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow((m_endPoint.x - m_startPoint.x), 2) + pow((m_endPoint.y - m_startPoint.y), 2));
}

string CLineSegment::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

void CLineSegment::AppendProperties(ostream & strm) const
{
	strm << "\nStart point: " << m_startPoint.ToString()
		<< "\nEnd point: " << m_endPoint.ToString();
}