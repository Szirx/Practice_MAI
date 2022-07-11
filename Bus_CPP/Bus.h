#pragma once
#include "Body.h"
class Bus : public Body
{
public:
	//конструктор с параметрами по умолчанию
	Bus(int InitX1 = 10, int InitY1 = 10);
	~Bus();					//деструктор

	virtual void Show(); 
	virtual void Hide();

};//end class Bus