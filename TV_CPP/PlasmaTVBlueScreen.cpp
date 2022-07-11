#include<windows.h>
#include "PlasmaTVBlueScreen.h"
extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

PlasmaTVBlueScreen::PlasmaTVBlueScreen(int inX, int inY, int inWidth, int inHeight) :PlasmaTVonStand(inX, inY, inWidth, inHeight) {

}

PlasmaTVBlueScreen::~PlasmaTVBlueScreen() {

}

void PlasmaTVBlueScreen::Show() {
	Visible = true;

	PlasmaTVonStand::Show();

	HPEN Pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(hdc, Pen);

	RECT R;
	R.left = X - width / 2 + 5; //левый верхний угол
	R.top = Y - height / 2 + 5;
	R.right = X + width / 2 - 5; //правый нижний
	R.bottom = Y + height / 2 - 5;

	//(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	FillRect(hdc, &R, (HBRUSH)CreateSolidBrush(RGB(0, 0, 255)));

	DeleteObject(Pen);
}

void PlasmaTVBlueScreen::Hide() {
	Visible = false;

	PlasmaTVonStand::Hide();

	HPEN Pen = ::CreatePen(PS_SOLID, 4, RGB(245, 245, 245));
	SelectObject(hdc, Pen);

	RECT R;
	R.left = X - width / 2 + 5; //левый верхний угол
	R.top = Y - height / 2 + 5;
	R.right = X + width / 2 - 5; //правый нижний
	R.right = Y + height / 2 - 5;

	//(hdc, X - width / 2 + 5, Y - height / 2 + 5, X + width / 2 - 5, Y + height / 2 - 5);
	FillRect(hdc, &R, (HBRUSH)CreateSolidBrush(RGB(245, 245, 245)));

	DeleteObject(Pen);
}