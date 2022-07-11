#include<windows.h>
#include "Coordinates.h."

extern HDC hdc;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*-----------------------  Методы класса "Coordinates" ----------------------------------*/

//Coordinates::Coordinates(int inX, int inY) {
//	X = inX;
//	Y = inY;
//}
//
//Coordinates::~Coordinates() {
//
//}
//
//int Coordinates::GetX() const {
//	return X;
//}
//
//int Coordinates::GetY() const {
//	return Y;
//}