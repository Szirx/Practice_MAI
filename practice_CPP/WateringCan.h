#pragma once

#include "ABCCan.h"

class WateringCan : public ABCCan
{
public:
	WateringCan(int InitX1, int InitY1,  int InitRadius);
	~WateringCan();

	virtual void Show();
	virtual void Hide();
};