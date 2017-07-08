#pragma once
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CLineSegment final: public CShape
{
public:
	CLineSegment() = default;

	CLineSegment(CPoint startPoint, CPoint endPoint, string outlineColor);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};