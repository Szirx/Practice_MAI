#include <windows.h>
#include "BigTrash.h"	//объ€вление классов
#include "Trash.h"
extern HDC hdc;      //объ€вим контекст устройства

//конструктор
BigTrash::BigTrash(int InitX1, int InitY1) : Trash(InitX1, InitY1)
{
	width = 200;
	heigth = 100;
}//end BigTrash::BigTrash()

//деструктор
BigTrash::~BigTrash(void)  //формально пустое тело
{

}//end BigTrash::~BigTrash()

//вывод фигуры в консоль
void BigTrash::Show(void)
{
	//обновим координаты второй точки
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//нарисуем фигуру
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 + 20, Y1 + 20, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X1 + 20, Y1 + 20, NULL);
	LineTo(hdc, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X2 - 20, Y1 + 20, NULL);
	LineTo(hdc, X1 + 20, Y2 - 20);
	Ellipse(hdc, X1, Y2, X1 + 10 , Y2 + 10);
	Ellipse(hdc, X2 - 10, Y2, X2, Y2 + 10);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end BigTrash::Show()

//удаление фигуры с консоли
void BigTrash::Hide(void)
{
	//обновим координаты второй точки
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//зададим цвет пера белый
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//сотрем фигуру
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 + 20, Y1 + 20, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X1 + 20, Y1 + 20, NULL);
	LineTo(hdc, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X2 - 20, Y1 + 20, NULL);
	LineTo(hdc, X1 + 20, Y2 - 20);
	Ellipse(hdc, X1, Y2, X1 + 10, Y2 + 10);
	Ellipse(hdc, X2 - 10, Y2, X2, Y2 + 10);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end BigTrash::Hide()