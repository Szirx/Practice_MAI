/*
 ***************************************************************************
 *                          ООП 				                           *
 *-------------------------------------------------------------------------*
 *                                                                         *
 * Project Name  : OOP_Lab_S4_N4.cpp     								   *
 * File Name     : main.cpp                                                *
 * Language      : C++			  		                                   *
 * Programmer(s) : Begdzhanov Magsat	   	  		                       *
 * Modified By   : Begdzhanov Magsat                                       *
 * Created       : 05 / 05 / 2022                                          *
 * Last Revision : 05 / 05 / 2022                                          *
 * Comment(s)    : Абстрактные классы и интерфейсы.                        *
 *                                                                         *
 ***************************************************************************
*/

#include <windows.h>
#include <iostream>
#include "Coordinates.h."
#include "Point.h"
#include "ITV.h"
#include "ABCFigure.h"
#include "GetConsoleWin.h"
#include "PlasmaTV.h"
#include "PlasmaTVonStand.h"
#include "PlasmaTVwLegs.h"
#include "PlasmaTVScreenOn.h"
#include "PlasmaTVScreenOff.h"
#include "PlasmaTVBroken.h"
#include "PlasmaTVColorScreen.h"
#include "PlasmaTVBlueScreen.h"
#include "Remote.h"
#include "RemoteNew.h"
#include "RemoteOld.h"
#include "RemoteRound.h"
#include "Function.h"
#include "RemoteExtra.h"
#include "PLasmaTVExtra.h"

using namespace std;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;

int main()
{
	system("color F0");
	setlocale(LC_ALL, "ru");
	
	//объявление и инициализация переменных
	int x0 = 525, y0 = 175, width = 350, height = 150;
	int rx0 = 85, ry0 = 400, rwidth = 30, rheight = 70;

	

	// Получим дескриптор окна
	HWND hwnd = GetConcolWindow();

	// Если дескриптор не равен нулю то ...
	if (hwnd != NULL)
	{
		// Получим контекст устройства 
		hdc = GetWindowDC(hwnd);

		// Если контекст устройства не равен нулю то ...
		if (hdc != 0) {

			PlasmaTV Tv(x0, y0, width, height);
			PlasmaTVwLegs TvwLegs(x0, y0, width, height);
			PlasmaTVonStand TvonStand(x0, y0, width, height);
			PlasmaTVScreenOn TvOn(x0, y0, width, height);
			PlasmaTVScreenOff TvOff(x0, y0, width, height);
			PlasmaTVBroken TvBroken(x0, y0, width, height);
			PlasmaTVColorScreen TvRed(x0, y0, width, height);
			PlasmaTVBlueScreen TvBlue(x0, y0, width, height);
			PLasmaTVExtra TvExtra(x0, y0, width, height);


			Remote Remote1(rx0, ry0, rwidth, rheight);
			RemoteNew RemoteNew(rx0, ry0, rwidth + 15, rheight + 15);
			RemoteOld RemoteOld(rx0, ry0, rwidth - 10, rheight - 10);
			RemoteRound RemoteRound(rx0, ry0, 20, 30);
			RemoteExtra RemoteExtra(rx0, ry0, 50, 50);

			PlasmaTV* figureTV[7]; 
			figureTV[0] = &TvonStand;
			figureTV[1] = &TvOn;
			figureTV[2] = &TvOff;
			figureTV[3] = &TvExtra;
			figureTV[4] = &TvRed;
			figureTV[5] = &TvBlue;
			figureTV[6] = &TvBroken;
			

			Remote* figureRm[5];
			figureRm[0] = &Remote1;
			figureRm[1] = &RemoteNew;
			figureRm[2] = &RemoteOld;
			figureRm[3] = &RemoteRound;
			figureRm[4] = &RemoteExtra;


			int CollisionCase[4][5];
			CollisionCase[0][0] = 3;
			CollisionCase[0][1] = 4;
			CollisionCase[0][2] = 5;
			CollisionCase[0][3] = 3;
			CollisionCase[0][4] = 5;

			CollisionCase[1][0] = 4;
			CollisionCase[1][1] = 5;
			CollisionCase[1][2] = 3;
			CollisionCase[1][3] = 4;
			CollisionCase[1][4] = 5;
			
			CollisionCase[2][0] = 5;
			CollisionCase[2][1] = 4;
			CollisionCase[2][2] = 5;
			CollisionCase[2][3] = 3;
			CollisionCase[2][4] = 4;

			CollisionCase[3][0] = 3;
			CollisionCase[3][1] = 3;
			CollisionCase[3][2] = 4;
			CollisionCase[3][3] = 5;
			CollisionCase[3][4] = 5; 

			figureTV[3]->Show();
			figureRm[4]->Show();
			Sleep(4000);
			figureTV[3]->Hide();
			figureRm[4]->Hide();

			for (int iR = 0; iR < 5; iR++)
			{
				for (int iTV = 0; iTV < 4; iTV++) {
					figureTV[iTV]->Show();
					Sleep(1000);
					figureRm[iR]->Show();

					while (1) {
						figureRm[iR]->Drag(5);

						if (Collision(figureTV[iTV], figureRm[iR])) {
							figureTV[iTV]->Show();
							Sleep(1000);
							figureTV[CollisionCase[iTV][iR]]->Show();
							break;
						}
					}

					figureRm[iR]->Move(rx0, ry0);
					Sleep(1000);
					figureRm[iR]->Hide();
				}
			}

		

		}

	}
}
