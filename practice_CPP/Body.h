#pragma once

#include "ITree.h"

class Body : public ITree
{
protected:
	int Radius;
	int height;
	int width;
public:
	Body(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius);
	~Body();

	virtual int GetWidth() const;
	virtual int GetHeight() const;

	virtual void Show();
	virtual void Hide();
};