#include<windows.h>
#include "PLasmaTVExtra.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PLasmaTVExtra::PLasmaTVExtra(int inX, int inY, int inWidth, int inHeight) :PlasmaTVonStand(inX, inY, inWidth, inHeight) {

}

PLasmaTVExtra::~PLasmaTVExtra() {

}

void PLasmaTVExtra::Show() {
	Visible = true;

	PlasmaTVonStand::Show();

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	RoundRect(hdc, X - 75, Y - 50, X + 75, Y + 50, 10, 10);
	RoundRect(hdc, X - 65, Y - 40, X + 65, Y + 40, 10, 10);
	RoundRect(hdc, X - 50, Y - 30, X + 50, Y + 30, 10, 10);
	RoundRect(hdc, X - 35, Y - 20, X + 35, Y + 20, 10, 10);
	RoundRect(hdc, X - 15, Y - 5, X + 15, Y + 5, 10, 10);
	

	DeleteObject(Pen);
}

void PLasmaTVExtra::Hide() {
	Visible = false;

	PlasmaTVonStand::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	RoundRect(hdc, X - 75, Y - 50, X + 75, Y + 50, 10, 10);
	RoundRect(hdc, X - 65, Y - 40, X + 65, Y + 40, 10, 10);
	RoundRect(hdc, X - 50, Y - 30, X + 50, Y + 30, 10, 10);
	RoundRect(hdc, X - 35, Y - 20, X + 35, Y + 20, 10, 10);
	RoundRect(hdc, X - 15, Y - 5, X + 15, Y + 5, 10, 10);


	DeleteObject(Pen);
}