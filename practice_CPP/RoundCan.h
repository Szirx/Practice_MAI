#pragma once
#include "WateringCan.h"
class RoundCan : public WateringCan
{
public:
	RoundCan(int InitX1, int InitY1, int InitRadius);
	~RoundCan();

	virtual void Show();
	virtual void Hide();
};

