#include <windows.h>
#include "BigTrash.h"	//���������� �������
#include "Trash.h"
extern HDC hdc;      //������� �������� ����������

//�����������
BigTrash::BigTrash(int InitX1, int InitY1) : Trash(InitX1, InitY1)
{
	width = 200;
	heigth = 100;
}//end BigTrash::BigTrash()

//����������
BigTrash::~BigTrash(void)  //��������� ������ ����
{

}//end BigTrash::~BigTrash()

//����� ������ � �������
void BigTrash::Show(void)
{
	//������� ���������� ������ �����
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//�������� ������
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 + 20, Y1 + 20, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X1 + 20, Y1 + 20, NULL);
	LineTo(hdc, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X2 - 20, Y1 + 20, NULL);
	LineTo(hdc, X1 + 20, Y2 - 20);
	Ellipse(hdc, X1, Y2, X1 + 10 , Y2 + 10);
	Ellipse(hdc, X2 - 10, Y2, X2, Y2 + 10);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end BigTrash::Show()

//�������� ������ � �������
void BigTrash::Hide(void)
{
	//������� ���������� ������ �����
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//������ ������
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 + 20, Y1 + 20, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X1 + 20, Y1 + 20, NULL);
	LineTo(hdc, X2 - 20, Y2 - 20);
	MoveToEx(hdc, X2 - 20, Y1 + 20, NULL);
	LineTo(hdc, X1 + 20, Y2 - 20);
	Ellipse(hdc, X1, Y2, X1 + 10, Y2 + 10);
	Ellipse(hdc, X2 - 10, Y2, X2, Y2 + 10);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end BigTrash::Hide()