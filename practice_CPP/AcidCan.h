#pragma once
#include "WateringCan.h"

class AcidCan : public WateringCan
{
public:
	AcidCan(int InitX1, int InitY1, int InitRadius);
	~AcidCan();

	virtual void Show();
	virtual void Hide();
};