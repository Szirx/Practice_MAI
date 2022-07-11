#pragma once
#include "Trolleybus.h"
class CrashedTrolleybus : public Trolleybus
{
public:
	CrashedTrolleybus(int initX = 10, int initY = 10);
	~CrashedTrolleybus();

	virtual void Show();
	virtual void Hide();
};