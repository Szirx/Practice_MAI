#include <Windows.h>
#include "TreeWithBranch.h"

TreeWithBranch::TreeWithBranch(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius):Body(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {};

TreeWithBranch::~TreeWithBranch(void) {};

void TreeWithBranch::Show(void)
{
	Body::Show();
	HPEN Pen1 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 5, RGB(150, 75, 0));
	SelectObject(hdc, Pen2);	//сделаем перо активным
	MoveToEx(hdc, X1 - 12, Y1 + 135, NULL);
	LineTo(hdc, X1 - 50, Y1 + 84);
	MoveToEx(hdc, X1 + 12, Y1 + 149, NULL);
	LineTo(hdc, X1 + 39, Y1 + 115);
	SelectObject(hdc, Pen1);
	Ellipse(hdc, X1 - 38 - 1.6 * Radius, Y1 + 95 - 1.6 * Radius, X1 - 117 + 1.6 * Radius, Y1 + 25 + 1.6 * Radius);//325 70
	Ellipse(hdc, X1 + 47 - 0.3 * Radius, Y1 + 65 - 0.3 * Radius, X1 + 107 + 0.3 * Radius, Y1 + 122 + 0.3 * Radius);//325 70
}

void TreeWithBranch::Hide(void)
{
	Body::Hide();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	MoveToEx(hdc, X1 - 12, Y1 + 135, NULL);
	LineTo(hdc, X1 - 50, Y1 + 84);
	MoveToEx(hdc, X1 + 12, Y1 + 149, NULL);
	LineTo(hdc, X1 + 39, Y1 + 115);
	Ellipse(hdc, X1 - 38 - 1.6 * Radius, Y1 + 95 - 1.6 * Radius, X1 - 117 + 1.6 * Radius, Y1 + 25 + 1.6 * Radius);//325 70
	Ellipse(hdc, X1 + 47 - 0.3 * Radius, Y1 + 65 - 0.3 * Radius, X1 + 107 + 0.3 * Radius, Y1 + 122 + 0.3 * Radius);//325 70

}