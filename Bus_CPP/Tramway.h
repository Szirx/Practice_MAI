#pragma once
#include "Body.h"
class Tramway : public Body
{
public:
	//����������� � ����������� �� ���������
	Tramway(int InitX1 = 10, int InitY1 = 10);
	~Tramway();					//����������

	virtual void Show();
	virtual void Hide();

};//end class Tramway