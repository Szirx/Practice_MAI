#include<windows.h>
#include "Point.h"	//объявление классов
#include "Location.h"
extern HDC hdc;      // объявим  контекст устройства

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	//инициализация закрытых переменных своего класса
	Visible = false;
}//end Point::Point()

 //--------------------------------------------------------------
 //деструктор
Point::~Point(void)   //формально пустое тело
{
}//end Point::~Point()

 //--------------------------------------------------------------
 //показать ТОЧКУ
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X1, Y1, RGB(0, 0, 0));	//рисуем красным цветом
	SetPixel(hdc, X1 + 1, Y1, RGB(0, 0, 0));	// 4 точки для удобства
	SetPixel(hdc, X1, Y1 + 1, RGB(0, 0, 0));
	SetPixel(hdc, X1 + 1, Y1 + 1, RGB(0, 0, 0));
}//end Point::Show()

 //--------------------------------------------------------------
 //скрыть ТОЧКУ
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X1, Y1, RGB(255, 255, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X1 + 1, Y1, RGB(255, 255, 255));
	SetPixel(hdc, X1, Y1 + 1, RGB(255, 255, 255));
	SetPixel(hdc, X1 + 1, Y1 + 1, RGB(255, 255, 255));
}//end Point::Hide()

 //--------------------------------------------------------------
 //узнать про светимость ТОЧКИ
bool Point::IsVisible(void)
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------
//переместить ТОЧКУ
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X1 = NewX;	//поменять координаты ТОЧКИ
	Y1 = NewY;
	Show();		//показать точку на новом месте
};//end Point::MoveTo()

  //-------------------------------------------------------------------
void Point::Drag(int Step)    //буксировка фигуры
{
	int FigX, FigY;   //новые координаты фигуры

	FigX = GetX();    //получаем начальное положение фигуры
	FigY = GetY();
	//направление движения объекта

	if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if

	if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if
	
	if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if

	if (KEY_DOWN(VK_UP)) //стрелка вверх  38
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if
}//end Drag()