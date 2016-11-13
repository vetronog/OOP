#pragma once
#include <boost/noncopyable.hpp>
#include "Car.h"

class CCarControl : boost::noncopyable
{
public:
	CCarControl(CCar & car, std::istream & input, std::ostream & output);
	bool HandleCommand();
	bool TurnOnEngine(std::istream & args);
	bool TurnOffEngine(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
	bool Info(std::istream & args);
	std::string GetDirectionString(Direction const& direction);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CCar & m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};