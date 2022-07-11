#pragma once
#include "Point.h"

class Bird : public Point
{
protected:
	int Radius;
public:
	Bird(int InitX1, int InitY1, int InitRadius);
	~Bird();

	void Show();
	void Hide();
};

