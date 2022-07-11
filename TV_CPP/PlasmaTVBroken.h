#pragma once
#include "PlasmaTVonStand.h"

class PlasmaTVBroken : public PlasmaTVonStand
{
public:
	PlasmaTVBroken(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVBroken();

	virtual void Show();
	virtual void Hide();
};

