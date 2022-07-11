#include "Remote.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

Remote::Remote(int inX, int inY, int inWidth, int inHeight):ABCFigure(inX, inY, inWidth, inHeight) {
	height = inHeight;
	width = inWidth;
}

Remote::~Remote() {
}

int Remote::GetWidth() const {
	return width;
}

int Remote::GetHeight() const {
	return height;
}

void Remote::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 3, Y - height / 2 + 3, X + width / 2 - 3, Y + height / 2 - 3);
	Ellipse(hdc, X - 10, Y - 32, X + 10, Y - 12);
	Ellipse(hdc, X - 10, Y - 12, X + 10, Y + 8);
	Rectangle(hdc, X - 8, Y + 10, X + 8, Y + 20);
	Rectangle(hdc, X - 8, Y + 20, X + 8, Y + 30);
	
	DeleteObject(Pen);
}

void Remote::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 3, Y - height / 2 + 3, X + width / 2 - 3, Y + height / 2 - 3);
	Ellipse(hdc, X - 10, Y - 32, X + 10, Y - 12);
	Ellipse(hdc, X - 10, Y - 12, X + 10, Y + 8);
	Rectangle(hdc, X - 8, Y + 10, X + 8, Y + 20);
	Rectangle(hdc, X - 8, Y + 20, X + 8, Y + 30);

	DeleteObject(Pen);
	
}