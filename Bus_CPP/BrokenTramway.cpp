#include <windows.h>
#include "BrokenTramway.h"
#include "Tramway.h"
extern HDC hdc;      //������� �������� ����������
const int WIDTH = 120;

//�����������
BrokenTramway::BrokenTramway(int InitX1, int InitY1) : Tramway(InitX1, InitY1)
{

}//end BrokenTramway::BrokenTramway()

//����������
BrokenTramway::~BrokenTramway(void)  //��������� ������ ����
{

}//end BrokenTramway::~BrokenTramway()

//����� ������ � �������
void BrokenTramway::Show(void)
{
	Visible = true;
	Tramway::Show();	//������ ������ ������
	//������� ���� ���� �����
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//������ ����
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	//������ ������
	Ellipse(hdc, X1 + 640, Y2 - 30, X1 + 700, Y2 + 30);
	Ellipse(hdc, X1 + 300, Y2 - 30, X1 + 360, Y2 + 30);
	//������� ���� ���� ������
	HPEN Black = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Black);
	//�������� �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ������� �� �����
	MoveToEx(hdc, X1 + 640, Y2, NULL);
	LineTo(hdc, X1 + 700, Y2);
	MoveToEx(hdc, X1 + 360, Y2, NULL);
	LineTo(hdc, X1 + 300, Y2);
	//������ �������
	DeleteObject(Black);
	DeleteObject(White);
}//end BrokenTramway::Show()

//�������� ������ � �������
void BrokenTramway::Hide(void)
{
	Visible = false;
	Tramway::Hide();	//������� ������ ������
	//������� ���� ���� ����� 
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);

	MoveToEx(hdc, X1 + 640, Y2, NULL);
	LineTo(hdc, X1 + 700, Y2);
	MoveToEx(hdc, X1 + 360, Y2, NULL);
	LineTo(hdc, X1 + 300, Y2);
	//������ ������
	DeleteObject(Pen);
}//end BrokenTramway::Hide()