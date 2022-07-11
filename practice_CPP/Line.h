#pragma once
#include "Point.h"


class Line : public Point
{
protected:
	int X2, Y2;
public:
	Line(int InitX1, int InitY1, int InitX2, int InitY2);
	~Line();

	void Drag(int step);
	
	int GetX2();
	int GetY2();

	void MoveTo(int NewX1, int NewY1, int NewX2, int NewY2);

	virtual void Show();
	virtual void Hide();
};
