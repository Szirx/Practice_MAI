#include<windows.h>
#include "Location.h"	//���������� �������
extern HDC hdc;      // �������  �������� ����������

Location::Location(int InitX, int InitY)
{
	//������������� �������� ���������� ������ ������
	X1 = InitX;
	Y1 = InitY;
};//end Location::Location()

  //����������
Location::~Location(void)  //��������� ������ ����
{
};//end Location::~Location()

  //�������� X ���������� �����
int Location::GetX(void)
{
	return X1;
};//end Location::GetX()	

  //�������� Y ���������� �����
int Location::GetY(void)
{
	return Y1;
}; //end Location::GetY()