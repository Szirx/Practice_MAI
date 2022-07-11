#pragma once
/********************************************************************
 *                      К  У  Р  С  Ы     С  +  +                   *
 *------------------------------------------------------------------*
 * Project Type  : Win32 Console Application                        *
 * Project Name  :													*
 * File Name     :											        *
 * Programmer(s) : Гаматин И.С.						                *
 * Modifyed By   :                                                  *
 * Created       : 17/04/22                                         *
 * Last Revision : 17/05/22                                         *
 *                                                                  *
 ********************************************************************/

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "GetConlWin.h"

#include "Location.h"
#include "Point.h"

#include "Body.h"
#include "TreeWithBranch.h"
#include "MultiTieredTree.h"
#include "AppleTree.h"
#include "IceCreamTree.h"

#include "WateringCan.h"
#include "AcidCan.h"

#include "Water.h"
#include "Bird.h"
#include "Acid.h"

#include "function.h"
#include "DeadTree.h"
#include "RoundCan.h"

HDC hdc;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
void main()
{
	setlocale(LC_ALL, "Ru");
	system("color F0");

	//объявление и инициализация переменных
	int x1 = 400, y1 = 400;		//стартовые координаты дерева
	int Radius0 = 50;			//начальное значение радиуса
	int DeltaRad = 10;		//начальное изменение радиуса
	int width = 160, height = 250;
	int movewidth = 38, moveheight = 40;
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			WateringCan ACan(x1 - 150, y1, Radius0);
			AcidCan BCan(x1 - 150, y1, Radius0);
			Body FirstTree(x1, y1, width, height, Radius0);
			TreeWithBranch SecondTree(x1, y1, width, height, Radius0);
			IceCreamTree ThirdTree(x1, y1, width, height, Radius0);
			MultiTieredTree FourthTree(x1, y1, width, height, Radius0);
			AppleTree LastTree(x1, y1, width, height, Radius0);
			Water WaterFall(x1 , y1);
			Acid AAcid(x1 - 40, y1);
			Bird ABird(x1 - 200, y1 - 200, Radius0);

			DeadTree PostLastTree(x1, y1, width, height, Radius0);
			RoundCan ARoundCan(x1 - 150, y1, Radius0);

			Body* figureTree[6];
			figureTree[0] = &FirstTree;
			figureTree[1] = &SecondTree;
			figureTree[2] = &ThirdTree;
			figureTree[3] = &FourthTree;
			figureTree[4] = &LastTree;
			figureTree[5] = &PostLastTree;

			Point* figureMove[4];
			figureMove[0] = &ACan;
			figureMove[1] = &BCan;
			figureMove[2] = &ABird;
			figureMove[3] = &ARoundCan;

			Water* figureWF = &WaterFall;
			Acid* figureAF = &AAcid;

			int CollisionCase[4][6];
			//Water
			CollisionCase[0][0] = 1;
			CollisionCase[0][1] = 2;
			CollisionCase[0][2] = 3;
			CollisionCase[0][3] = 4;
			CollisionCase[0][4] = NULL;
			CollisionCase[0][5] = NULL;
			//Acid
			CollisionCase[1][0] = NULL;
			CollisionCase[1][1] = 0;
			CollisionCase[1][2] = 1;
			CollisionCase[1][3] = 2;
			CollisionCase[1][4] = 3;
			CollisionCase[1][5] = NULL;
			//Bird
			CollisionCase[2][0] = 4;
			CollisionCase[2][1] = 4;
			CollisionCase[2][2] = 4;
			CollisionCase[2][3] = 4;
			CollisionCase[2][4] = 4;
			CollisionCase[2][5] = 4;
			//RoundCan
			CollisionCase[3][0] = NULL;
			CollisionCase[3][1] = NULL;
			CollisionCase[3][2] = NULL;
			CollisionCase[3][3] = NULL;
			CollisionCase[3][4] = NULL;
			CollisionCase[3][5] = 1;


			for (int iMove = 0; iMove < 4; iMove++)
			{
				for (int iTree = 0; iTree < 6; iTree++)
				{
					if (CollisionCase[iMove][iTree] == NULL) continue;
					figureTree[iTree]->Show();
					figureMove[iMove]->MoveTo(x1 - 150, y1);
					figureMove[iMove]->Show();

					while (1) {
						figureMove[iMove]->Drag(5);
						if (Collision(figureTree[iTree], figureMove[iMove]))
						{
							if (iMove == 0 || iMove == 3) {
								figureWF->MoveTo(figureMove[iMove]->GetX1() + 80, figureMove[iMove]->GetY1());
								figureWF->Show();
								Sleep(200);
								figureWF->Hide();
							}
							if (iMove == 1) {
								figureAF->MoveTo(figureMove[iMove]->GetX1() + 80, figureMove[iMove]->GetY1());
								figureAF->Show();
								Sleep(200);
								figureAF->Hide();
							}
							figureTree[iTree]->Hide();
							Sleep(1000);
							figureMove[iMove]->Hide();
							figureTree[CollisionCase[iMove][iTree]]->Show();
							figureMove[iMove]->Show();
							Sleep(1000);
							figureTree[CollisionCase[iMove][iTree]]->Hide();
							break;
						}
					}	
					figureTree[iTree]->Hide();
				}
			}
		}// end if
	}// end if
}//end main()