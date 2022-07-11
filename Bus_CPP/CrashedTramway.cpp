#include <windows.h>
#include "CrashedTramway.h"
#include "Tramway.h"
extern HDC hdc;      // �������  �������� ����������
const int WIDTH = 120;


//�����������
CrashedTramway::CrashedTramway(int InitX1, int InitY1) : Tramway(InitX1, InitY1)
{

}//end CrashedTramway::CrashedTramway()

//����������
CrashedTramway::~CrashedTramway(void)  //��������� ������ ����
{

}//end CrashedTramway::~CrashedTramway()

//����� ������ � �������
void CrashedTramway::Show(void)
{
	Visible = true;
	Tramway::Show();	//������ ������ ������
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	//������ �������
	MoveToEx(hdc, X1 + (580 + WIDTH), Y1 + 20, NULL); //������� �������� ���������� x1, y1
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
	MoveToEx(hdc, X1 + 300, Y1, NULL); //������� �������� ���������� x1, y1
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 260, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 100);
	LineTo(hdc, X1 + 460, Y1 - 80);
	LineTo(hdc, X1 + 360, Y1 - 60);
	LineTo(hdc, X1 + 420, Y1);
	//������� �������
	DeleteObject(Pen);
	DeleteObject(Gray);
	DeleteObject(White);
}//end CrashedTramway::Show()

//�������� ������ � �������
void CrashedTramway::Hide(void)
{
	Visible = false;
	Tramway::Hide();	//������� ������ ������
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
}//end CrashedTramway::Hide()