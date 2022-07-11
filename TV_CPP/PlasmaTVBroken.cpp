#include "PlasmaTVBroken.h"
#include<windows.h>
extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVBroken::PlasmaTVBroken(int inX, int inY, int inWidth, int inHeight) :PlasmaTVonStand(inX, inY, inWidth, inHeight) {

}

PlasmaTVBroken::~PlasmaTVBroken() {

}

void PlasmaTVBroken::Show() {
	Visible = true;

	PlasmaTVonStand::Show();

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);
	///////////////////
	MoveToEx(hdc, X - 100, Y - height/2 + 5, NULL);
	LineTo(hdc, X - 115, Y - height / 2 + 30);

	MoveToEx(hdc, X - 115, Y - height / 2 + 30, NULL);
	LineTo(hdc, X - 90, Y - height / 2 + 30);
	
	MoveToEx(hdc, X - 90, Y - height / 2 + 30, NULL);
	LineTo(hdc, X - 100, Y - height / 2 + 60);
	Sleep(500);
	///////////////////
	MoveToEx(hdc, X + 100, Y - height/2 + 5, NULL);
	LineTo(hdc, X + 115, Y - height / 2 + 30);

	MoveToEx(hdc, X + 115, Y - height / 2 + 30, NULL);
	LineTo(hdc, X + 90, Y - height / 2 + 30);
	
	MoveToEx(hdc, X + 90, Y - height / 2 + 30, NULL);
	LineTo(hdc, X + 100, Y - height / 2 + 60);
	Sleep(500);
	///////////////////
	MoveToEx(hdc, X , Y + height / 2 - 5, NULL);
	LineTo(hdc, X - 15, Y + height / 2 - 30);

	MoveToEx(hdc, X - 15, Y + height / 2 - 30, NULL);
	LineTo(hdc, X + 15, Y + height / 2 - 30);

	MoveToEx(hdc, X + 15, Y + height / 2 - 30, NULL);
	LineTo(hdc, X , Y + height / 2 - 60);
	Sleep(500);

	PlasmaTVBroken::Hide();



	///////////////////
	DeleteObject(Pen);
}

void PlasmaTVBroken::Hide() {
	Visible = false;

	PlasmaTVonStand::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	MoveToEx(hdc, X - 100, Y - height / 2 + 5, NULL);
	LineTo(hdc, X - 115, Y - height / 2 + 30);

	MoveToEx(hdc, X - 115, Y - height / 2 + 30, NULL);
	LineTo(hdc, X - 90, Y - height / 2 + 30);

	MoveToEx(hdc, X - 90, Y - height / 2 + 30, NULL);
	LineTo(hdc, X - 100, Y - height / 2 + 60);
	///////////////////
	MoveToEx(hdc, X + 100, Y - height / 2 + 5, NULL);
	LineTo(hdc, X + 115, Y - height / 2 + 30);

	MoveToEx(hdc, X + 115, Y - height / 2 + 30, NULL);
	LineTo(hdc, X + 90, Y - height / 2 + 30);

	MoveToEx(hdc, X + 90, Y - height / 2 + 30, NULL);
	LineTo(hdc, X + 100, Y - height / 2 + 60);
	///////////////////
	MoveToEx(hdc, X, Y + height / 2 - 5, NULL);
	LineTo(hdc, X - 15, Y + height / 2 - 30);

	MoveToEx(hdc, X - 15, Y + height / 2 - 30, NULL);
	LineTo(hdc, X + 15, Y + height / 2 - 30);

	MoveToEx(hdc, X + 15, Y + height / 2 - 30, NULL);
	LineTo(hdc, X, Y + height / 2 - 60);

	DeleteObject(Pen);
}