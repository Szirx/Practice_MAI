#include <windows.h>
#include "CrashedNewBus.h"
#include "NewBus.h"
extern HDC hdc;      // объ€вим  контекст устройства
const int WIDTH = 120;

//конструктор
CrashedNewBus::CrashedNewBus(int InitX1, int InitY1) : NewBus(InitX1, InitY1)
{

}//end CrashedBus::CrashedBus()

//деструктор
CrashedNewBus::~CrashedNewBus(void)  //формально пустое тело
{

}//end CrashedBus::~CrashedBus()

//вывод фигуры в консоль
void CrashedNewBus::Show(void)
{
	Visible = true;
	NewBus::Show();	//рисуем фигуру предка
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
	//удал€ем объекты
	DeleteObject(Pen);
	DeleteObject(Gray);
}//end CrashedBus::Show()

//удаление фигуры с консоли
void CrashedNewBus::Hide(void)
{
	Visible = false;
	NewBus::Hide();	//сотрем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//стираем трещину
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//стираем дым
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//удал€ем объект
	DeleteObject(Pen);
}//end CrashedBus::Hide()