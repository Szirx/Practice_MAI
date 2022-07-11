#include<windows.h>
#include "PlasmaTVonStand.h"


extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVonStand::PlasmaTVonStand(int inX, int inY, int inWidth, int inHeight):PlasmaTVwLegs(inX, inY, inWidth, inHeight) {

}

PlasmaTVonStand::~PlasmaTVonStand() {

}

void PlasmaTVonStand::Show() {
	Visible = true;

	PlasmaTVwLegs::Show();

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - 190, Y + 105, X + 190, Y + 155);
	Rectangle(hdc, X - 110, Y + 130, X + 110, Y + 140);

	Rectangle(hdc, X - 190, Y + 155, X + 190, Y + 205);
	Rectangle(hdc, X - 110, Y + 180, X + 110, Y + 190);

	Rectangle(hdc, X - 190, Y + 205, X + 190, Y + 255);
	Rectangle(hdc, X - 110, Y + 230, X + 110, Y + 240);
	
	DeleteObject(Pen);
}

void PlasmaTVonStand::Hide() {
	Visible = false;

	PlasmaTVwLegs::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - 190, Y + 105, X + 190, Y + 155);
	Rectangle(hdc, X - 110, Y + 130, X + 110, Y + 140);

	Rectangle(hdc, X - 190, Y + 155, X + 190, Y + 205);
	Rectangle(hdc, X - 110, Y + 180, X + 110, Y + 190);

	Rectangle(hdc, X - 190, Y + 205, X + 190, Y + 255);
	Rectangle(hdc, X - 110, Y + 230, X + 110, Y + 240);

	DeleteObject(Pen);
}