#pragma once

#include "Water.h"

class Acid : public Water
{
public:
	Acid(int InitX1, int InitY1);
	~Acid();

	void Show();
	void Hide();
};