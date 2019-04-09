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
				szNotice = "## 생산 요청 불가";

		if (iKey == '2')
			g_bExit = false;

		/// 너무 민감... WinAPI 메시지 받을때 WM_KEYDOWN 때나 쓰자
		//if (GetAsyncKeyState(0x31) & 0x8000)
		//	if (!Enqueue(GetTickCount64()))
		//		szNotice = "## 생산 요청 불가";
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
			szNotice = "## 유닛 생성 완료";
			system("cls");
		}
}

void Draw()
{
	int iPos = Front;
	unsigned long long llOut;
	printf("[ 1 : 유닛 생산 요청 / 2 : 종료 ]\n");
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