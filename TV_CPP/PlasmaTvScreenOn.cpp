#include<windows.h>
#include "PlasmaTVScreenOn.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVScreenOn::PlasmaTVScreenOn(int inX, int inY, int inWidth, int inHeight) :PlasmaTVonStand(inX, inY, inWidth, inHeight) {
	
}

PlasmaTVScreenOn::~PlasmaTVScreenOn() {

}

void PlasmaTVScreenOn::Show() {
	Visible = true;

	PlasmaTVonStand::Show();

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	RoundRect(hdc, X - 45, Y - 30, X + 45, Y + 30, 10, 10);
	Ellipse(hdc, X - 35, Y - 30, X - 15, Y);
	Ellipse(hdc, X + 15, Y - 30, X + 35, Y);
	RoundRect(hdc, X - 10, Y + 5, X + 10, Y + 15, 5, 5);
	
	DeleteObject(Pen);
}

void PlasmaTVScreenOn::Hide() {
	Visible = false;

	PlasmaTVonStand::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	RoundRect(hdc, X - 45, Y - 30, X + 45, Y + 30, 10, 10);
	Ellipse(hdc, X - 35, Y - 30, X - 15, Y);
	Ellipse(hdc, X + 15, Y - 30, X + 35, Y);
	RoundRect(hdc, X - 10, Y + 5, X + 10, Y + 15, 5, 5);

	DeleteObject(Pen);
}