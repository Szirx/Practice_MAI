#pragma once
#include "Tramway.h"
class BrokenTramway : public Tramway
{
public:
	BrokenTramway(int initX = 10, int initY = 10);
	~BrokenTramway();

	virtual void Show();
	virtual void Hide();
};