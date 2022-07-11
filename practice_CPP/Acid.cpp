#include "Acid.h"

Acid::Acid(int InitX1, int InitY1):Water(InitX1, InitY1) {};

Acid::~Acid(void) {};
void Acid::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 17, Y1 + 74);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 46, Y1 + 61);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 50, Y1 + 38);
}
void Acid::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 17, Y1 + 74);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 46, Y1 + 61);
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X1 + 50, Y1 + 38);
}