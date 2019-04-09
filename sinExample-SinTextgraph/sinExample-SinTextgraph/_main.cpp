#include <cmath>
#include <iostream>
#include <Windows.h>
#pragma comment(lib,"winmm")

using namespace std;

#define df_PI 3.14159265359

void draw_singraph(int iMaxAngle, int iInterval);
void main()
{
	timeBeginPeriod(1);
	_wsetlocale(LC_ALL, L"kor");

	int iInterval;

	printf("Input Singraph Interval : ");
	scanf_s("%d", &iInterval);
	if (iInterval == 0)
		iInterval = 10;

	while (1)
	{
		draw_singraph(360, iInterval);
		Sleep(1);
	}

	timeEndPeriod(1);
}

void draw_singraph(int iMaxAngle, int iInterval)
{
	double dRadian = 0;
	double dSin = 0;

	for (int i = 0; i < iMaxAngle; i += iInterval)
	{
		dRadian = i * df_PI / 180;	// Radian Formular
		dSin = sin(dRadian);

		wprintf(L"sin(%3d) = %+.3f", i, dSin);

		// Drawing Graph
		for (int j = -13; j < dSin * 10; ++j) // Initial Value = Blank Space
			wprintf(L" ");
		wprintf(L"войм\n");

		Sleep(100);
	}
}