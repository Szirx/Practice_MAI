#pragma once
#include "Location.h"
/*-----------------------  Класс ТОЧКА ----------------------------------*/
class Point : public Location
{
	// Point - производный класс от Location
	// атрибут public в объявлении производного класса означает
	// возможность вызова любого из полей и методов, унаследованных
	// от Location

protected:							//классам, производным от Point, потребуется доступ public
	bool Visible;					//светится точка или нет

public:
	Point(int InitX1, int InitY1);	//конструктор класса
	virtual ~Point();	// виртуальный деструктор
	bool IsVisible();				//узнать про светимость точки
	virtual void MoveTo(int NewX1, int NewY1);//переместить фигуру
	virtual void Drag(int Step);			//буксировка фигуры

	//int GetX1();

		//виртуальные функции
	virtual void Show();              //показать фигуру ТОЧКА
	virtual void Hide();              //спрятать фигуру ТОЧКА

};//end class Point