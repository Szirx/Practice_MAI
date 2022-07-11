#pragma once
#include "Point.h"

/*-----------------------  Класс КРУГ  ----------------------------------*/
class Circle : public Point
{
protected:
	//private:						//необязательно , т.к. по умолчанию
	int Radius;					//радиус круга
public:
	//конструктор с параметрами по умолчанию
	Circle(int InitX1 = 10, int InitY1 = 10, int InitRadius = 10);

	virtual ~Circle();	// виртуальный деструктор

	void Expand(int DeltaRad);	//увеличить радиус КРУГА
	void Reduce(int DeltaRad);	//уменьшить радиус КРУГА

	virtual	void Show();		//показать фигуру КРУГ
	virtual	void Hide();		//скрыть фигуру КРУГ

//	void MoveTo (int NewX, int NewY);  //можно убрать совсем! берем из Point

};//end class Circle