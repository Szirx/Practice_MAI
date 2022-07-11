#include <windows.h>
#include "BrokenNewBus.h"
#include "NewBus.h"
extern HDC hdc;      // объявим  контекст устройства
const int WIDTH = 120;

//конструктор
BrokenNewBus::BrokenNewBus(int InitX1, int InitY1) : NewBus(InitX1, InitY1)
{

}//end BrokenBus::BrokenBus()

//деструктор
BrokenNewBus::~BrokenNewBus(void)  //формально пустое тело
{

}//end BrokenBus::~BrokenBus()

//вывод фигуры в консоль
void BrokenNewBus::Show(void)
{
	Visible = true;
	NewBus::Show();	//рисуем фигуру предка
	//зададим цвет пера белый
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//сотрем колесо
	Ellipse(hdc, X2 - 155, Y2 - 55, X2 - 45, Y2 + 55);
	Ellipse(hdc, X2 - 145, Y2 - 45, X2 - 55, Y2 + 45);
	//сотрем фару
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	//зададим цвет пера черный
	HPEN Black = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Black);
	//нарисуем трещину на стекле
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//закроем пустоту от колеса
	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	DeleteObject(Black);
	DeleteObject(White);
}//end BrokenBus::Show()

//удаление фигуры с консоли
void BrokenNewBus::Hide(void)
{
	Visible = false;
	NewBus::Hide(); //стираем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//сотрем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);

	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	DeleteObject(Pen);
}//end BrokenBus::Hide()