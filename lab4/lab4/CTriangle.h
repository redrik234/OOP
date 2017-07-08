#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

class CTriangle final: public CSolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, string outlineColor, string fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	vector<CPoint> m_vertices;
};