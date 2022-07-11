#include <windows.h>
#include "NewTrash.h"	//объ€вление классов
#include "Trash.h"
extern HDC hdc;      //объ€вим контекст устройства

//конструктор
NewTrash::NewTrash(int InitX1, int InitY1) : Trash(InitX1, InitY1)
{
	width = 200;
	heigth = 100;
}//end BigTrash::BigTrash()

//деструктор
NewTrash::~NewTrash(void)  //формально пустое тело
{

}//end BigTrash::~BigTrash()

//вывод фигуры в консоль
void NewTrash::Show(void)
{
	//обновим координаты второй точки
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//нарисуем фигуру
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y1);
	LineTo(hdc, X2 - 20, Y2);
	LineTo(hdc, X1 + 20, Y2);
	LineTo(hdc, X1, Y1);
	LineTo(hdc, X2 - 20, Y2);
	MoveToEx(hdc, X2, Y1, NULL);
	LineTo(hdc, X1 + 20, Y2);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end BigTrash::Show()

//удаление фигуры с консоли
void NewTrash::Hide(void)
{
	//обновим координаты второй точки
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//зададим цвет пера белый
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//сотрем фигуру
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y1);
	LineTo(hdc, X2 - 20, Y2);
	LineTo(hdc, X1 + 20, Y2);
	LineTo(hdc, X1, Y1);
	LineTo(hdc, X2 - 20, Y2);
	MoveToEx(hdc, X2, Y1, NULL);
	LineTo(hdc, X1 + 20, Y2);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end BigTrash::Hide()