#pragma once
#include "shape.h"
class PointPlusShape : virtual public Shape {
public:
	void Show(HDC);
	void DrawRubber(HWND);
	Shape* copyShape();
	LPCTSTR setWindowText();
};