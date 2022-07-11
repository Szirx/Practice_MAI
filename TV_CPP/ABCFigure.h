 #pragma once
#include "Point.h"
class ABCFigure : public Point
{
protected:
	int height;
	int width;

public:
	ABCFigure(int inX1, int inY1, int inWidth, int inHeight);
	virtual ~ABCFigure() = default;

	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Show() = 0;
	virtual void Hide() = 0;
};

