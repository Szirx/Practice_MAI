#include <windows.h>
#include "Body.h"	//���������� �������
#include "Tramway.h"
extern HDC hdc;      // �������  �������� ����������
const int RADIUS = 30;
const int WIDTH = 120;
const int HEIGTH = 290;

//�����������
Tramway::Tramway(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Tramway::Tramway()

//����������
Tramway::~Tramway(void)  //��������� ������ ����
{

}//end Tramway::~Tramway()

//����� ������ � �������
void Tramway::Show(void)
{
	Visible = true;
	Body::Show(); //������ ������ ������
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//������ �����
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//������ ������
	Ellipse(hdc, X1 + (50 - RADIUS), Y2 - RADIUS, X1 + (50 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (110 - RADIUS), Y2 - RADIUS, X1 + (110 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (330 - RADIUS), Y2 - RADIUS, X1 + (330 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (390 - RADIUS), Y2 - RADIUS, X1 + (390 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (610 - RADIUS), Y2 - RADIUS, X1 + (610 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (670 - RADIUS), Y2 - RADIUS, X1 + (670 + RADIUS), Y2 + RADIUS);
	//������ ����
	MoveToEx(hdc, X1 + 300, Y1, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}//end Tramway::Show()

//�������� ������ � �������
void Tramway::Hide(void)
{
	Visible = false;
	Body::Hide(); //������� ������ ������
	//������� ���� ���� �����
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//������� �����
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + HEIGTH));
	Rectangle(hdc, X1 + 180, Y1 + 40, X1 + (140 + WIDTH), Y1 + WIDTH);
	//������� ������
	Ellipse(hdc, X1 + (50 - RADIUS), Y2 - RADIUS, X1 + (50 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (110 - RADIUS), Y2 - RADIUS, X1 + (110 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (330 - RADIUS), Y2 - RADIUS, X1 + (330 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (390 - RADIUS), Y2 - RADIUS, X1 + (390 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (610 - RADIUS), Y2 - RADIUS, X1 + (610 + RADIUS), Y2 + RADIUS);
	Ellipse(hdc, X1 + (670 - RADIUS), Y2 - RADIUS, X1 + (670 + RADIUS), Y2 + RADIUS);
	//������� ����
	MoveToEx(hdc, X1 + 300, Y1, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}//end Tramway::Hide()