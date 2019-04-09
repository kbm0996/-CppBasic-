#include <Windows.h>
#include <cstdio>
#include <clocale>

#define df_CHATLINE_COUNT 10
#define df_CHATLEN_MAX 128

void InputChatline(const WCHAR *szChat, WCHAR ** pChatLine);
void PrintChatline(WCHAR ** pChatLine);

void main()
{
	_wsetlocale(LC_ALL, L"kor");

	WCHAR szChat[df_CHATLEN_MAX];
	WCHAR *pChatLine[df_CHATLINE_COUNT];
	memset(pChatLine, 0, sizeof(pChatLine));

	while (1)
	{
		wprintf(L"\nCHAT :: ");
		fgetws(szChat, df_CHATLEN_MAX, stdin);

		system("cls");

		// 빈 문자열은 입력받지 않음
		if (wcscmp(szChat, L"\n") == 0)
		{
			PrintChatline(pChatLine);
			continue;
		}
		// 종료 조건
		else if (wcscmp(szChat, L"exit\n") == 0)
			break;

		InputChatline(szChat, pChatLine);
		PrintChatline(pChatLine);
	}

	for (int i = 0; i < df_CHATLINE_COUNT; ++i)
	{
		if (pChatLine[i] != NULL)
			free(pChatLine[i]);
	}
}

void InputChatline(const WCHAR *szChat, WCHAR ** pChatLine)
{
	size_t iSize = wcslen(szChat) + 1;
	WCHAR *pBuff = (WCHAR*)malloc((iSize) * sizeof(WCHAR));
	wcscpy_s(pBuff, iSize, szChat);

	// pChatLine이 꽉 찼을 때부터 정렬을 시작
	if (pChatLine[df_CHATLINE_COUNT - 1] != NULL)
	{

		if (pChatLine[0] != NULL)	// pChatLine의 가장 윗 칸이 차있으면 제거
		{
			free(pChatLine[0]);
			pChatLine[0] = NULL;
		}

		for (int i = 0; i < df_CHATLINE_COUNT - 1; ++i)	// pChatLine을 하나씩 민다
			pChatLine[i] = pChatLine[i + 1];

		if (pChatLine[df_CHATLINE_COUNT - 1] != NULL)	// pChatLine 맨 밑 칸부터 채우기 위해 비운다
			pChatLine[df_CHATLINE_COUNT - 1] = NULL;
	}


	/* pChatLine을 df_CHATLINE_COUNT개만큼 화면에 표시하기 위해 버퍼 저장부를 정렬 다음으로 내림 */
	for (int i = 0; i < df_CHATLINE_COUNT; ++i)		// pChatLine 빈 칸을 찾아 버퍼 저장
	{
		if (pChatLine[i] == NULL)
		{
			pChatLine[i] = pBuff;
			break;
		}
	}
}

void PrintChatline(WCHAR ** pChatLine)
{
	for (int i = 0; i < df_CHATLINE_COUNT; ++i)
	{
		if (pChatLine[i] != NULL)
			wprintf(L"%02d # %s", i, pChatLine[i]);
	}
}