#include "RemoteExtra.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

RemoteExtra::RemoteExtra(int inX, int inY, int inWidth, int inHeight) : Remote(inX, inY, inWidth, inHeight) {

}

RemoteExtra::~RemoteExtra() {
}

void RemoteExtra::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Ellipse(hdc, X - width / 2 + 5 , Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	Rectangle(hdc, X - width / 2 + 10, Y - height / 2 + 10, X + width / 2 - 10, Y + height / 2 - 10);
	Rectangle(hdc, X - width / 2 + 15, Y - height / 2 + 15, X + width / 2 - 15, Y + height / 2 - 15);

	DeleteObject(Pen);
}

void RemoteExtra::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Ellipse(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	Rectangle(hdc, X - width / 2 + 10, Y - height / 2 + 10, X + width / 2 - 10, Y + height / 2 - 10);
	Rectangle(hdc, X - width / 2 + 15, Y - height / 2 + 15, X + width / 2 - 15, Y + height / 2 - 15);

	DeleteObject(Pen);

}