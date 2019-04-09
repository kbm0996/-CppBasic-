#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <locale>

#define df_STRING_MAX_LENGTH 1000
#define df_WORD_CNT 13

#ifndef TEST
#define TEST_PRINT(A) {}
#else
#define TEST_PRINT(A) wprintf(L"%s \n", A)
#endif

WCHAR g_Dic[df_WORD_CNT][2][20] =
{
	{ L"i",L"나" },{ L"you",L"너" },{ L"like",L"좋아한다" },{ L"love",L"사랑한다" },{ L"hate", L"증오한다" },
	{ L"am",L"은/는" },{ L"are", L"은/는" },{ L"is", L"은/는" },{ L"she", L"그녀" },{ L"he", L"그" },{ L"boy", L"소년" },{ L"a",L"" },{ L"an",L"" }
};


WCHAR g_Buff[df_STRING_MAX_LENGTH / 2][df_STRING_MAX_LENGTH];


void StringDivide(WCHAR* pInStr);
void StringConverse(WCHAR* pInStr, WCHAR* pOutStr);

void main()
{
	_wsetlocale(LC_ALL, L"kor");

	WCHAR wszInput[df_STRING_MAX_LENGTH];
	WCHAR wszOutput[df_STRING_MAX_LENGTH];

	ZeroMemory(wszInput, sizeof(wszInput));
	ZeroMemory(wszOutput, sizeof(wszOutput));

	// INPUT
	wprintf(L"Input String : ");
	fgetws(wszInput, df_STRING_MAX_LENGTH, stdin);

	// TODO: 문자열을 소문자로 변환
	_wcslwr_s(wszInput);

	StringDivide(wszInput);

	for (int i = 0; i < df_STRING_MAX_LENGTH / 2; ++i)
	{
		if (wcscmp(g_Buff[i], L"\0") != 0)
			StringConverse(g_Buff[i], wszOutput);
	}


	wprintf(L"Input String : %s\n", wszOutput);

	system("pause");
}

void StringDivide(WCHAR* pInStr)
{
	int iPrePos = 0;
	int iCurPos = 0;
	int iArrayPos = 0;

	// 처음부터 구분자가 입력됐을 경우
	if (pInStr[0] == L' ')
		iCurPos = 1;

	for (; iCurPos < df_STRING_MAX_LENGTH; ++iCurPos)
	{
		if (pInStr[iCurPos] == L' ')
		{
			// 구분자가 연속적으로 입력됐을 경우
			if (pInStr[iCurPos - 1] == L' ')
			{
				iPrePos = iCurPos + 1;
				continue;
			}

			wcsncpy_s(g_Buff[iArrayPos++], pInStr + iPrePos, iCurPos - iPrePos);
			TEST_PRINT(g_Buff[iArrayPos - 1]);

			iPrePos = iCurPos + 1;
		}

		// NULL 문자를 만나면 break
		if (pInStr[iCurPos] == L'\0')
		{
			wcsncpy_s(g_Buff[iArrayPos++], pInStr + iPrePos, (iCurPos - 1) - iPrePos);
			TEST_PRINT(g_Buff[iArrayPos - 1]);
			break;
		}
	}
}

void StringConverse(WCHAR *pInStr, WCHAR *pOutStr)
{
	for (int j = 0; j < df_WORD_CNT; ++j)
	{
		if (wcscmp(pInStr, g_Dic[j][0]) == 0)
		{
			wcscat_s(pOutStr, df_STRING_MAX_LENGTH, g_Dic[j][1]);
			wcscat_s(pOutStr, df_STRING_MAX_LENGTH, L" ");
			return;
		}
	}
	wcscat_s(pOutStr, df_STRING_MAX_LENGTH, pInStr);
	wcscat_s(pOutStr, df_STRING_MAX_LENGTH, L" ");
}