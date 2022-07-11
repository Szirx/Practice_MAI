#include "DeadTree.h"

DeadTree::DeadTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius) :Body(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {};

DeadTree::~DeadTree(void) {};

void DeadTree::Show(void)
{
	Body::Show();
	HPEN Pen1 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 5, RGB(150, 75, 0));
	SelectObject(hdc, Pen2);	//сделаем перо активным
	MoveToEx(hdc, X1 - 12, Y1 + 135, NULL);
	LineTo(hdc, X1 - 50, Y1 + 84);
	MoveToEx(hdc, X1 + 12, Y1 + 149, NULL);
	LineTo(hdc, X1 + 39, Y1 + 115);
	MoveToEx(hdc, X1 - 12, Y1 + 95, NULL);
	LineTo(hdc, X1 - 50, Y1 + 44);
	MoveToEx(hdc, X1 + 12, Y1 + 109, NULL);
	LineTo(hdc, X1 + 39, Y1 + 75);
	MoveToEx(hdc, X1 + 12, Y1 + 69, NULL);
	LineTo(hdc, X1 + 39, Y1 + 35);
}

void DeadTree::Hide(void)
{
	Body::Hide();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1 - 12, Y1 + 135, NULL);
	LineTo(hdc, X1 - 50, Y1 + 84);
	MoveToEx(hdc, X1 + 12, Y1 + 149, NULL);
	LineTo(hdc, X1 + 39, Y1 + 115);
	MoveToEx(hdc, X1 - 12, Y1 + 95, NULL);
	LineTo(hdc, X1 - 50, Y1 + 44);
	MoveToEx(hdc, X1 + 12, Y1 + 109, NULL);
	LineTo(hdc, X1 + 39, Y1 + 75);
	MoveToEx(hdc, X1 + 12, Y1 + 69, NULL);
	LineTo(hdc, X1 + 39, Y1 + 35);
}