#pragma once
#include "Point.h"
class AbsBody : public Point
{
protected:
	int width = 0;			//длина фигуры
	int heigth = 0;			//высота фигуры
	int X2 = 0;				//вторая координата X
	int Y2 = 0;				//вторая координата Y
public:
	//конструктор с параметрами по умолчанию
	AbsBody(int InitX1 = 10, int InitY1 = 10);
	~AbsBody() = default;					//деструктор

	virtual int GetWidth() = 0;
	virtual int GetHeigth() = 0;

	virtual	void Show() = 0;
	virtual	void Hide() = 0;

};//end class AbsBody