#pragma once
#include "AbsBody.h"
class Body : public AbsBody
{
public:
	//����������� � ����������� �� ���������
	Body(int InitX1 = 10, int InitY1 = 10);
	~Body();					//����������

	int GetWidth();
	int GetHeigth();

	virtual	void Show();
	virtual	void Hide();	

};//end class Body