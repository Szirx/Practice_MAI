#include <windows.h>
#include "NewTrash.h"	//���������� �������
#include "Trash.h"
extern HDC hdc;      //������� �������� ����������

//�����������
NewTrash::NewTrash(int InitX1, int InitY1) : Trash(InitX1, InitY1)
{
	width = 200;
	heigth = 100;
}//end BigTrash::BigTrash()

//����������
NewTrash::~NewTrash(void)  //��������� ������ ����
{

}//end BigTrash::~BigTrash()

//����� ������ � �������
void NewTrash::Show(void)
{
	//������� ���������� ������ �����
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = true;
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//�������� ������
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y1);
	LineTo(hdc, X2 - 20, Y2);
	LineTo(hdc, X1 + 20, Y2);
	LineTo(hdc, X1, Y1);
	LineTo(hdc, X2 - 20, Y2);
	MoveToEx(hdc, X2, Y1, NULL);
	LineTo(hdc, X1 + 20, Y2);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end BigTrash::Show()

//�������� ������ � �������
void NewTrash::Hide(void)
{
	//������� ���������� ������ �����
	X2 = X1 + width;
	Y2 = Y1 + heigth;
	Visible = false;
	//������� ���� ���� �����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//������ ������
	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y1);
	LineTo(hdc, X2 - 20, Y2);
	LineTo(hdc, X1 + 20, Y2);
	LineTo(hdc, X1, Y1);
	LineTo(hdc, X2 - 20, Y2);
	MoveToEx(hdc, X2, Y1, NULL);
	LineTo(hdc, X1 + 20, Y2);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}// end BigTrash::Hide()