#pragma once
#include "Trash.h"
class BigTrash : public Trash
{
public:
	//����������� � ����������� �� ���������
	BigTrash(int InitX1 = 10, int InitY1 = 10);
	~BigTrash();					//����������

	virtual	void Show();
	virtual	void Hide();

};//end class Body