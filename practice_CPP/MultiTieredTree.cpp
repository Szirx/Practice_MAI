#include <Windows.h>
#include "MultiTieredTree.h"

MultiTieredTree::MultiTieredTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius):Body(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {};

MultiTieredTree::~MultiTieredTree(void) {};

void MultiTieredTree::Show(void)
{
	Body::Show();
	HPEN Pen1 = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, Pen1);	//сделаем перо активным
	Ellipse(hdc, X1 + 11 - 0.3 * Radius, Y1 - 19 - 0.3 * Radius, X1 + 103 + 0.3 * Radius, Y1 + 69 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 109 - 0.3 * Radius, Y1 - 19 - 0.3 * Radius, X1 - 17 + 0.3 * Radius, Y1 + 69 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 95 - 0.3 * Radius, Y1 + 17 - 0.3 * Radius, X1 + 91 + 0.3 * Radius, Y1 + 134 + 0.3 * Radius);//325 70
	DeleteObject(Pen1);
}

void MultiTieredTree::Hide(void)
{
	Body::Hide();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 + 11 - 0.3 * Radius, Y1 - 19 - 0.3 * Radius, X1 + 103 + 0.3 * Radius, Y1 + 69 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 109 - 0.3 * Radius, Y1 - 19 - 0.3 * Radius, X1 - 17 + 0.3 * Radius, Y1 + 69 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 95 - 0.3 * Radius, Y1 + 17 - 0.3 * Radius, X1 + 91 + 0.3 * Radius, Y1 + 134 + 0.3 * Radius);//325 70
	DeleteObject(Pen);
}