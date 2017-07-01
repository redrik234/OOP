#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape, public ISolidShape
{
public:
	CSolidShape() = default;
	CSolidShape(const string & type, string outlineColor, string fillColor);

	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;

	string ToString() const;

	string GetFillColor() const override;
	string GetOutlineColor() const;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	string m_fillColor;
};