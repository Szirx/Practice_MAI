#pragma once
#include "iTrash.h"
class Trash : public iTrash
{
protected:
	int heigth = 100;
	int width = 60;
	int X2 = 100;				//вторая координата X
	int Y2 = 100;				//вторая координата Y
public:
	//конструктор с параметрами по умолчанию
	Trash(int InitX1 = 10, int InitY1 = 10);
	~Trash();					//деструктор

	int GetWidth();
	int GetHeigth();

	virtual	void Show();
	virtual	void Hide();

};//end class Body