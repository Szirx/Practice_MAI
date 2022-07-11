#pragma once
#include "PlasmaTVonStand.h"

class PlasmaTVScreenOff : public PlasmaTVonStand
{
public:
	PlasmaTVScreenOff(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVScreenOff();

	virtual void Show();
	virtual void Hide();
};