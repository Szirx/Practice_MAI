#pragma once
#include "Remote.h"
class RemoteOld : public Remote
{
public:
	RemoteOld(int inX1, int inY1, int inWidth, int inHeight);
	~RemoteOld();

	virtual void Show();
	virtual void Hide();
};

