#include<windows.h>
#include "PlasmaTVScreenOff.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVScreenOff::PlasmaTVScreenOff(int inX, int inY, int inWidth, int inHeight):PlasmaTVonStand(inX, inY, inWidth, inHeight) {

}

PlasmaTVScreenOff::~PlasmaTVScreenOff() {

}

void PlasmaTVScreenOff::Show() {
	Visible = true;

	PlasmaTVonStand::Show();

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	MoveToEx(hdc, X - 145, Y - 20, NULL);
	LineTo(hdc, X + 145, Y - 20);
	MoveToEx(hdc, X - 125, Y - 10, NULL);
	LineTo(hdc, X + 125, Y - 10);
	MoveToEx(hdc, X - 105, Y, NULL);
	LineTo(hdc, X + 105, Y);
	MoveToEx(hdc, X - 85, Y + 10, NULL);
	LineTo(hdc, X + 85, Y + 10);
	MoveToEx(hdc, X - 65, Y + 20, NULL);
	LineTo(hdc, X + 65, Y + 20);

	DeleteObject(Pen);
}

void PlasmaTVScreenOff::Hide() {
	Visible = false;

	PlasmaTVonStand::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	MoveToEx(hdc, X - 145, Y - 20, NULL);
	LineTo(hdc, X + 145, Y - 20);
	MoveToEx(hdc, X - 125, Y - 10, NULL);
	LineTo(hdc, X + 125, Y - 10);
	MoveToEx(hdc, X - 105, Y, NULL);
	LineTo(hdc, X + 105, Y);
	MoveToEx(hdc, X - 85, Y + 10, NULL);
	LineTo(hdc, X + 85, Y + 10); 
	MoveToEx(hdc, X - 65, Y + 20, NULL);
	LineTo(hdc, X + 65, Y + 20);

	DeleteObject(Pen);
}