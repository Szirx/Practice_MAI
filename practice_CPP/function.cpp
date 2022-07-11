#include "function.h"

using namespace std;

bool Collision(Body* figure1, Point* figure2) {
	bool XColl = false;
	bool YColl = false;

	int f1_width = figure1->GetWidth();
	int f1_height = figure1->GetHeight();
	int f1_x = figure1->GetX1() - f1_width / 2;
	int f1_y = figure1->GetY1() - f1_height / 2;

	int f2_x = figure2->GetX1();
	int f2_y = figure2->GetY1();

	if ((f1_x + f1_width >= f2_x) && (f1_x <= f2_x)) XColl = true;
	if ((f1_y + f1_height >= f2_y) && (f1_y <= f2_y)) YColl = true;

	if (XColl && YColl) {
		std::cout << "\n!Collision!\n";
		return true;
	}
	return false;
}