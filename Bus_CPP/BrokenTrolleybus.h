#pragma once
#include "Trolleybus.h"
class BrokenTrolleybus : public Trolleybus
{
public:
	BrokenTrolleybus(int initX = 10, int initY = 10);
	~BrokenTrolleybus();

	virtual void Show();
	virtual void Hide();
};