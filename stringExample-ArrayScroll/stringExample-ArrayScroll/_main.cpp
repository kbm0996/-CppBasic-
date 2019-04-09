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

		// �� ���ڿ��� �Է¹��� ����
		if (wcscmp(szChat, L"\n") == 0)
		{
			PrintChatline(pChatLine);
			continue;
		}
		// ���� ����
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

	// pChatLine�� �� á�� ������ ������ ����
	if (pChatLine[df_CHATLINE_COUNT - 1] != NULL)
	{

		if (pChatLine[0] != NULL)	// pChatLine�� ���� �� ĭ�� �������� ����
		{
			free(pChatLine[0]);
			pChatLine[0] = NULL;
		}

		for (int i = 0; i < df_CHATLINE_COUNT - 1; ++i)	// pChatLine�� �ϳ��� �δ�
			pChatLine[i] = pChatLine[i + 1];

		if (pChatLine[df_CHATLINE_COUNT - 1] != NULL)	// pChatLine �� �� ĭ���� ä��� ���� ����
			pChatLine[df_CHATLINE_COUNT - 1] = NULL;
	}


	/* pChatLine�� df_CHATLINE_COUNT����ŭ ȭ�鿡 ǥ���ϱ� ���� ���� ����θ� ���� �������� ���� */
	for (int i = 0; i < df_CHATLINE_COUNT; ++i)		// pChatLine �� ĭ�� ã�� ���� ����
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