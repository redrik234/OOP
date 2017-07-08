#include "stdafx.h"
#include "CMenu.h"
#include "IShape.h"
#include "CLineSegment.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include <sstream>
#include <iterator>

using namespace std;
using namespace placeholders;

CMenu::CMenu(istream & input, ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", bind(&CMenu::CreateLineSegment, this, _1) },
		{ "circle", bind(&CMenu::CreateCircle, this, _1) },
		{ "triangle", bind(&CMenu::CreateTriangle, this, _1) },
		{ "rectangle", bind(&CMenu::CreateRectangle, this, _1) }
})
{
}

bool CmpAreas(const shared_ptr<IShape> & firstShape, const shared_ptr<IShape> & secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool CmpPerimeters(const shared_ptr<IShape> & firstShape, const shared_ptr<IShape> & secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
}

void CMenu::PrintInfo(ostream & output)
{
	if (!m_shapes.empty())
	{
		auto shapeWithMaxArea = max_element(m_shapes.begin(), m_shapes.end(), CmpAreas);

		auto shapeWithMinPerimeter = min_element(m_shapes.begin(), m_shapes.end(), CmpPerimeters);

		output << "\nShape with maximum area: " << endl;
		output << (*shapeWithMaxArea)->ToString() << endl;

		output << endl;

		output << "Shape with min perimeter: " << endl;
		output << (*shapeWithMinPerimeter)->ToString() << endl;
	}
}

vector<string> CMenu::GetShapeParameters(const string & paramsLine) const
{
	vector<string> params;

	const boost::char_separator<char> separator(" ");
	boost::tokenizer<boost::char_separator<char>> tokenizer(paramsLine, separator);

	copy(tokenizer.begin(), tokenizer.end(), back_inserter(params));

	return params;
}

bool CMenu::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CMenu::CreateLineSegment(istream & args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 5)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage line <x1> <y1> <x2> <y2> <outlineColor>" << endl;
		return true;
	}

	CPoint startPoint, endPoint;
	string outlineColor;

	startPoint.x = stoi(parameters[0]);
	startPoint.y = stoi(parameters[1]);

	endPoint.x = stoi(parameters[2]);
	endPoint.y = stoi(parameters[3]);

	outlineColor = parameters[4];

	m_shapes.push_back(make_shared<CLineSegment>(CLineSegment(startPoint, endPoint, outlineColor)));

	m_output << "line segment was created" << endl;
	return true;
}

bool CMenu::CreateCircle(istream & args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 5)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage circle <x1> <y1> <radius> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint center;
	double radius;

	center.x = stoi(parameters[0]);
	center.y = stoi(parameters[1]);

	radius = stod(parameters[2]);
	if (radius < 0)
	{
		m_output << "Circle radius can't be negative value." << endl;
		return true;
	}

	m_shapes.push_back(make_shared<CCircle>(CCircle(center, radius, parameters[3], parameters[4])));
	m_output << "circle was created" << endl;
	return true;
}

bool CMenu::CreateTriangle(istream & args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 8)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage triangle <x1> <y1> <x2> <y2> <x3> <y3> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint vertex1, vertex2, vertex3;

	vertex1.x = stoi(parameters[0]);
	vertex1.y = stoi(parameters[1]);

	vertex2.x = stoi(parameters[2]);
	vertex2.y = stoi(parameters[3]);

	vertex3.x = stoi(parameters[4]);
	vertex3.y = stoi(parameters[5]);

	m_shapes.push_back(make_shared<CTriangle>(CTriangle(vertex1, vertex2, vertex3, parameters[6], parameters[7])));

	m_output << "triangle was created" << endl;
	return true;
}

bool CMenu::CreateRectangle(istream & args)
{
	string shapeProperties;
	getline(args, shapeProperties);
	vector<string> parameters = GetShapeParameters(shapeProperties);

	if (parameters.size() != 6)
	{
		m_output << "Invalid parameters count." << endl
			<< "Usage rectangle <x1> <y1> <width> <height> <outlineColor> <fillColor>" << endl;
		return true;
	}

	CPoint leftTop = CPoint(0, 0);
	double width = 0;
	double height = 0;

	leftTop.x = stoi(parameters[0]);
	leftTop.y = stoi(parameters[1]);

	width = stoi(parameters[2]);
	height= stoi(parameters[3]);

	if (width < 0 || height < 0)
	{
		m_output << "Width and height can't be negative value." << endl;
		return true;
	}

	m_shapes.push_back(make_shared<CRectangle>(CRectangle(leftTop, width, height, parameters[4], parameters[5])));

	m_output << "rectangle was created" << endl;
	return true;
}

int CMenu::GetNumberOfShapes() const
{
	return m_shapes.size();
}