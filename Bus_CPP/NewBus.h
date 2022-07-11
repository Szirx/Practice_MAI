#pragma once
#include "Body.h"
class NewBus : public Body
{
public:
	//конструктор с параметрами по умолчанию
	NewBus(int InitX1 = 10, int InitY1 = 10);
	~NewBus();					//деструктор

	virtual void Show();
	virtual void Hide();

};//end class Bus