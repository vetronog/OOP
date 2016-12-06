#pragma once
#include <boost/noncopyable.hpp>
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


class IShape;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(std::ifstream & input, std::ostream & output);
	bool HandleCommand();
	void PrintInfo() const;
private:
	void CreateLine(std::istream & args);
	void CreateTriangle(std::istream & args);
	void CreateRectangle(std::istream & args);
	void CreateCircle(std::istream & args);
	typedef std::map<std::string, std::function<void(std::istream & args)>> ActionMap;

	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::ifstream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};
