#pragma once
#include "Remote.h"
class RemoteRound : public Remote
{
public:
	RemoteRound(int inX1, int inY1, int inWidth, int inHeight);
	~RemoteRound();

	virtual void Show();
	virtual void Hide();
};

