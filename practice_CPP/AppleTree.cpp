#include <Windows.h>
#include "AppleTree.h"

AppleTree::AppleTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius) :MultiTieredTree(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {};

AppleTree::~AppleTree(void) {};

void AppleTree::Show(void)
{
	MultiTieredTree::Show();
	HPEN Pen2 = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, Pen2);
	Ellipse(hdc, X1 - 65 - 0.08 * Radius, Y1 + 60 - 0.08 * Radius, X1 - 25 + 0.08 * Radius, Y1 + 100 + 0.08 * Radius);
	Ellipse(hdc, X1 - 30 - 0.08 * Radius, Y1 + 100 - 0.08 * Radius, X1 + 10 + 0.08 * Radius, Y1 + 140 + 0.08 * Radius);
	Ellipse(hdc, X1 + 60 - 0.08 * Radius, Y1 + 70 - 0.08 * Radius, X1 + 100 + 0.08 * Radius, Y1 + 110 + 0.08 * Radius);
	Ellipse(hdc, X1 - 115 - 0.08 * Radius, Y1 + 70 - 0.08 * Radius, X1 - 75 + 0.08 * Radius, Y1 + 110 + 0.08 * Radius);

}

void AppleTree::Hide(void)
{
	MultiTieredTree::Hide();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 - 65 - 0.08 * Radius, Y1 + 60 - 0.08 * Radius, X1 - 25 + 0.08 * Radius, Y1 + 100 + 0.08 * Radius);
	Ellipse(hdc, X1 - 30 - 0.08 * Radius, Y1 + 100 - 0.08 * Radius, X1 + 10 + 0.08 * Radius, Y1 + 140 + 0.08 * Radius);
	Ellipse(hdc, X1 + 60 - 0.08 * Radius, Y1 + 70 - 0.08 * Radius, X1 + 100 + 0.08 * Radius, Y1 + 110 + 0.08 * Radius);
	Ellipse(hdc, X1 - 115 - 0.08 * Radius, Y1 + 70 - 0.08 * Radius, X1 - 75 + 0.08 * Radius, Y1 + 110 + 0.08 * Radius);
}