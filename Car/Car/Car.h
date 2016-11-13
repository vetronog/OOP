#pragma once
#include "stdafx.h"
#include "Const.h"

typedef std::pair<unsigned, unsigned> Speed;
typedef std::map<Gear, Speed> SpeedRange;
extern const SpeedRange speedRange;

class CCar
{
public:
	int GetGear() const;
	unsigned GetCurrentSpeed() const;
	Direction GetDirection() const;
	bool IsTurnOnEngine() const;
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(int gear);
	bool SetSpeed(int speed);

	bool IsNeutralGear() const;
	bool IsSpeedInRange(Gear const& gear, int speed) const;
	bool CheckGear(int gear) const;
private:
	bool m_isEngineOn = false;
	Gear m_currentGear = Gear::NEUTRAL_GEAR;
	unsigned m_speed = 0;
};