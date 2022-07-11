#pragma once
#include "Trash.h"
class BigTrash : public Trash
{
public:
	//конструктор с параметрами по умолчанию
	BigTrash(int InitX1 = 10, int InitY1 = 10);
	~BigTrash();					//деструктор

	virtual	void Show();
	virtual	void Hide();

};//end class Body