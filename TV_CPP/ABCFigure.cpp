#include "ABCFigure.h"
#include<windows.h>
#include "Coordinates.h."
#include "Point.h"

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

ABCFigure::ABCFigure(int inX, int inY, int inWidth, int inHeight) :Point(inX, inY) {
	height = inHeight;
	width = inWidth;
}
