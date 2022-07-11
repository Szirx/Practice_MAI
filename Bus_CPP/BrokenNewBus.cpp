#include <windows.h>
#include "BrokenNewBus.h"
#include "NewBus.h"
extern HDC hdc;      // �������  �������� ����������
const int WIDTH = 120;

//�����������
BrokenNewBus::BrokenNewBus(int InitX1, int InitY1) : NewBus(InitX1, InitY1)
{

}//end BrokenBus::BrokenBus()

//����������
BrokenNewBus::~BrokenNewBus(void)  //��������� ������ ����
{

}//end BrokenBus::~BrokenBus()

//����� ������ � �������
void BrokenNewBus::Show(void)
{
	Visible = true;
	NewBus::Show();	//������ ������ ������
	//������� ���� ���� �����
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//������ ������
	Ellipse(hdc, X2 - 155, Y2 - 55, X2 - 45, Y2 + 55);
	Ellipse(hdc, X2 - 145, Y2 - 45, X2 - 55, Y2 + 45);
	//������ ����
	Ellipse(hdc, X2 - 30, Y2 - 40, X2 - 10, Y2 - 100);
	//������� ���� ���� ������
	HPEN Black = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Black);
	//�������� ������� �� ������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ������� �� ������
	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	DeleteObject(Black);
	DeleteObject(White);
}//end BrokenBus::Show()

//�������� ������ � �������
void BrokenNewBus::Hide(void)
{
	Visible = false;
	NewBus::Hide(); //������� ������ ������
	//������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);

	MoveToEx(hdc, X2 - 155, Y2, NULL);
	LineTo(hdc, X2 - 45, Y2);
	DeleteObject(Pen);
}//end BrokenBus::Hide()