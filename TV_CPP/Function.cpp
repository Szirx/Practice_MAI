#include "Function.h"

using namespace std;

bool Collision(PlasmaTV* figure1, Remote* figure2) {
	bool XColl = false;
	bool YColl = false;

	int f1_width = figure1->GetWidth();
	int f1_height = figure1->GetHeight();
	int f1_x = figure1->GetX() - f1_width / 2;
	int f1_y = figure1->GetY() - f1_height / 2;

	int f2_width = figure2->GetWidth();
	int f2_height = figure2->GetHeight();
	int f2_x = figure2->GetX() - f2_width / 2;
	int f2_y = figure2->GetY() - f2_height / 2;

	if ((f1_x + f1_width >= f2_x) && (f1_x <= f2_x + f2_width)) XColl = true;
	if ((f1_y + f1_height >= f2_y) && (f1_y <= f2_y + f2_height)) YColl = true;

	if (XColl && YColl) {
		std::cout << "  !Collision!  ";
		return true;
	}
	return false;
}