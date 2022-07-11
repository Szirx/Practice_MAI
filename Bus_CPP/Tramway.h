#pragma once
#include "Body.h"
class Tramway : public Body
{
public:
	//конструктор с параметрами по умолчанию
	Tramway(int InitX1 = 10, int InitY1 = 10);
	~Tramway();					//деструктор

	virtual void Show();
	virtual void Hide();

};//end class Tramway