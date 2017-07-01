#include "stdafx.h"
#include "CShape.h"

CShape::CShape(const string & type, string color)
	: m_outlineColor(color)
	, m_type(type)
{
}

string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

string CShape::ToString() const
{
	std::ostringstream strm;
	strm << m_type << ":"
		<< "\nArea = " << GetArea()
		<< "\nPerimeter = " << GetPerimeter()
		<< "\nColor outline = " << GetOutlineColor();
	AppendProperties(strm);
	return strm.str();
}