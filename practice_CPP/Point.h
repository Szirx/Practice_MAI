#pragma once
#include "Location.h"
/*-----------------------  ����� ����� ----------------------------------*/
class Point : public Location
{
	// Point - ����������� ����� �� Location
	// ������� public � ���������� ������������ ������ ��������
	// ����������� ������ ������ �� ����� � �������, ��������������
	// �� Location

protected:							//�������, ����������� �� Point, ����������� ������ public
	bool Visible;					//�������� ����� ��� ���

public:
	Point(int InitX1, int InitY1);	//����������� ������
	virtual ~Point();	// ����������� ����������
	bool IsVisible();				//������ ��� ���������� �����
	virtual void MoveTo(int NewX1, int NewY1);//����������� ������
	virtual void Drag(int Step);			//���������� ������

	//int GetX1();

		//����������� �������
	virtual void Show();              //�������� ������ �����
	virtual void Hide();              //�������� ������ �����

};//end class Point