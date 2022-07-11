#include <windows.h>
#include "BrokenTrolleybus.h"
#include "Trolleybus.h"
extern HDC hdc;      // �������  �������� ����������
const int WIDTH = 120;

//�����������
BrokenTrolleybus::BrokenTrolleybus(int InitX1, int InitY1) : Trolleybus(InitX1, InitY1)
{

}//end BrokenTrolleybus::BrokenTrolleybus()

//����������
BrokenTrolleybus::~BrokenTrolleybus(void)  //��������� ������ ����
{

}//end BrokenTrolleybus::~BrokenTrolleybus()

void BrokenTrolleybus::Show(void)
{
	Visible = true;
	Trolleybus::Show();	//������ ������ ������
	//������� ���� ���� �����
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//������� ������
	Ellipse(hdc, X2 - 155, Y2 - 55, X2 - 45, Y2 + 55);
	Ellipse(hdc, X2 - 145, Y2 - 45, X2 - 55, Y2 + 45);
	//������� ����
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	//������� ���� ���� ������
	HPEN Black = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Black);
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ������� �� ������
	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	//������ �������
	DeleteObject(Black);
	DeleteObject(White);
}//end BrokenTrolleybus::Show()

void BrokenTrolleybus::Hide(void)
{
	Visible = false;
	Trolleybus::Hide();	//������� ������ ������
	// ������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);

	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	//������ ������
	DeleteObject(Pen);
}//end BrokenTrolleybus::Hide()