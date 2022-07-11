#include <Windows.h>
#include "Circle.h"

/*-----------------------------------------------------------------------*/
/*        ������ ������ Circle            */
/*----------------------------------------*/
//��� ������������� �������� ����� ���������� ����������� ������
Circle::Circle(int InitX1, int InitY1, int InitRadius) :Point(InitX1, InitY1)
{
	//������������� �������� ���������� ������ ������
	Radius = InitRadius;
}//end Circle::Circle ()

//-------------------------------------------------------------------
Circle::~Circle(void)  //��������� ������ ����
{
};//end Circle::~Circle ()

//-------------------------------------------------------------------
void Circle::Show(void)
{

	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X1 - Radius, Y1 - Radius, X1 + Radius, Y1 + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);

} // end Circle::Show()

//-------------------------------------------------------------------
void Circle::Hide(void)
{

	// ������� ���� � ���� ����``
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //�����
	//	HPEN Pen=::CreatePen(PS_SOLID,2,RGB(255,255,255));
	SelectObject(hdc, Pen);

	// �������� ���� ������������� ������
	Ellipse(hdc, X1 - Radius, Y1 - Radius, X1 + Radius, Y1 + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);

}// end Circle::Hide()

//-------------------------------------------------------------------
/* �����  ������ ��������� ����������� ��������    !!
void Circle::MoveTo(int NewX, int NewY)  //����� �� Point
{
	Hide();  //�������� ������ ����������
	X= NewX; //�������� ����������
	Y= NewY;
	Show();  //�������� ���������� �� ����� �����
}//end Circle::MoveTo()
*/
//-------------------------------------------------------------------
void Circle::Expand(int DeltaRad)
{
	Hide();             //�������� ���������� �� ������ ��������
	Radius += DeltaRad; //�������� ������ 
	if (Radius < 0)     //��� �������������� ���������� �������
		Radius = 5;
	Show();             //�������� ���������� � ����� ��������
}//end Circle::Expand ()

//---------------------------------------------------------------
void Circle::Reduce(int DeltaRad)
{
	Expand(-DeltaRad); //������������� ���������� �������
}//end Circle::Reduce ()

//void Circle::Narrow(int DeltaRad, int Choice)
//{
//	Expand(-Delta)
//}
