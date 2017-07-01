#include "stdafx.h"
#include "CSolidShape.h"
#include "CShape.h"

CSolidShape::CSolidShape(const string & type, string outlineColor, string fillColor)
	:CShape(type, outlineColor)
	, m_fillColor(fillColor)
{
}

string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

string CSolidShape::ToString() const
{
	return CShape::ToString();
}

string CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}