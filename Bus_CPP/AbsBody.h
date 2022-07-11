#pragma once
#include "Point.h"
class AbsBody : public Point
{
protected:
	int width = 0;			//����� ������
	int heigth = 0;			//������ ������
	int X2 = 0;				//������ ���������� X
	int Y2 = 0;				//������ ���������� Y
public:
	//����������� � ����������� �� ���������
	AbsBody(int InitX1 = 10, int InitY1 = 10);
	~AbsBody() = default;					//����������

	virtual int GetWidth() = 0;
	virtual int GetHeigth() = 0;

	virtual	void Show() = 0;
	virtual	void Hide() = 0;

};//end class AbsBody