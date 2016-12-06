#include "stdafx.h"
#include "Control.h"
#include "IShape.h"

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(std::ifstream & input, std::ostream & output)
	:m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", bind(&CRemoteControl::CreateLine, this, _1) },
})
{
}

void CRemoteControl::PrintInfo() const
{
	if (!m_shapes.empty())
	{

		auto shapeWithMaxArea = std::max_element(m_shapes.begin(), m_shapes.end(), []
		(auto const& firstShape, auto const& secondShape)
		{
			return firstShape->GetArea() < secondShape->GetArea();
		});
		m_output << "The shape with the largest area:\n";
		m_output << (*shapeWithMaxArea)->ToString() << "\n";

		m_output << "|SHAPES|\n";
		for (auto const& shape : m_shapes)
		{
			m_output << ">" << shape->ToString() << "\n";

		}

		auto shapeWithMinPerimeter = std::min_element(m_shapes.begin(), m_shapes.end(), []
		(auto const& firstShape, auto const& secondShape)
		{
			return firstShape->GetPerimeter() < secondShape->GetPerimeter();
		});
		m_output << "Shape with minimum perimeter:\n";
		m_output << (*shapeWithMinPerimeter)->ToString() << "\n";

	}
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string action;
	strm >> action;
	if (strm.eof() && action.empty())
	{
		return true;
	}
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}
	return false;
}

bool CRemoteControl::CreateLine(std::istream & args)
{
	std::shared_ptr<CLineSegment> lineSegment;
	args >> lineSegment;
	m_shapes.push_back(lineSegment);
	return true;
}
