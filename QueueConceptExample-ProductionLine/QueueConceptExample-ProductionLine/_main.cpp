#include "Logic.h"

bool g_bExit;

void main()
{
	timeBeginPeriod(1);

	COORD	pos;		// ���ڸ� ����� �ܼ� ��ġ
	pos.X = pos.Y = 0;

	while (!g_bExit)
	{
		// TODO: �����Ÿ� ����
		/// system("cls");	// system ��ɾ�� ȭ���� ����� ȭ���� �����Ÿ��� ������ �߻�
		// ���� ���۸��� ����Ͽ� �ذ��ؾ�������, �����ϰ� �ܼ��� Ư�� ��ġ���� �ٽ� �׸��� ������ �����Ÿ� ���� �ذ�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		Draw();
		Action();
		KeyProcess();

		Sleep(1);
	}

	timeEndPeriod(1);
}