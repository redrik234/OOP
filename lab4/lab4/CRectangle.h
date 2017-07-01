#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CRectangle final: public CSolidShape
{
public:
	CRectangle(CPoint leftTopPoint, double width, double height, string outlineColor, string fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	string GetOutlineColor() const override;
	string GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
};