#include<windows.h>
#include "Coordinates.h."
#include "Point.h"
#include "PlasmaTV.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTV::PlasmaTV(int inX, int inY, int inWidth, int inHeight):ITV(inX, inY, inWidth, inHeight) {
	height = inHeight;
	width = inWidth;
}


PlasmaTV::~PlasmaTV() {

}

int PlasmaTV::GetWidth() const {
	return width;
}

int PlasmaTV::GetHeight() const {
	return height;
}

void PlasmaTV::Show() {
	Visible = true;

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5 , Y + height / 2 - 5);

	DeleteObject(Pen);
}

void PlasmaTV::Hide() {
	Visible = false;

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	Rectangle(hdc, X - width / 2, Y - height / 2, X + width / 2, Y + height / 2);
	Rectangle(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);

	DeleteObject(Pen);
}



