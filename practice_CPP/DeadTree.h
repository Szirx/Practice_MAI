#pragma once
#include "Body.h"
class DeadTree : public Body
{
public:
	DeadTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~DeadTree();

	virtual void Show();
	virtual void Hide();
};

