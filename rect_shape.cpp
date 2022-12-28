#include "rect_shape.h"

void RectShape::Show(HDC hdc)
{
	int xStart = xs2 - (2 * (xs2 - xs1));
	int yStart = ys2 - (2 * (ys2 - ys1));

	MoveToEx(hdc, xStart, yStart, NULL);
	LineTo(hdc, xs2, yStart);
	LineTo(hdc, xs2, ys2);
	LineTo(hdc, xStart, ys2);
	LineTo(hdc, xStart, yStart);
}

void RectShape::DrawRubber(HWND hWnd)
{
	HDC hdc;
	HPEN hPenOld, hPen;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	int xStart = xs2 - (2 * (xs2 - xs1));
	int yStart = ys2 - (2 * (ys2 - ys1));

	MoveToEx(hdc, xStart, yStart, NULL);
	LineTo(hdc, xs2, yStart);
	LineTo(hdc, xs2, ys2);
	LineTo(hdc, xStart, ys2);
	LineTo(hdc, xStart, yStart);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

Shape* RectShape::copyShape()
{
	return new RectShape;
}

LPCTSTR RectShape::setWindowText()
{
	return  L"Прямокутник";
}