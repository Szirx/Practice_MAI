#include "RemoteRound.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

RemoteRound::RemoteRound(int inX, int inY, int inWidth, int inHeight) : Remote(inX, inY, inWidth, inHeight) {

}

RemoteRound::~RemoteRound() {
}

void RemoteRound::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Ellipse(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);

	DeleteObject(Pen);
}

void RemoteRound::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Ellipse(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Ellipse(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);

	DeleteObject(Pen);

}