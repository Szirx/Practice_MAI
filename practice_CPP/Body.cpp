#include <Windows.h>
#include "Body.h"

Body::Body(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius):
	ITree(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {
	Radius = InitRadius;
	width = InitWidth;
	height = InitHeight;
};

Body::~Body(void) {};

int Body::GetHeight() const
{
	return height;
}

int Body::GetWidth() const
{
	return width;
}

void Body::Show(void)
{
	HPEN Pen1 = CreatePen(PS_SOLID, 5, RGB(150, 75, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, Pen1);	//сделаем перо активным
	Rectangle(hdc, X1 - 12, Y1, X1 + 13, Y1 + 180);
	SelectObject(hdc, Pen2);
	Ellipse(hdc, X1 - 10 - 1.2 * Radius, Y1 - 30 - 1.2 * Radius, X1 + 10 + 1.2 * Radius, Y1 - 10 + 1.2 * Radius);

	DeleteObject(Pen1);
	DeleteObject(Pen2);
}

void Body::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Rectangle(hdc, X1 - 12, Y1, X1 + 13, Y1 + 180);
	Ellipse(hdc, X1 - 10 - 1.2 * Radius, Y1 - 30 - 1.2 * Radius, X1 + 10 + 1.2 * Radius, Y1 - 10 + 1.2 * Radius);

	DeleteObject(Pen);
}


