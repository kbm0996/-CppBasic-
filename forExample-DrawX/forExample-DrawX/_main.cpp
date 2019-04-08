#include <cstdio>
#include <clocale>
#include <Windows.h>
#pragma comment(lib,"winmm")

void draw_x(int iLength);
void main()
{
	timeBeginPeriod(1);
	_wsetlocale(LC_ALL, L"kor");

	int iLength = 1;

	while (iLength != 0)
	{
		wprintf(L"Input Length of Side ( 0 = End) : ");
		scanf_s("%d", &iLength);

		draw_x(iLength);
	}

	timeEndPeriod(1);
}

void draw_x(int iLength)
{
	for (int iHeight = 0; iHeight < iLength; ++iHeight)
	{
		for (int iWidth = 0; iWidth < iLength; ++iWidth)
		{
			if (iWidth == iHeight)
			{
				wprintf(L"■");
			}
			else if (iWidth == iLength - 1 - iHeight)
			{
				wprintf(L"■");
			}
			else
			{
				wprintf(L"□");
			}
		}
		wprintf(L"\n");
	}
}