#pragma once

#include "Body.h"

class TreeWithBranch : public Body
{
public:
	TreeWithBranch(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~TreeWithBranch();

	virtual void Show();
	virtual void Hide();
};