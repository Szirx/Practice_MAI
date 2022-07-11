#pragma once
#include "Remote.h"
class RemoteExtra : public Remote
{
public:
	RemoteExtra(int inX1, int inY1, int inWidth, int inHeight);
	~RemoteExtra();

	virtual void Hide();
	virtual void Show();
};
