#include <Windows.h>
#include "Line.h"

Line::Line(int InitX1, int InitY1, int InitX2, int InitY2) :Point(InitX1, InitY1)
{
	X2 = InitX2;
	Y2 = InitY2;
}

Line::~Line(void){};

void Line::Show(void)
{
	Visible = true;

	// ������� ���� � ���� ���� - ������� � ������� ����
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

	SelectObject(hdc, Pen);	//������� ���� ��������

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y2);

	DeleteObject(Pen);
}

void Line::Hide(void)
{
	Visible = false;

	// ������� ���� � ���� ����
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //�����
	//	HPEN Pen=::CreatePen(PS

	MoveToEx(hdc, X1, Y1, NULL);
	LineTo(hdc, X2, Y2);

	DeleteObject(Pen);
}

int Line::GetX2(void)
{
	return X2;
};//end 	

  //�������� Y ���������� �����
int Line::GetY2(void)
{
	return Y2;
}; //end 

void Line::MoveTo(int NewX1, int NewY1, int NewX2, int NewY2)
{
	Hide();		//������� ����� ���������
	X1 = NewX1;	//�������� ���������� �����
	Y1 = NewY1;
	X2 = NewX2;	//�������� ���������� �����
	Y2 = NewY2;
	Show();		//�������� ����� �� ����� �����
}

void Line::Drag(int Step)
{
	int X1, Y1, X2, Y2;   //����� ���������� ������

	X1 = GetX1();    //�������� ��������� ��������� ������
	Y1 = GetY1();
	X2 = GetX2();
	Y2 = GetY2();

	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27
			break;

		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			X1 -= Step;
			X2 -= Step;
			MoveTo(X1, Y1, X2, Y2);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			X1 += Step;
			X2 += Step;
			MoveTo(X1, Y1, X2, Y2);

			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			Y1 += Step;
			Y2 += Step;
			MoveTo(X1, Y1, X2, Y2);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			Y1 -= Step;
			Y2 -= Step;
			MoveTo(X1, Y1, X2, Y2);
			Sleep(500);
		}//end if
	}   //while
}