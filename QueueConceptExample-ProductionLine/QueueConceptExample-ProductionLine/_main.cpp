#include "Logic.h"

bool g_bExit;

void main()
{
	timeBeginPeriod(1);

	COORD	pos;		// 문자를 출력할 콘솔 위치
	pos.X = pos.Y = 0;

	while (!g_bExit)
	{
		// TODO: 깜빡거림 문제
		/// system("cls");	// system 명령어로 화면을 지우면 화면이 깜빡거리는 현상이 발생
		// 더블 버퍼링을 사용하여 해결해야하지만, 간단하게 콘솔의 특정 위치부터 다시 그리는 식으로 깜빡거림 현상 해결
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		Draw();
		Action();
		KeyProcess();

		Sleep(1);
	}

	timeEndPeriod(1);
}