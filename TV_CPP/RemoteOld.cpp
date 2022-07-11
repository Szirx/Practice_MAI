#include "RemoteOld.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

RemoteOld::RemoteOld(int inX, int inY, int inWidth, int inHeight) : Remote(inX, inY, inWidth, inHeight) {

}

RemoteOld::~RemoteOld() {
}

void RemoteOld::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	Ellipse(hdc, X - 8, Y - 30, X + 8, Y - 12);
	
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 30, X + width / 2 - 5, Y + height / 2 - 30);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 40, X + width / 2 - 5, Y + height / 2 - 20);

	DeleteObject(Pen);
}

void RemoteOld::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	Ellipse(hdc, X - 8, Y - 30, X + 8, Y - 12);

	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 30, X + width / 2 - 5, Y + height / 2 - 30);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 40, X + width / 2 - 5, Y + height / 2 - 20);

	DeleteObject(Pen);

}