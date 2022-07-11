#include <windows.h>
#include "CrashedTrolleybus.h"
#include "Trolleybus.h"
extern HDC hdc;      // �������  �������� ����������
const int WIDTH = 120;

//�����������
CrashedTrolleybus::CrashedTrolleybus(int InitX1, int InitY1) : Trolleybus(InitX1, InitY1)
{

}//end CrashedTrolleybus::CrashedTrolleybus()

//����������
CrashedTrolleybus::~CrashedTrolleybus(void)  //��������� ������ ����
{

}//end CrashedTrolleybus::~CrashedTrolleybus()

//����� ������ � �������
void CrashedTrolleybus::Show(void)
{
	Visible = true;
	Trolleybus::Show();	//������ ������ ������
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ���� ���� �����
	HPEN Gray = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
	SelectObject(hdc, Gray);
	//������ ���
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//������� ���� ���� �����
	HPEN White = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, White);
	//������� ����
	MoveToEx(hdc, X1 + 670, Y1, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 570, Y1 - 120);
	//������� �������
	DeleteObject(Pen);
	DeleteObject(Gray);
	DeleteObject(White);
}//end CrashedTrolleybus::Show()

//�������� ������ � �������
void CrashedTrolleybus::Hide(void)
{
	Visible = false;
	Trolleybus::Hide();	//������� ������ ������
	//������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//������� �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ���
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//������� ������
	DeleteObject(Pen);
}//end CrashedTrolleybus::Hide()