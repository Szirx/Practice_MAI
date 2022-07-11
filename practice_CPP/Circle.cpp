#include <Windows.h>
#include "Circle.h"

/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Circle            */
/*----------------------------------------*/
//для инициализации закрытых полей используем конструктор предка
Circle::Circle(int InitX1, int InitY1, int InitRadius) :Point(InitX1, InitY1)
{
	//инициализация закрытых переменных своего класса
	Radius = InitRadius;
}//end Circle::Circle ()

//-------------------------------------------------------------------
Circle::~Circle(void)  //формально пустое тело
{
};//end Circle::~Circle ()

//-------------------------------------------------------------------
void Circle::Show(void)
{

	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X1 - Radius, Y1 - Radius, X1 + Radius, Y1 + Radius);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);

} // end Circle::Show()

//-------------------------------------------------------------------
void Circle::Hide(void)
{

	// Зададим перо и цвет пера``
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //синий
	//	HPEN Pen=::CreatePen(PS_SOLID,2,RGB(255,255,255));
	SelectObject(hdc, Pen);

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X1 - Radius, Y1 - Radius, X1 + Radius, Y1 + Radius);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);

}// end Circle::Hide()

//-------------------------------------------------------------------
/* можно  УБРАТЬ благодаря виртуальным функциям    !!
void Circle::MoveTo(int NewX, int NewY)  //берем из Point
{
	Hide();  //стирание старой окружности
	X= NewX; //поменять координаты
	Y= NewY;
	Show();  //показать окружность на новом месте
}//end Circle::MoveTo()
*/
//-------------------------------------------------------------------
void Circle::Expand(int DeltaRad)
{
	Hide();             //спрятать окружность со старым радиусом
	Radius += DeltaRad; //изменить радиус 
	if (Radius < 0)     //для отрицательного приращения радиуса
		Radius = 5;
	Show();             //показать окружность с новым радиусом
}//end Circle::Expand ()

//---------------------------------------------------------------
void Circle::Reduce(int DeltaRad)
{
	Expand(-DeltaRad); //отрицательное приращение радиуса
}//end Circle::Reduce ()

//void Circle::Narrow(int DeltaRad, int Choice)
//{
//	Expand(-Delta)
//}
