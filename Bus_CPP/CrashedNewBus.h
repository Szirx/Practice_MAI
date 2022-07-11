#pragma once
#include "NewBus.h"
class CrashedNewBus : public NewBus
{
public:
	CrashedNewBus(int initX = 10, int initY = 10);
	~CrashedNewBus();

	virtual void Show();
	virtual void Hide();
};