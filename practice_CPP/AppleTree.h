#pragma once
#include "MultiTieredTree.h"

class AppleTree : public MultiTieredTree
{
public:
	AppleTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~AppleTree();

	virtual void Show();
	virtual void Hide();
};

