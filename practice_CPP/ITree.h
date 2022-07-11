#pragma once
#include "Point.h"
class ITree : public Point
{
public:
	ITree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	virtual ~ITree() = default;

	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Show() = 0;
	virtual void Hide() = 0;
};

