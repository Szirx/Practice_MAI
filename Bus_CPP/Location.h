#pragma once
class Location
{
protected:
	int X1;		//координата X
	int Y1;		//координата Y
public:
	Location(int InitX, int InitY); //конструктор
	~Location();                    //деструктор
	int GetX();						//получить X координату точки
	int GetY();						//получить Y координату точки
}; //end class Location