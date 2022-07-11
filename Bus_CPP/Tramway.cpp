#include <windows.h>
#include "Body.h"	//объявление классов
#include "Tramway.h"
extern HDC hdc;      // объявим  контекст устройства
const int RADIUS = 30;
const int WIDTH = 120;
const int HEIGTH = 290;

//конструктор
Tramway::Tramway(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Tramway::Tramway()

//деструктор
Tramway::~Tramway(void)  //формально пустое тело
{

}//end Tramway::~Tramway()

//вывод фигуры в консоль
void Tramway::Show(void)
{
	Visible = true;
	Body::Show(); //рисуем фигуру предка
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//рисуем дверь
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//рисуем колеса
	Ellipse(hdc, X1 + (50 - RADIUS), Y2 - RADIUS, X1 + (50 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (110 - RADIUS), Y2 - RADIUS, X1 + (110 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (330 - RADIUS), Y2 - RADIUS, X1 + (330 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (390 - RADIUS), Y2 - RADIUS, X1 + (390 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (610 - RADIUS), Y2 - RADIUS, X1 + (610 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (670 - RADIUS), Y2 - RADIUS, X1 + (670 + RADIUS), Y2 + RADIUS);
	//рисуем рога
	MoveToEx(hdc, X1 + 300, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Tramway::Show()

//удаление фигуры с консоли
void Tramway::Hide(void)
{
	Visible = false;
	Body::Hide(); //стираем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//стираем дверь
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//стираем колеса
	Ellipse(hdc, X1 + (50 - RADIUS), Y2 - RADIUS, X1 + (50 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (110 - RADIUS), Y2 - RADIUS, X1 + (110 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (330 - RADIUS), Y2 - RADIUS, X1 + (330 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (390 - RADIUS), Y2 - RADIUS, X1 + (390 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (610 - RADIUS), Y2 - RADIUS, X1 + (610 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (670 - RADIUS), Y2 - RADIUS, X1 + (670 + RADIUS), Y2 + RADIUS);
	//стираем рога
	MoveToEx(hdc, X1 + 300, Y1, NULL); //сделать текущими координаты x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Tramway::Hide()