#include <windows.h>
#include <math.h>
#include <iostream>
#include "Point.h"	//объ€вление классов
#include "Lamppost.h"
extern HDC hdc;      // объ€вим  контекст устройства
const double STEP = 0.2;

// ћакрос дл€ проверки состо€ни€ клавиатуры Ц из ЎјЅЋќЌј
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//конструктор
Lamppost::Lamppost(int InitX1, int InitY1) : Point(InitX1, InitY1)
{

}//end Lamppost::Lamppost()

//деструктор
Lamppost::~Lamppost(void)  //формально пустое тело
{

}//end Lamppost::~Lamppost()

//вывод фигуры в консоль
void Lamppost::Show()
{

}

//удаление фигуры с консоли
void Lamppost::Hide()
{

}

//увеличение фигуры
void Lamppost::UpScale()
{

}

//уменьшение фигуры
void Lamppost::DownScale()
{

}