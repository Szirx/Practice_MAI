#pragma once
class Location
{
protected:
	int X1;		//���������� X
	int Y1;		//���������� Y
public:
	Location(int InitX, int InitY); //�����������
	~Location();                    //����������
	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
}; //end class Location