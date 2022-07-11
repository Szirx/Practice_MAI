/***---------------------------------------****
****---------------���� ���----------------****
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
#include "GetConlWin.h"		//��������� �� ���������� ����

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc;	// ������� �������� ����������

bool IsCollision(AbsBody* transport, iTrash* trash)
{
	bool collisionX = true; //�������� �� X
	bool collisionY = true; //�������� �� Y

	int transportCoordinates[4];	//���������� ����������
	transportCoordinates[0] = transport->GetX();							//���������� X1
	transportCoordinates[1] = transport->GetX() + transport->GetWidth();	//���������� X2
	transportCoordinates[2] = transport->GetY();							//���������� Y1
	transportCoordinates[3] = transport->GetY() + transport->GetHeigth();	//���������� Y2

	int trashCoordinates[2];	//���������� �����������
	trashCoordinates[0] = trash->GetX() + trash->GetWidth() / 2;	//���������� � ������ �����������
	trashCoordinates[1] = trash->GetY() + trash->GetHeigth() / 2;	//���������� Y ������ �����������
	
	//�������� ���������� �������� �� ���������� X
	if (trashCoordinates[0] > transportCoordinates[1] || trashCoordinates[0] < transportCoordinates[0]) collisionX = false;
	//�������� ���������� �������� �� ���������� Y
	if (trashCoordinates[1] > transportCoordinates[3] || trashCoordinates[1] < transportCoordinates[2]) collisionX = false;

	if (collisionX && collisionY)	//���� ��������� �������� �� ����� ����
	{
		return true;
	}
	return false;
}//end bool IsCollision

int main()
{
	//���������� � ������������� ����������
	int x0 = 50, y0 = 270;		//��������� ���������� ��� ����������
	int x01 = 1100, y01 = 350;		//��������� ���������� ��� �����������
	int xNew = 0, yNew = 0;		//���������� ����� ������������
	//������� ���������� ����������� ����
	HWND hwnd = GetConcolWindow();

	//���� ���������� ���������� - ����� ��������
	if (hwnd != NULL)
	{
		//������� �������� ���������� ��� ����������� ����
		hdc = GetWindowDC(hwnd);

		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{

			Bus bus(x0, y0);		//�������
			NewBus newbus(x0, y0);
			Trolleybus trolleybus(x0, y0);	//����������
			Tramway tramway(x0, y0);	//�������
			
			//������� ����� ������������
			CrashedBus crashedbus(x0, y0);
			BrokenBus brokenbus(x0, y0);
			CrashedTramway crashedtramway(x0, y0);
			BrokenTramway brokentramway(x0, y0);
			CrashedTrolleybus crashedtrolleybus(x0, y0);
			BrokenTrolleybus brokentrolleybus(x0, y0);
			CrashedNewBus crashednewbus(x0, y0);
			BrokenNewBus brokennewbus(x0, y0);

			//������� �����������
			Trash trash(x01, y01);
			BigTrash bigtrash(x01, y01);
			NewTrash newtrash(x01, y01);

			//������ ���������� �� ������� �����������
			iTrash* trashes[3];
			trashes[0] = &trash;
			trashes[1] = &bigtrash;
			trashes[2] = &newtrash;

			//������ ���������� �� ������� ����������
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

			//������� ��������
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

			for (int i = 0; i < 4; i++)	//������ �� ����� ����������
			{
				for (int j = 0; j < 3; j++)	//������ �� ������������
				{
					if (Collisions[i][j] == NULL) continue;
					while (1) //������� ������� ������� 1
						if (KEY_DOWN(49))   //����� 1 
							break;
					transport[i]->MoveTo(x0, y0);	//��������� ��������� � ��������� �����
					trashes[j]->Show();		//������ ������ �����������
					while (1)
					{
						transport[i]->Drag(10); //������� ������ ����������
						if (IsCollision(transport[i], trashes[j]))	//�������� �� ��������
						{
							transport[i]->Hide();	//������ ������ ����������
							xNew = transport[i]->GetX(), yNew = transport[i]->GetY();	//���������� ����� ����������
							transport[Collisions[i][j]]->MoveTo(xNew, yNew);	//�������� ������ ���������� ��������
							transport[Collisions[i][j]]->Show();	//���������� ������ ����������
							while (1) //������� ������� ������� 2
								if (KEY_DOWN(50))   //����� 2
									break;
							transport[Collisions[i][j]]->Hide();	//������ ��������� ��������
							trashes[j]->Hide();		//������ �����������
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