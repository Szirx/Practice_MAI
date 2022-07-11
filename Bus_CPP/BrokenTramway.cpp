#include <windows.h>
#include "BrokenTramway.h"
#include "Tramway.h"
extern HDC hdc;      //объ€вим контекст устройства
const int WIDTH = 120;

//конструктор
BrokenTramway::BrokenTramway(int InitX1, int InitY1) : Tramway(InitX1, InitY1)
{

}//end BrokenTramway::BrokenTramway()

//деструктор
BrokenTramway::~BrokenTramway(void)  //формально пустое тело
{

}//end BrokenTramway::~BrokenTramway()

//вывод фигуры в консоль
void BrokenTramway::Show(void)
{
	Visible = true;
	Tramway::Show();	//рисуем фигуру предка
	//зададим цвет пера белый
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//сотрем фару
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	//сотрем колеса
	Ellipse(hdc, X1 + 640, Y2 - 30, X1 + 700, Y2 + 30);
	Ellipse(hdc, X1 + 300, Y2 - 30, X1 + 360, Y2 + 30);
	//зададим цвет пера черный
	HPEN Black = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Black);
	//нарисуем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//закроем пустоты от колес
	MoveToEx(hdc, X1 + 640, Y2, NULL);
	LineTo(hdc, X1 + 700, Y2);
	MoveToEx(hdc, X1 + 360, Y2, NULL);
	LineTo(hdc, X1 + 300, Y2);
	//удалим объекты
	DeleteObject(Black);
	DeleteObject(White);
}//end BrokenTramway::Show()

//удаление фигуры с консоли
void BrokenTramway::Hide(void)
{
	Visible = false;
	Tramway::Hide();	//стираем фигуру предка
	//зададим цвет пера белый 
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//сотрем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);

	MoveToEx(hdc, X1 + 640, Y2, NULL);
	LineTo(hdc, X1 + 700, Y2);
	MoveToEx(hdc, X1 + 360, Y2, NULL);
	LineTo(hdc, X1 + 300, Y2);
	//удалим объект
	DeleteObject(Pen);
}//end BrokenTramway::Hide()