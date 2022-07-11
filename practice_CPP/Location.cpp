#include <Windows.h>
#include "Location.h"
/*-----------------------------------------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/
//конструктор
Location::Location(int InitX1, int InitY1)
{
	//инициализация закрытых переменных своего класса
	X1 = InitX1;
	Y1 = InitY1;
};//end Location::Location()

  //деструктор
Location::~Location(void)  //формально пустое тело
{
};//end Location::~Location()

  //получить X координату точки
int Location::GetX1(void)
{
	return X1;
};//end Location::GetX()	

  //получить Y координату точки
int Location::GetY1(void)
{
	return Y1;
}; //end Location::GetY()