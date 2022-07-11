#include "Bird.h"

Bird::Bird(int InitX1, int InitY1, int InitRadius) :Point(InitX1, InitY1) {
	Radius = InitRadius;
};

Bird::~Bird() {};


void Bird::Show(void)
{
	HPEN Pen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(255, 170, 0));
	HPEN Pen3 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen1);	//сделаем перо активным
	Ellipse(hdc, X1 - 0.08 * Radius, Y1 - 0.08 * Radius, X1 + 38 + 0.08 *Radius, Y1 + 40 + 0.08 * Radius);
	SelectObject(hdc, Pen3);
	Ellipse(hdc, X1 + 19 - 0.03 * Radius, Y1 + 11 - 0.03 * Radius, X1 + 28 + 0.03 * Radius, Y1 + 22 + 0.03 * Radius);
	SelectObject(hdc, Pen2);
	MoveToEx(hdc, X1 + 39, Y1 + 14, NULL);
	LineTo(hdc, X1 + 59, Y1 + 21);
	MoveToEx(hdc, X1 + 36, Y1 + 31, NULL);
	LineTo(hdc, X1 + 59, Y1 + 21);
	DeleteObject(Pen1);
	DeleteObject(Pen2);
	DeleteObject(Pen3);
};

void Bird::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 - 0.08 * Radius, Y1 - 0.08 * Radius, X1 + 38 + 0.08 * Radius, Y1 + 40 + 0.08 * Radius);
	Ellipse(hdc, X1 + 19 - 0.03 * Radius, Y1 + 11 - 0.03 * Radius, X1 + 28 + 0.03 * Radius, Y1 + 22 + 0.03 * Radius);
	MoveToEx(hdc, X1 + 39, Y1 + 14, NULL);
	LineTo(hdc, X1 + 59, Y1 + 21);
	MoveToEx(hdc, X1 + 36, Y1 + 31, NULL);
	LineTo(hdc, X1 + 59, Y1 + 21);
	DeleteObject(Pen);
};
