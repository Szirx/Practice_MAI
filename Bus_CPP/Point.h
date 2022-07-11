#pragma once
#include "Location.h"
class Point : public Location
{
protected:							
	bool Visible;					//�������� ����� ��� ���

public:
	Point(int InitX, int InitY);	//����������� ������
	~Point();						//����������
	bool IsVisible();				//������ ��� ���������� �����
	void MoveTo(int NewX, int NewY);//����������� ������
	void Drag(int Step);			//���������� ������

	virtual void Show();              //�������� ������ �����
	virtual void Hide();              //�������� ������ �����

};//end class Point