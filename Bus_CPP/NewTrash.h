#pragma once
#include "Trash.h"
class NewTrash : public Trash
{
public:
	//����������� � ����������� �� ���������
	NewTrash(int InitX1 = 10, int InitY1 = 10);
	~NewTrash();					//����������

	virtual	void Show();
	virtual	void Hide();

};//end class Body