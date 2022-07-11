#include <windows.h>
#include <iostream>
#include "iTrash.h"	//объ€вление классов
#include "Trash.h"
extern HDC hdc;      // объ€вим  контекст устройства

//конструктор
Trash::Trash(int InitX1, int InitY1) : iTrash(InitX1, InitY1)
{

}//end Trash::Trash()

//деструктор
Trash::~Trash(void)  //формально пустое тело
{

}//end Trash::~Trash()

//вывод фигуры в консоль
void Trash::Show(void)
{
	//обновл€ем координаты
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 - 10, Y1 - 10, X2 + 10, Y1);
	MoveToEx(hdc, X1 + 15, Y1 - 10, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 15, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 10);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end Trash::Show()

//удаление фигуры с консоли
void Trash::Hide(void)
{
	//обновим координаты
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//зададим цвет пера белый
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 - 10, Y1 - 10, X2 + 10, Y1);
	MoveToEx(hdc, X1 + 15, Y1 - 10, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 15, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 10);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end Trash::Hide()

//получить длину фигуры
int Trash::GetWidth()
{
	return width;
}//end Trash::GetWidth()

//получить высоту фигуры
int Trash::GetHeigth()
{
	return heigth;
}//end Trash::GetHeigth()