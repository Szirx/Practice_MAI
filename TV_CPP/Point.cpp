#include<windows.h>
#include "PlasmaTV.h"
#include "Point.h."
#include <iostream>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)


/*---------------------------  Методы класса "Point" -----------------------------------*/

Point::Point(int inX, int inY) : Coordinates() {
	Visible = false;
	X = inX;
	Y = inY;
}

Point::~Point() {

}

int Point::GetX() const {
	return X;
}

int Point::GetY() const {
	return Y;
}

void Point::Show() {
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}

void Point::Hide() {
	this->Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

bool Point::IsVisible() {
	return Visible;
}

void Point::Move(int newX, int newY) {
	Hide();		//сделать точку невидимой
	X = newX;	//поменять координаты ТОЧКИ
	Y = newY;
	Show();		//показать точку на новом месте
}


void Point::Drag(int step) {

	int FigX, FigY;   //новые координаты фигуры
	int sleepTime = 10;
	FigX = GetX();    //получаем начальное положение фигуры
	FigY = GetY();


	//направление движения объекта

	if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
	{
		FigX -= step;
		Move(FigX, FigY);
		Sleep(sleepTime);
	}//end if

	if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
	{
		FigX += step;
		Move(FigX, FigY);
		Sleep(sleepTime);
	}//end if

	if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
	{
		FigY += step;
		Move(FigX, FigY);
		Sleep(sleepTime);
	}//end if

	if (KEY_DOWN(VK_UP)) //стрелка вверх  38
	{
		FigY -= step;
		Move(FigX, FigY);
		Sleep(sleepTime);
	}//end if

}

/*--------------------------------------------------------------------------------------*/