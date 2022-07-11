#include <Windows.h>
#include "IceCreamTree.h"

IceCreamTree::IceCreamTree(int InitX1, int InitY1, int InitWidth, int InitHeight, int InitRadius):Body(InitX1, InitY1, InitWidth, InitHeight, InitRadius) {};

IceCreamTree::~IceCreamTree(void) {};

void IceCreamTree::Show(void)
{
	Body::Show();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 + 11 - 0.3 * Radius, Y1 + 28 - 0.3 * Radius, X1 + 103 + 0.3 * Radius, Y1 + 130 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 109 - 0.3 * Radius, Y1 + 28 - 0.3 * Radius, X1 - 17 + 0.3 * Radius, Y1 + 130 + 0.3 * Radius);//325 70
}

void IceCreamTree::Hide(void)
{
	Body::Hide();
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Ellipse(hdc, X1 + 11 - 0.3 * Radius, Y1 + 28 - 0.3 * Radius, X1 + 103 + 0.3 * Radius, Y1 + 130 + 0.3 * Radius);//325 70
	Ellipse(hdc, X1 - 109 - 0.3 * Radius, Y1 + 28 - 0.3 * Radius, X1 - 17 + 0.3 * Radius, Y1 + 130 + 0.3 * Radius);//325 70

}