#pragma once
#include "CSolidShape.h"
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CCircle final : public CSolidShape
{
public:
	CCircle(CPoint center, double radius, string outlineColor, string fillColor);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetCenter() const;
	double GetRadius() const;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	CPoint m_center;
	double m_radius;
};