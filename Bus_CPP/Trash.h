#pragma once
#include "iTrash.h"
class Trash : public iTrash
{
protected:
	int heigth = 100;
	int width = 60;
	int X2 = 100;				//������ ���������� X
	int Y2 = 100;				//������ ���������� Y
public:
	//����������� � ����������� �� ���������
	Trash(int InitX1 = 10, int InitY1 = 10);
	~Trash();					//����������

	int GetWidth();
	int GetHeigth();

	virtual	void Show();
	virtual	void Hide();

};//end class Body