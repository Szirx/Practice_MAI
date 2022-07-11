#include <windows.h>
#include "Body.h"
#include "Bus.h"
extern HDC hdc;      // объ€вим  контекст устройства
const int BIGRADIUS = 55;
const int SMALLRADIUS = 45;
const int WIDTH = 120;

//конструктор
Bus::Bus(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Bus::Bus()

//деструктор
Bus::~Bus(void)  //формально пустое тело
{

}//end Bus::~Bus()

//вывод фигуры в консоль
void Bus::Show(void)
{
	Visible = true;
	Body::Show();	//рисуем фигуру предка
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//рисуем окно
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + WIDTH));
	//рисуем колеса
	Ellipse(hdc, X1 + (140 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (140 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (140 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (140 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Bus::Show()

//удаление фигуры с консоли
void Bus::Hide(void)
{
	Visible = false;
	Body::Hide(); //стираем фигуру предка
	//зададим цвет пера белый
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//стираем окно
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + WIDTH));
	//стираем колеса
	Ellipse(hdc, X1 + (140 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (140 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (140 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (140 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	//уничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Bus::Hide()