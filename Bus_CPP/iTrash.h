#pragma once
#include "Point.h"
class iTrash : public Point
{
public:
	//конструктор с параметрами по умолчанию
	iTrash(int InitX1 = 10, int InitY1 = 10);
	virtual ~iTrash() = default;					//деструктор

	virtual int GetWidth() = 0;
	virtual int GetHeigth() = 0;

	virtual	void Show() = 0;
	virtual	void Hide() = 0;
};//end class iTrash