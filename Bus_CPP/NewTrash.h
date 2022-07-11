#pragma once
#include "Trash.h"
class NewTrash : public Trash
{
public:
	//конструктор с параметрами по умолчанию
	NewTrash(int InitX1 = 10, int InitY1 = 10);
	~NewTrash();					//деструктор

	virtual	void Show();
	virtual	void Hide();

};//end class Body