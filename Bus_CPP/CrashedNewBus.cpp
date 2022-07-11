#include <windows.h>
#include "CrashedNewBus.h"
#include "NewBus.h"
extern HDC hdc;      // �������  �������� ����������
const int WIDTH = 120;

//�����������
CrashedNewBus::CrashedNewBus(int InitX1, int InitY1) : NewBus(InitX1, InitY1)
{

}//end CrashedBus::CrashedBus()

//����������
CrashedNewBus::~CrashedNewBus(void)  //��������� ������ ����
{

}//end CrashedBus::~CrashedBus()

//����� ������ � �������
void CrashedNewBus::Show(void)
{
	Visible = true;
	NewBus::Show();	//������ ������ ������
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
	//������� �������
	DeleteObject(Pen);
	DeleteObject(Gray);
}//end CrashedBus::Show()

//�������� ������ � �������
void CrashedNewBus::Hide(void)
{
	Visible = false;
	NewBus::Hide();	//������ ������ ������
	//������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	//������� �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL);
	LineTo(hdc, X1 + (540 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (550 + WIDTH), Y1 + 60);
	LineTo(hdc, X1 + (510 + WIDTH), Y1 + 100);
	//������� ���
	Ellipse(hdc, X2 - 100, Y2 + 20, X2 - 300, Y2 - 100);
	Ellipse(hdc, X2 - 300, Y2 - 70, X2 - 120, Y2 - 150);
	Ellipse(hdc, X2 - 350, Y2 - 130, X2 - 200, Y2 - 180);
	//������� ������
	DeleteObject(Pen);
}//end CrashedBus::Hide()