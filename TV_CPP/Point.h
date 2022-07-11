#pragma once
#include "Coordinates.h"
/*---------------------------  ����� ����� -----------------------------------*/

class Point : public Coordinates
{
protected:
	int X;
	int Y;
	bool Visible;
	
public:
	Point(int inX, int inY);
	~Point();

	bool IsVisible();
	void Move(int newX, int newY);
	
	void Drag(int step);
	
	int GetX() const;
	int GetY() const;

	virtual void Show();
	virtual void Hide();
};

/*----------------------------------------------------------------------------*/