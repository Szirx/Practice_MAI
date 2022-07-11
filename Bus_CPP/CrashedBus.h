#pragma once
#include "Bus.h"
class CrashedBus : public Bus
{
public:
	CrashedBus(int initX = 10, int initY = 10);
	~CrashedBus();

	virtual void Show();
	virtual void Hide();
};