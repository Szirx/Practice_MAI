#include "Water.h"

Water::Water(int InitX1, int InitY1) :Point(InitX1, InitY1) {};

Water::~Water(void) {};
void Water::Show(void)
{
	HPEN Pen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 17, Y1 + 74);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 46, Y1 + 61);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 50, Y1 + 38);
}
void Water::Hide(void)
{
	HPEN Pen = CreatePen(PS_DOT, 1, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 17, Y1 + 74);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 46, Y1 + 61);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 50, Y1 + 38);
}