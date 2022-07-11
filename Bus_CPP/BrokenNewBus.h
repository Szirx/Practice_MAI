#pragma once
#include "NewBus.h"
class BrokenNewBus : public NewBus
{
public:
	BrokenNewBus(int initX = 10, int initY = 10);
	~BrokenNewBus();

	virtual void Show();
	virtual void Hide();
};