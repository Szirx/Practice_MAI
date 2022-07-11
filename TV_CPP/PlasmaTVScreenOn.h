#pragma once
#include "PlasmaTVonStand.h"

class PlasmaTVScreenOn : public PlasmaTVonStand
{
public:
	PlasmaTVScreenOn(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVScreenOn();

	virtual void Show();
	virtual void Hide();
};