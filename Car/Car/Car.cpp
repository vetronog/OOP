#include "stdafx.h"
#include "Car.h"

static const SpeedRange speedRange = {
	{ Gear::REVERSE, Speed(0, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(0, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, 150) }
};


bool CCar::IsNeutralGear() const
{
	return m_currentGear == Gear::NEUTRAL_GEAR;
}

int CCar::GetGear() const
{
	return static_cast<int>(m_currentGear);
}

unsigned CCar::GetCurrentSpeed() const
{
	return m_speed;
}

bool CCar::IsTurnOnEngine() const
{
	return m_isEngineOn;
}

bool CCar::TurnOnEngine()
{
	return !m_isEngineOn ? m_isEngineOn = true : false;
}

bool CCar::TurnOffEngine()
{
	bool isTurnOffEngine = false;
	if (m_isEngineOn && (m_speed == 0) && IsNeutralGear())
	{
		m_isEngineOn = false;
		isTurnOffEngine = true;
	}
	return isTurnOffEngine;
}

bool CCar::CheckGear(int gear) const
{
	return ((static_cast<Gear>(gear) == Gear::REVERSE) && (m_speed == 0)) ||
		((m_currentGear == Gear::REVERSE) && (static_cast<Gear>(gear) == Gear::FIRST_GEAR) && (m_speed == 0)) ||
		((m_currentGear == Gear::NEUTRAL_GEAR) && (static_cast<Gear>(gear) == Gear::FIRST_GEAR) && (m_speed == 0)) ||
		((static_cast<Gear>(gear) == Gear::NEUTRAL_GEAR)) ||
		((m_currentGear != Gear::REVERSE) && (static_cast<Gear>(gear) >= Gear::FIRST_GEAR) && (m_speed >= 0));
}

bool CCar::IsSpeedInRange(Gear const& gear, int speed) const
{
	auto it = speedRange.find(gear);
	auto speedRange = it->second;
	return (speed >= speedRange.first) && (speed <= speedRange.second);
}

bool CCar::SetGear(int gear)
{
	bool isSetGear = false;
	bool isAvailableGear = m_isEngineOn && (gear >= MIN_GEAR) && (gear <= MAX_GEAR);
	if (isAvailableGear)
	{
		if(isAvailableGear && IsSpeedInRange(static_cast<Gear>(gear), GetCurrentSpeed()) && CheckGear(gear))
		{
			m_currentGear = static_cast<Gear>(gear);
			isSetGear = true;
		}
	}
	return isSetGear;
}

bool CCar::SetSpeed(int speed)
{
	bool isSetSpeed = false;
	if (IsSpeedInRange(m_currentGear, speed))
	{
		if (IsNeutralGear() && (speed <= GetCurrentSpeed()) || !IsNeutralGear())
		{
			m_speed = (Gear::REVERSE == m_currentGear) || (m_speed < 0) ? -speed : speed;
			isSetSpeed = true;
		}
	}
	return isSetSpeed;
}

Direction CCar::GetDirection() const
{
	Direction direction;
	if (m_speed > 0)
	{
		direction = Direction::FORWARD;
	}
	else if (m_speed < 0)
	{
		direction = Direction::BACKWARD;
	}
	else
	{
		direction = Direction::STAND;
	}
	return direction;
}