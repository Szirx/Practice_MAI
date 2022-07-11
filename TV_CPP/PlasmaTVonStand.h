#pragma once
#include "PlasmaTVwLegs.h"

class PlasmaTVonStand : public PlasmaTVwLegs
{
public:
	PlasmaTVonStand(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVonStand();

	virtual void Show();
	virtual void Hide();
};