#pragma once
#include <string>

using namespace std;

class IShape
{
public:
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual string ToString() const = 0;
	virtual string GetOutlineColor() const = 0;
	virtual ~IShape() = default;
};