#include <Windows.h>
#include "Location.h"
/*-----------------------------------------------------------------------*/
/*        ������ ������ Location          */
/*----------------------------------------*/
//�����������
Location::Location(int InitX1, int InitY1)
{
	//������������� �������� ���������� ������ ������
	X1 = InitX1;
	Y1 = InitY1;
};//end Location::Location()

  //����������
Location::~Location(void)  //��������� ������ ����
{
};//end Location::~Location()

  //�������� X ���������� �����
int Location::GetX1(void)
{
	return X1;
};//end Location::GetX()	

  //�������� Y ���������� �����
int Location::GetY1(void)
{
	return Y1;
}; //end Location::GetY()