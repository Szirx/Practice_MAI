#pragma once
#include "Location.h"
class Point : public Location
{
protected:							
	bool Visible;					//светится точка или нет

public:
	Point(int InitX, int InitY);	//конструктор класса
	~Point();						//деструктор
	bool IsVisible();				//узнать про светимость точки
	void MoveTo(int NewX, int NewY);//переместить фигуру
	void Drag(int Step);			//буксировка фигуры

	virtual void Show();              //показать фигуру ТОЧКА
	virtual void Hide();              //спрятать фигуру ТОЧКА

};//end class Point