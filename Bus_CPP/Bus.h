#pragma once
#include "Body.h"
class Bus : public Body
{
public:
	//����������� � ����������� �� ���������
	Bus(int InitX1 = 10, int InitY1 = 10);
	~Bus();					//����������

	virtual void Show(); 
	virtual void Hide();

};//end class Bus