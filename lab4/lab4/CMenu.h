#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include <sstream>
#include "CShape.h"

using namespace std;

class CMenu : boost::noncopyable
{
public:
	CMenu(istream & input, ostream & output);
	bool HandleCommand();
	void PrintInfo(ostream & output);
	vector<shared_ptr<IShape>> GetСollectionOfShapes() const;
private:
	bool CreateLineSegment(istream & args);
	bool CreateCircle(istream & args);
	bool CreateTriangle(istream & args);
	bool CreateRectangle(istream & args);
	vector<string> GetShapeParameters(const string & paremeters) const;

	typedef map<string, function<bool(istream & args) >> ActionMap;

	vector<shared_ptr<IShape>> m_shapes;
	istream & m_input;
	ostream & m_output;

	const ActionMap m_actionMap;
};