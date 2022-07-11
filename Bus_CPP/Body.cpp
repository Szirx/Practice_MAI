#include <windows.h>
#include "Body.h"
#include "AbsBody.h"
extern HDC hdc;      // объ€вим  контекст устройства
const int WIDTH = 120;
const int HEIGTH = 290;

//конструктор
Body::Body(int InitX1, int InitY1) : AbsBody(InitX1, InitY1)
{
	width = 720;
	heigth = 330;
	X2 = X1 + width;
	Y2 = Y1 + heigth;
}// end Body::Body()

//деструктор
Body::~Body(void)  //формально пустое тело
{

}//end Body::~Body()

//вывод фигуры в консоль
void Body::Show(void)
{
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//зададим цвет пера черный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Rectangle(hdc, X1, Y1, X2, Y2);
	//рисуем окна
	Rectangle(hdc, X1 + 20, Y1 + 20, X1 + (20 + WIDTH), Y1 + (20 + WIDTH));
	Rectangle(hdc, X1 + 300, Y1 + 20, X1 + (300 + WIDTH), Y1 + (20 + WIDTH));
	Rectangle(hdc, X1 + 580, Y1 + 20, X1 + (580 + WIDTH), Y1 + (20 + WIDTH));
	//рисуем дверь
	Rectangle(hdc, X1 + 440, Y1 + 20, X1 + (440 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 460, Y1 + 40, X1 + (420 + WIDTH), Y1 + WIDTH);
	//рисуем фары
	Ellipse(hdc, X1 + 10, Y1 + 200, X1 + 30, Y1 + 220);
	Ellipse(hdc, X1 + 10, Y1 + 230, X1 + 30, Y1 + 250);
	Ellipse(hdc, X1 + 10, Y1 + 260, X1 + 30, Y1 + 280);
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Body::Show()

//удаление фигуры с консоли
void Body::Hide(void)
{
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//зададим цвет пера белый
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	Rectangle(hdc, X1, Y1, X2, Y2);
	//стираем окна
	Rectangle(hdc, X1 + 20, Y1 + 20, X1 + (20 + WIDTH), Y1 + (20 + WIDTH));
	Rectangle(hdc, X1 + 300, Y1 + 20, X1 + (300 + WIDTH), Y1 + (20 + WIDTH));
	Rectangle(hdc, X1 + 580, Y1 + 20, X1 + (580 + WIDTH), Y1 + (20 + WIDTH));
	Rectangle(hdc, X1 + 440, Y1 + 20, X1 + (440 + WIDTH), Y1 + (20 + HEIGTH));
	//стираем дверь
	Rectangle(hdc, X1 + 440, Y1 + 20, X1 + (440 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 460, Y1 + 40, X1 + (420 + WIDTH), Y1 + WIDTH);
	//стираем фары
	Ellipse(hdc, X1 + 10, Y1 + 200, X1 + 30, Y1 + 220);
	Ellipse(hdc, X1 + 10, Y1 + 230, X1 + 30, Y1 + 250);
	Ellipse(hdc, X1 + 10, Y1 + 260, X1 + 30, Y1 + 280);
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	// ”ничтожим нами созданные объекты  
	DeleteObject(Pen);
}//end Body::Hide()

//получить длину фигуры
int Body::GetWidth()
{
	return width;
}//end Body::GetWidth()

//получить высоту фигуры
int Body::GetHeigth()
{
	return heigth;
}//end Body::GetHeigth()