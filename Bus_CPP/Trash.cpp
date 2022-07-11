#include <windows.h>
#include <iostream>
#include "iTrash.h"	//���������� �������
#include "Trash.h"
extern HDC hdc;      // �������  �������� ����������

//�����������
Trash::Trash(int InitX1, int InitY1) : iTrash(InitX1, InitY1)
{

}//end Trash::Trash()

//����������
Trash::~Trash(void)  //��������� ������ ����
{

}//end Trash::~Trash()

//����� ������ � �������
void Trash::Show(void)
{
	//��������� ����������
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 - 10, Y1 - 10, X2 + 10, Y1);
	MoveToEx(hdc, X1 + 15, Y1 - 10, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 15, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 10);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end Trash::Show()

//�������� ������ � �������
void Trash::Hide(void)
{
	//������� ����������
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//������� ���� ���� �����
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	Rectangle(hdc, X1, Y1, X2, Y2);
	Rectangle(hdc, X1 - 10, Y1 - 10, X2 + 10, Y1);
	MoveToEx(hdc, X1 + 15, Y1 - 10, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 15, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 15);
	LineTo(hdc, X1 + 45, Y1 - 10);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end Trash::Hide()

//�������� ����� ������
int Trash::GetWidth()
{
	return width;
}//end Trash::GetWidth()

//�������� ������ ������
int Trash::GetHeigth()
{
	return heigth;
}//end Trash::GetHeigth()