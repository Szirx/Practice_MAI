#pragma once
#include "PlasmaTVonStand.h"
class PlasmaTVColorScreen :
    public PlasmaTVonStand
{
public:
	PlasmaTVColorScreen(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVColorScreen();

	virtual void Show();
	virtual void Hide();
};

