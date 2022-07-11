#include <windows.h>
#include "AbsBody.h"
#include "Point.h"

//конструктор
AbsBody::AbsBody(int InitX1, int InitY1) : Point(InitX1, InitY1)
{
	X2 = X1 + width;
	Y2 = Y1 + heigth;
}// end AbsBody::AbsBody()