#pragma once
#include "PlasmaTVonStand.h"
class PLasmaTVExtra : public PlasmaTVonStand
{
public:
	PLasmaTVExtra(int inX, int inY, int inWidth, int inHeight);
	~PLasmaTVExtra();

	virtual void Show();
	virtual void Hide();
};

