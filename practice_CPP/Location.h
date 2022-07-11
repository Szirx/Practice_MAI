#pragma once
#include <iostream>
#include <Windows.h>

extern HDC hdc;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class Location
{
protected:		//предоставляет возможность потомкам (производному 
				//классу) иметь доступ к частным данным
	int X1;		//координата X
	int Y1;		//координата Y

public:   //эти методы доступны извне всем в программе

	Location(int InitX1, int InitY1); //конструктор
	~Location();                    //деструктор
	int GetX1();						//получить X координату точки
	int GetY1();						//получить Y координату точки
};//end class Location