#include<windows.h>
#include "PlasmaTVwLegs.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVwLegs::PlasmaTVwLegs(int inX, int inY, int inWidth, int inHeight):PlasmaTV(inX, inY, inWidth, inHeight) {
	
}

PlasmaTVwLegs::~PlasmaTVwLegs() {

}

void PlasmaTVwLegs::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	PlasmaTV::Show();

	Rectangle(hdc, X - 135, Y + 75, X - 125, Y + 95);
	Rectangle(hdc, X + 125, Y + 75, X + 135, Y + 95);
	Rectangle(hdc, X - 185, Y + 95, X + 185, Y + 105);

	DeleteObject(Pen);
}

void PlasmaTVwLegs::Hide() {
	Visible = false;

	PlasmaTV::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - 135, Y + 75, X - 125, Y + 95);
	Rectangle(hdc, X + 125, Y + 75, X + 135, Y + 95);
	Rectangle(hdc, X - 185, Y + 95, X + 185, Y + 105);

	DeleteObject(Pen);
}