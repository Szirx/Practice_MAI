#include "RemoteNew.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

RemoteNew::RemoteNew(int inX, int inY, int inWidth, int inHeight) : Remote(inX, inY, inWidth, inHeight) {
	
}

RemoteNew::~RemoteNew() {
}

void RemoteNew::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	//Rectangle(hdc, X - width / 2 - 15, Y - height / 2 - 15, X + width / 2 + 15, Y + height / 2 + 15);
	Rectangle(hdc, X - width / 2 + 3, Y - height / 2 + 3, X + width / 2 - 3, Y + height / 2 - 3);
	Ellipse(hdc, X - 13, Y - 32, X + 13, Y - 12);
	Ellipse(hdc, X - 13, Y - 12, X + 13, Y + 8);
	Ellipse(hdc, X - 13, Y + 8, X + 13, Y + 28);

	DeleteObject(Pen);
}

void RemoteNew::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	//Rectangle(hdc, X - width / 2 - 15, Y - height / 2 - 15, X + width / 2 + 15, Y + height / 2 + 15);
	Ellipse(hdc, X - 13, Y - 32, X + 13, Y - 12);
	Ellipse(hdc, X - 13, Y - 12, X + 13, Y + 8);
	Ellipse(hdc, X - 13, Y + 8, X + 13, Y + 28);

	DeleteObject(Pen);

}