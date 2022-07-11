#pragma once
#include "Point.h"
class ITV : public Point
{

public:
	ITV(int inX1, int inY1, int inWidth, int inHeight);
	virtual ~ITV() = default;


	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Show() = 0;
	virtual void Hide() = 0;
};