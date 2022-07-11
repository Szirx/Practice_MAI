#pragma once
#include <iostream>
#include <Windows.h>

extern HDC hdc;

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class Location
{
protected:		//������������� ����������� �������� (������������ 
				//������) ����� ������ � ������� ������
	int X1;		//���������� X
	int Y1;		//���������� Y

public:   //��� ������ �������� ����� ���� � ���������

	Location(int InitX1, int InitY1); //�����������
	~Location();                    //����������
	int GetX1();						//�������� X ���������� �����
	int GetY1();						//�������� Y ���������� �����
};//end class Location