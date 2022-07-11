#pragma once
#include "PlasmaTVonStand.h"
class PlasmaTVBlueScreen :
    public PlasmaTVonStand
{
public:
	PlasmaTVBlueScreen(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVBlueScreen();

	virtual void Show();
	virtual void Hide();
};

