#pragma once
#include "Remote.h"

class RemoteNew : public Remote
{

public:
	RemoteNew(int inX1, int inY1, int inWidth, int inHeight);
	~RemoteNew();

	virtual void Show();
	virtual void Hide();
};

