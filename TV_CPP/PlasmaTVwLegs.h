#pragma once
#include "PlasmaTV.h"

class PlasmaTVwLegs : public PlasmaTV
{
public:
	PlasmaTVwLegs(int inX, int inY, int inWidth, int inHeight);
	~PlasmaTVwLegs();

	virtual void Show();
	virtual void Hide();
}; 
