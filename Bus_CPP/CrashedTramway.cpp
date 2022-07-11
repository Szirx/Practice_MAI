#include <windows.h>
#include "CrashedTramway.h"
#include "Tramway.h"
extern HDC hdc;      // объ€вим  контекст устройства
const int WIDTH = 120;


//конструктор
CrashedTramway::CrashedTramway(int InitX1, int InitY1) : Tramway(InitX1, InitY1)
{

}//end CrashedTramway::CrashedTramway()

//деструктор
CrashedTramway::~CrashedTramway(void)  //формально пустое тело
{

}//end CrashedTramway::~CrashedTramway()

//вывод фигуры в консоль
void CrashedTramway::Show(void)
{
	Visible = true;
	Tramway::Show();	//рисуем фигуру предка
	//зададим цвет пера черынй
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	//рисуем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL); //сделать текущими координаты x1, y1
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
	MoveToEx(hdc, X1 + 300, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	//удал€ем объекты
	DeleteObject(Pen);
	DeleteObject(Gray);
	DeleteObject(White);
}//end CrashedTramway::Show()

//удаление фигуры с консоли
void CrashedTramway::Hide(void)
{
	Visible = false;
	Tramway::Hide();	//стираем фигуру предка
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
	//удал€ем объект
	DeleteObject(Pen);
}//end CrashedTramway::Hide()