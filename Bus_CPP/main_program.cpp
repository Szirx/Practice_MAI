/***---------------------------------------****
****--------------- урс ќќѕ----------------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : main_program.CPP             *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.			      *
* Modified By  : Zhbanov I.A.                 *
* Created      : 01/04/2022                   *
* Last Revision: 18/05/2022                   *
* --------------------------------------------*/

#pragma once                  
#include <windows.h>
#include <iostream>
#include "Body.h"
#include "Bus.h"
#include "CrashedBus.h"
#include "BrokenBus.h"
#include "Tramway.h"
#include "CrashedTramway.h"
#include "BrokenTramway.h"
#include "Trolleybus.h"
#include "CrashedTrolleybus.h"
#include "BrokenTrolleybus.h"
#include "Trash.h"
#include "NewTrash.h"
#include "BigTrash.h"
#include "NewBus.h"
#include "CrashedNewBus.h"
#include "BrokenNewBus.h"
#include "GetConlWin.h"		//указатель на консольное окно

//макрос дл€ определени€ кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;	// ќбъ€вим контекст устройства

bool IsCollision(AbsBody* transport, iTrash* trash)
{
	bool collisionX = true; //коллизи€ по X
	bool collisionY = true; //коллизи€ по Y

	int transportCoordinates[4];	//координаты транспорта
	transportCoordinates[0] = transport->GetX();							//координата X1
	transportCoordinates[1] = transport->GetX() + transport->GetWidth();	//координата X2
	transportCoordinates[2] = transport->GetY();							//координата Y1
	transportCoordinates[3] = transport->GetY() + transport->GetHeigth();	//координата Y2

	int trashCoordinates[2];	//координаты преп€тстви€
	trashCoordinates[0] = trash->GetX() + trash->GetWidth() / 2;	//координата ’ центра преп€тстви€
	trashCoordinates[1] = trash->GetY() + trash->GetHeigth() / 2;	//координата Y центра преп€тстви€
	
	//проверка отсутстви€ коллизии по координате X
	if (trashCoordinates[0] > transportCoordinates[1] || trashCoordinates[0] < transportCoordinates[0]) collisionX = false;
	//проверка отсутстви€ коллизии по координате Y
	if (trashCoordinates[1] > transportCoordinates[3] || trashCoordinates[1] < transportCoordinates[2]) collisionX = false;

	if (collisionX && collisionY)	//если произошла коллизи€ по обеим ос€м
	{
		return true;
	}
	return false;
}//end bool IsCollision

int main()
{
	//объ€вление и инициализаци€ переменных
	int x0 = 50, y0 = 270;		//стартовые координаты дл€ транспорта
	int x01 = 1100, y01 = 350;		//стартовые координаты дл€ преп€тстви€
	int xNew = 0, yNew = 0;		//координаты после столкновени€
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства дл€ консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{

			Bus bus(x0, y0);		//автобус
			NewBus newbus(x0, y0);
			Trolleybus trolleybus(x0, y0);	//троллейбус
			Tramway tramway(x0, y0);	//трамвай
			
			//объекты после столкновени€
			CrashedBus crashedbus(x0, y0);
			BrokenBus brokenbus(x0, y0);
			CrashedTramway crashedtramway(x0, y0);
			BrokenTramway brokentramway(x0, y0);
			CrashedTrolleybus crashedtrolleybus(x0, y0);
			BrokenTrolleybus brokentrolleybus(x0, y0);
			CrashedNewBus crashednewbus(x0, y0);
			BrokenNewBus brokennewbus(x0, y0);

			//объекты преп€тстви€
			Trash trash(x01, y01);
			BigTrash bigtrash(x01, y01);
			NewTrash newtrash(x01, y01);

			//массив указателей на объекты преп€тстви€
			iTrash* trashes[3];
			trashes[0] = &trash;
			trashes[1] = &bigtrash;
			trashes[2] = &newtrash;

			//массив указателей на объекты транспорта
			AbsBody* transport[12];
			transport[0] = &bus;
			transport[1] = &trolleybus;
			transport[2] = &tramway;
			transport[3] = &newbus;

			transport[4] = &brokenbus;
			transport[5] = &brokentrolleybus;
			transport[6] = &brokentramway;

			transport[7] = &crashedbus;
			transport[8] = &crashedtrolleybus;
			transport[9] = &crashedtramway;

			transport[10] = &brokennewbus;
			transport[11] = &crashednewbus;

			//матрица коллизий
			int Collisions[4][3];
			Collisions[0][0] = 4;
			Collisions[0][1] = 7;
			Collisions[0][2] = NULL;

			Collisions[1][0] = 5;
			Collisions[1][1] = 8;
			Collisions[1][2] = NULL;

			Collisions[2][0] = 6;
			Collisions[2][1] = 9;
			Collisions[2][2] = NULL;

			Collisions[3][0] = 10;
			Collisions[3][1] = NULL;
			Collisions[3][2] = 11;

			for (int i = 0; i < 4; i++)	//проход по видам транспорта
			{
				for (int j = 0; j < 3; j++)	//проход по преп€тстви€м
				{
					if (Collisions[i][j] == NULL) continue;
					while (1) //ожидаем нажати€ клавиши 1
						if (KEY_DOWN(49))   //цифра 1 
							break;
					transport[i]->MoveTo(x0, y0);	//переносим транспорт в начальные точки
					trashes[j]->Show();		//рисуем фигуру преп€тстви€
					while (1)
					{
						transport[i]->Drag(10); //двигаем фигуру транспорта
						if (IsCollision(transport[i], trashes[j]))	//проверка на коллизию
						{
							transport[i]->Hide();	//пр€чем фигуру транспорта
							xNew = transport[i]->GetX(), yNew = transport[i]->GetY();	//запоминаем новые координаты
							transport[Collisions[i][j]]->MoveTo(xNew, yNew);	//вызываем объект результата коллизии
							transport[Collisions[i][j]]->Show();	//показываем фигуру результата
							while (1) //ожидаем нажати€ клавиши 2
								if (KEY_DOWN(50))   //цифра 2
									break;
							transport[Collisions[i][j]]->Hide();	//пр€чем результат коллизии
							trashes[j]->Hide();		//пр€чем преп€тствие
							break;
						}//end if
					}//end while
				}//end for
			}//end for
		}// end if
	}// end if
	return 0;
}//end main()

/******************   End of File main_program.cpp  *****************/