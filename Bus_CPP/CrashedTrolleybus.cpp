#include <windows.h>
#include "CrashedTrolleybus.h"
#include "Trolleybus.h"
extern HDC hdc;      // объявим  контекст устройства
const int WIDTH = 120;

//конструктор
CrashedTrolleybus::CrashedTrolleybus(int InitX1, int InitY1) : Trolleybus(InitX1, InitY1)
{

}//end CrashedTrolleybus::CrashedTrolleybus()

//деструктор
CrashedTrolleybus::~CrashedTrolleybus(void)  //формально пустое тело
{

}//end CrashedTrolleybus::~CrashedTrolleybus()

//вывод фигуры в консоль
void CrashedTrolleybus::Show(void)
{
	Visible = true;
	Trolleybus::Show();	//рисуем фигуру предка
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	//рисуем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//зададим цвет пера серый
	HPEN Gray = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
	SelectObject(hdc, Gray);
	//рисуем дым
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//зададим цвет пера белый
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//стираем рога
	MoveToEx(hdc, X1 + 670, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 570, Y1 - 120);
	//удаляем объекты
	DeleteObject(Pen);
	DeleteObject(Gray);
	DeleteObject(White);
}//end CrashedTrolleybus::Show()

//удаление фигуры с консоли
void CrashedTrolleybus::Hide(void)
{
	Visible = false;
	Trolleybus::Hide();	//стираем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//стираем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//стираем дым
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//удаляем объект
	DeleteObject(Pen);
}//end CrashedTrolleybus::Hide()