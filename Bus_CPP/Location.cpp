#include<windows.h>
#include "Location.h"	//объявление классов
extern HDC hdc;      // объявим  контекст устройства

Location::Location(int InitX, int InitY)
{
	//инициализация закрытых переменных своего класса
	X1 = InitX;
	Y1 = InitY;
};//end Location::Location()

  //деструктор
Location::~Location(void)  //формально пустое тело
{
};//end Location::~Location()

  //получить X координату точки
int Location::GetX(void)
{
	return X1;
};//end Location::GetX()	

  //получить Y координату точки
int Location::GetY(void)
{
	return Y1;
}; //end Location::GetY()