#pragma once
#include "ABCFigure.h"

class Remote : public ABCFigure
{
protected:
	int height;
	int width;

public:
	Remote(int inX1, int inY1, int inWidth, int inHeight);
	~Remote();

	int GetWidth() const;
	int GetHeight() const;

	virtual void Show();
	virtual void Hide();

};

