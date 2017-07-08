#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape, public ISolidShape
{
public:
	CSolidShape() = default;
	CSolidShape(const string & type, string outlineColor, string fillColor);

	string ToString() const override;

	string GetFillColor() const override;
	string GetOutlineColor() const override;
private:
	string m_fillColor;
};