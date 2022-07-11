#pragma once

#include "Point.h"

class Water : public Point
{
public:
	Water(int InitX1, int InitY1);
	~Water();

	void Show();
	void Hide();
};