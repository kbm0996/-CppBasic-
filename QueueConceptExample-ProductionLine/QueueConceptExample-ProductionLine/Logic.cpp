#include "Logic.h"
#include "Queue.h"

extern long long Queue[MAX];

extern bool g_bExit;
extern int Front;

char* szNotice = "";

void KeyProcess()
{
	if (_kbhit())
	{
		int iKey = _getch();
		if (iKey == '1')
			if (!Enqueue(GetTickCount64()))
				szNotice = "## ���� ��û �Ұ�";

		if (iKey == '2')
			g_bExit = false;

		/// �ʹ� �ΰ�... WinAPI �޽��� ������ WM_KEYDOWN ���� ����
		//if (GetAsyncKeyState(0x31) & 0x8000)
		//	if (!Enqueue(GetTickCount64()))
		//		szNotice = "## ���� ��û �Ұ�";
		//if (GetAsyncKeyState(0x32) & 0x8000)
		//	g_bExit = false;
	}
}

void Action()
{
	unsigned long long llFront;
	Peek(Front, &llFront);
	if ((GetTickCount64() - llFront) / 100 > 100)
		if (Dequeue())
		{
			szNotice = "## ���� ���� �Ϸ�";
			system("cls");
		}
}

void Draw()
{
	int iPos = Front;
	unsigned long long llOut;
	printf("[ 1 : ���� ���� ��û / 2 : ���� ]\n");
	printf("\n-- CONTROLL TOWER UNIT CREATE --\n");
	printf("\n#---------------------------------------------------------------\n");
	while (Peek(iPos % MAX, &llOut))
	{
		printf(" Progress:%lld %% |", min((GetTickCount64() - llOut) / 100, 100));
		iPos++;
	}
	printf("\n#---------------------------------------------------------------\n\n");
	printf(szNotice);

	szNotice = "";
}