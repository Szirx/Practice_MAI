#include <windows.h>
#include <math.h>
#include <iostream>
#include "Point.h"	//���������� �������
#include "Lamppost.h"
extern HDC hdc;      // �������  �������� ����������
const double STEP = 0.2;

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//�����������
Lamppost::Lamppost(int InitX1, int InitY1) : Point(InitX1, InitY1)
{

}//end Lamppost::Lamppost()

//����������
Lamppost::~Lamppost(void)  //��������� ������ ����
{

}//end Lamppost::~Lamppost()

//����� ������ � �������
void Lamppost::Show()
{

}

//�������� ������ � �������
void Lamppost::Hide()
{

}

//���������� ������
void Lamppost::UpScale()
{

}

//���������� ������
void Lamppost::DownScale()
{

}