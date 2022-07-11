#include "AcidCan.h"
#pragma once

AcidCan::AcidCan(int InitX1, int InitY1, int InitRadius):WateringCan(InitX1, InitY1, InitRadius) {
};

AcidCan::~AcidCan(void) {};


void AcidCan::Show(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Ellipse(hdc, X1 - 24 - 0.1 * Radius, Y1 - 22 - 0.1 * Radius, X1 + 18 + 0.1 * Radius, Y1 + 18 + 0.1 * Radius);
	MoveToEx(hdc, X1 + 34, Y1 + 18, NULL);
	LineTo(hdc, X1 + 80, Y1);
	MoveToEx(hdc, X1 + 34, Y1, NULL);
	LineTo(hdc, X1 + 80, Y1);
	Rectangle(hdc, X1, Y1, X1 + 35, Y1 + 36);

	DeleteObject(Pen);
}

void AcidCan::Hide(void)
{
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Ellipse(hdc, X1 - 24 - 0.1 * Radius, Y1 - 22 - 0.1 * Radius, X1 + 18 + 0.1 * Radius, Y1 + 18 + 0.1 * Radius);
	MoveToEx(hdc, X1 + 37, Y1 + 18, NULL);
	LineTo(hdc, X1 + 80, Y1);
	MoveToEx(hdc, X1 + 37, Y1, NULL);
	LineTo(hdc, X1 + 80, Y1);
	Rectangle(hdc, X1, Y1, X1 + 35, Y1 + 36);

	DeleteObject(Pen);
}