#include "RoundCan.h"
#pragma once

RoundCan::RoundCan(int InitX1, int InitY1, int InitRadius) :WateringCan(InitX1, InitY1, InitRadius) {
};

RoundCan::~RoundCan(void) {};


void RoundCan::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 200));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 - 24 - 0.1 * Radius, Y1 - 22 - 0.1 * Radius, X1 + 18 + 0.1 * Radius, Y1 + 18 + 0.1 * Radius);
	MoveToEx(hdc, X1 + 34, Y1 + 18, NULL);
	LineTo(hdc, X1 + 80, Y1);
	MoveToEx(hdc, X1 + 34, Y1, NULL);
	LineTo(hdc, X1 + 80, Y1);
	Ellipse(hdc, X1 - 0.1 * Radius, Y1 - 0.1 * Radius, X1 + 60 + 0.1 * Radius, Y1 + 50 + 0.1 * Radius);

	DeleteObject(Pen);
}

void RoundCan::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 - 24 - 0.1 * Radius, Y1 - 22 - 0.1 * Radius, X1 + 18 + 0.1 * Radius, Y1 + 18 + 0.1 * Radius);
	MoveToEx(hdc, X1 + 37, Y1 + 18, NULL);
	LineTo(hdc, X1 + 90, Y1);
	MoveToEx(hdc, X1 + 37, Y1, NULL);
	LineTo(hdc, X1 + 90, Y1);
	Ellipse(hdc, X1 - 0.1 * Radius, Y1 - 0.1 * Radius, X1 + 60 + 0.1 * Radius, Y1 + 50 + 0.1 * Radius);

	DeleteObject(Pen);
}