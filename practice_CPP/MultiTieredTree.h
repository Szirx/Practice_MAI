#pragma once

#include "Body.h"

class MultiTieredTree : public Body
{
public:
	MultiTieredTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~MultiTieredTree();

	virtual void Show();
	virtual void Hide();
};
