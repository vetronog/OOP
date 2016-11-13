#include "stdafx.h"
#include "CarControl.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;


CCarControl::CCarControl(CCar & car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "EngineOn", bind(&CCarControl::TurnOnEngine, this, _1) },
		{ "EngineOff", bind(&CCarControl::TurnOffEngine, this, _1) },
		{ "SetGear", bind(&CCarControl::SetGear, this, _1) },
		{ "SetSpeed", bind(&CCarControl::SetSpeed, this, _1) },
		{ "Info", bind(&CCarControl::Info, this, _1) },
})
{
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
	}
	else
	{
		return false;
	}
	return true;
}

bool CCarControl::TurnOnEngine(std::istream & /*args*/)
{
	bool isTurnOnEngine = m_car.TurnOnEngine();
	std::string output = isTurnOnEngine ? "Engine is turned on\n" : "Engine is already on!\n";
	m_output << output;
	return isTurnOnEngine;
}

bool CCarControl::TurnOffEngine(std::istream & /*args*/)
{
	bool isTurnOff = m_car.TurnOffEngine();
	std::string output = isTurnOff ? "Engine is turned off\n" : "Engine is already off, not on neutral gear or not carero speed!\n";
	m_output << output;
	return isTurnOff;
}

bool CCarControl::SetGear(std::istream & args)
{
	int gear;
	args >> gear;
	bool isSetGear = m_car.SetGear(gear);
	std::string output = isSetGear ? "Gear: " + std::to_string(m_car.GetGear()) : "Error: Gear can not switch at the moment!";
	m_output << output << endl;
	return isSetGear;
}

bool CCarControl::SetSpeed(std::istream & args)
{
	int speed;
	args >> speed;
	bool isSetSpeed = m_car.SetSpeed(speed);
	std::string output = isSetSpeed ? "Speed: " + std::to_string(m_car.GetCurrentSpeed()) : "Error: Speed is not the same as a valid gear value or gear is neutral!";
	m_output << output << endl;
	return isSetSpeed;
}

bool CCarControl::Info(std::istream & /*args*/)
{
	std::string output = m_car.IsTurnOnEngine() ?
		"Engine is turned on\n"
		"Direction: " + GetDirectionString(m_car.GetDirection()) + "\n"
		"Gear: " + std::to_string(m_car.GetGear()) + "\n"
		"Speed: " + std::to_string(m_car.GetCurrentSpeed()) + "\n"
		: "Engine is turned off\n";
	m_output << output;
	return true;
}

std::string CCarControl::GetDirectionString(Direction const& direction)
{
	std::string result;
	if (direction == Direction::FORWARD)
	{
		result = "Forward";
	}
	else if (direction == Direction::BACKWARD)
	{
		result = "Backward";
	}
	else
	{
		result = "Standing";
	}
	return result;
}
