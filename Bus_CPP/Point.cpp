#include<windows.h>
#include "Point.h"	//���������� �������
#include "Location.h"
extern HDC hdc;      // �������  �������� ����������

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	//������������� �������� ���������� ������ ������
	Visible = false;
}//end Point::Point()

 //--------------------------------------------------------------
 //����������
Point::~Point(void)   //��������� ������ ����
{
}//end Point::~Point()

 //--------------------------------------------------------------
 //�������� �����
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X1, Y1, RGB(0, 0, 0));	//������ ������� ������
	SetPixel(hdc, X1 + 1, Y1, RGB(0, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X1, Y1 + 1, RGB(0, 0, 0));
	SetPixel(hdc, X1 + 1, Y1 + 1, RGB(0, 0, 0));
}//end Point::Show()

 //--------------------------------------------------------------
 //������ �����
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X1, Y1, RGB(255, 255, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X1 + 1, Y1, RGB(255, 255, 255));
	SetPixel(hdc, X1, Y1 + 1, RGB(255, 255, 255));
	SetPixel(hdc, X1 + 1, Y1 + 1, RGB(255, 255, 255));
}//end Point::Hide()

 //--------------------------------------------------------------
 //������ ��� ���������� �����
bool Point::IsVisible(void)
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------
//����������� �����
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X1 = NewX;	//�������� ���������� �����
	Y1 = NewY;
	Show();		//�������� ����� �� ����� �����
};//end Point::MoveTo()

  //-------------------------------------------------------------------
void Point::Drag(int Step)    //���������� ������
{
	int FigX, FigY;   //����� ���������� ������

	FigX = GetX();    //�������� ��������� ��������� ������
	FigY = GetY();
	//����������� �������� �������

	if (KEY_DOWN(VK_LEFT)) //������� �����  37
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if

	if (KEY_DOWN(VK_RIGHT)) //������� ������  39
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if
	
	if (KEY_DOWN(VK_DOWN)) //������� ����  40
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if

	if (KEY_DOWN(VK_UP)) //������� �����  38
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(10);
	}//end if
}//end Drag()