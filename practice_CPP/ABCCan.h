#pragma once
#include "Point.h"
class ABCCan : public Point
{
protected:
	int Radius;
public:
	ABCCan(int InitX1, int InitY1, int InitRadius);
	virtual ~ABCCan() = default;

	virtual void Show() = 0;
	virtual void Hide() = 0;
};

