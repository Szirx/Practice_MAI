#pragma once
#include "Body.h"
class Trolleybus : public Body
{
public:
	//конструктор с параметрами по умолчанию
	Trolleybus(int InitX1 = 10, int InitY1 = 10);
	~Trolleybus();					//деструктор

	virtual void Show();
	virtual void Hide();

};//end class Trolleybus