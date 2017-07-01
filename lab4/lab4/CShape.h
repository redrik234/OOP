#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape() = default;
	CShape(const string & type, string color);

	string ToString() const;
	string GetOutlineColor() const override;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	string m_outlineColor;
	string m_type;
};