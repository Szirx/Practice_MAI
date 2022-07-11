#include <windows.h>
#include "Body.h"
#include "Bus.h"
extern HDC hdc;      // �������  �������� ����������
const int BIGRADIUS = 55;
const int SMALLRADIUS = 45;
const int WIDTH = 120;

//�����������
Bus::Bus(int InitX1, int InitY1) : Body(InitX1, InitY1)
{

}//end Bus::Bus()

//����������
Bus::~Bus(void)  //��������� ������ ����
{

}//end Bus::~Bus()

//����� ������ � �������
void Bus::Show(void)
{
	Visible = true;
	Body::Show();	//������ ������ ������
	//������� ���� ���� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//������ ����
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + WIDTH));
	//������ ������
	Ellipse(hdc, X1 + (140 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (140 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (140 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (140 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}//end Bus::Show()

//�������� ������ � �������
void Bus::Hide(void)
{
	Visible = false;
	Body::Hide(); //������� ������ ������
	//������� ���� ���� �����
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	//������� ����
	Rectangle(hdc, X1 + 160, Y1 + 20, X1 + (160 + WIDTH), Y1 + (20 + WIDTH));
	//������� ������
	Ellipse(hdc, X1 + (140 - BIGRADIUS), Y2 - BIGRADIUS, X1 + (140 + BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X2 - (100 + BIGRADIUS), Y2 - BIGRADIUS, X2 - (100 - BIGRADIUS), Y2 + BIGRADIUS);
	Ellipse(hdc, X1 + (140 - SMALLRADIUS), Y2 - SMALLRADIUS, X1 + (140 + SMALLRADIUS), Y2 + SMALLRADIUS);
	Ellipse(hdc, X2 - (100 + SMALLRADIUS), Y2 - SMALLRADIUS, X2 - (100 - SMALLRADIUS), Y2 + SMALLRADIUS);
	//��������� ���� ��������� �������  
	DeleteObject(Pen);
}//end Bus::Hide()