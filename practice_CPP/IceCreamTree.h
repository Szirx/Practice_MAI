#pragma once

#include "Body.h"

class IceCreamTree : public Body
{
public:
	IceCreamTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~IceCreamTree();

	virtual void Show();
	virtual void Hide();
};