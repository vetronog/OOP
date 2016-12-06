#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape(std::string const& type);
	virtual ~ISolidShape() = default;//для устранения утечек памяти(только если наследуется от интерфейса(лекция Малова))
	virtual std::string GetFillColor() const = 0;
};