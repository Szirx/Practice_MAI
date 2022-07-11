#pragma once
#include "ITV.h"

class PlasmaTV : public ITV
{
protected:
	int height;
	int width;

public:
	PlasmaTV(int inX1, int inY1, int inWidth, int inHeight);
	~PlasmaTV();

	int GetWidth() const;
	int GetHeight() const;

	virtual void Show();
	virtual void Hide();
};