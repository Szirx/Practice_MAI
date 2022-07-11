#pragma once
#include "Tramway.h"
class CrashedTramway : public Tramway
{
public:
	CrashedTramway(int initX = 10, int initY = 10);
	~CrashedTramway();

	virtual void Show();
	virtual void Hide();
};