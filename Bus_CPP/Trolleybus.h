#pragma once
#include "Body.h"
class Trolleybus : public Body
{
public:
	//����������� � ����������� �� ���������
	Trolleybus(int InitX1 = 10, int InitY1 = 10);
	~Trolleybus();					//����������

	virtual void Show();
	virtual void Hide();

};//end class Trolleybus