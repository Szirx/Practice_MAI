#include <windows.h>
#include "Body.h"
#include "NewBus.h"
extern HDC hdc;      // объявим  контекст устройства
const int BIGRADIUS = 55;
const int SMALLRADIUS = 45;
const int WIDTH = 120;

//конструктор
NewBus::NewBus(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Bus::Bus()

//деструктор
NewBus::~NewBus(void)  //формально пустое тело
{

}//end Bus::~Bus()

//вывод фигуры в консоль
void NewBus::Show(void)
{
	Visible = true;
	Body::Show();	//рисуем фигуру предка
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);	//сделаем перо активным
	Rectangle(hdc, X1 + 300, Y1 + 20, X1 + (300 + WIDTH), Y1 + (20 + WIDTH));
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

	Rectangle(hdc, X1 + 300, Y1, X1 + (300 + WIDTH), Y2);
	Rectangle(hdc, X1 + 320, Y1, X1 + (300 + WIDTH - 20), Y2);
	Rectangle(hdc, X1 + 330, Y1, X1 + (300 + WIDTH - 30), Y2);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
	DeleteObject(White);
}//end Bus::Show()

//удаление фигуры с консоли
void NewBus::Hide(void)
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
	Rectangle(hdc, X1 + 300, Y1, X1 + (300 + WIDTH), Y2);
	Rectangle(hdc, X1 + 320, Y1, X1 + (300 + WIDTH - 20), Y2);
	Rectangle(hdc, X1 + 330, Y1, X1 + (300 + WIDTH - 30), Y2);
	//уничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Bus::Hide()