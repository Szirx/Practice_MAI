#include <windows.h>
#include <math.h>
#include "Body.h"	//объявление классов
#include "Trolleybus.h"
extern HDC hdc;      // объявим  контекст устройства
const int BIGRADIUS = 55;
const int SMALLRADIUS = 45;
const int WIDTH = 120;
const int HEIGTH = 290;

//конструктор
Trolleybus::Trolleybus(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Trolleybus::Trolleybus()

//деструктор
Trolleybus::~Trolleybus(void)  //формально пустое тело
{

}//end Trolleybus::~Trolleybus()

//вывод фигуры в консоль
void Trolleybus::Show(void)
{
	//обновляем координаты
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	Body::Show(); //риусем фигуру предка
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//рисуем дверь
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//рисуем колеса
	Ellipse(hdc, X1 + (80 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (80 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (80 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (80 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	//рисуем рога
	MoveToEx(hdc, X1 + 670, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 570, Y1 - 120);
	MoveToEx(hdc, X1 + 610, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 510, Y1 - 120);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end Trolleybus::Show()

//удаление фигуры с консоли
void Trolleybus::Hide(void)
{
	//обновляем координаты
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	Body::Hide();	//стираем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//стираем дверь
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//стираем колеса
	Ellipse(hdc, X1 + (80 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (80 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (80 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (80 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	//стираем рога
	MoveToEx(hdc, X1 + 670, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 570, Y1 - 120);
	MoveToEx(hdc, X1 + 610, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 510, Y1 - 120);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}// end Trolleybus::Hide()