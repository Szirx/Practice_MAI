#include "ITV.h"
#include<windows.h>

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

ITV::ITV(int inX, int inY, int inWidth, int inHeight) :Point(inX, inY) {

}
