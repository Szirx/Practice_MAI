#pragma once
#include "Point.h"

/*-----------------------  ����� ����  ----------------------------------*/
class Circle : public Point
{
protected:
	//private:						//������������� , �.�. �� ���������
	int Radius;					//������ �����
public:
	//����������� � ����������� �� ���������
	Circle(int InitX1 = 10, int InitY1 = 10, int InitRadius = 10);

	virtual ~Circle();	// ����������� ����������

	void Expand(int DeltaRad);	//��������� ������ �����
	void Reduce(int DeltaRad);	//��������� ������ �����

	virtual	void Show();		//�������� ������ ����
	virtual	void Hide();		//������ ������ ����

//	void MoveTo (int NewX, int NewY);  //����� ������ ������! ����� �� Point

};//end class Circle