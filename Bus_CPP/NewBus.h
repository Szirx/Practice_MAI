#pragma once
#include "Body.h"
class NewBus : public Body
{
public:
	//����������� � ����������� �� ���������
	NewBus(int InitX1 = 10, int InitY1 = 10);
	~NewBus();					//����������

	virtual void Show();
	virtual void Hide();

};//end class Bus