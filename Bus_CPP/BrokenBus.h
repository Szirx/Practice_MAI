#pragma once
#include "Bus.h"
class BrokenBus : public Bus
{
public:
	BrokenBus(int initX = 10, int initY = 10);
	~BrokenBus();

	virtual void Show();
	virtual void Hide();
};