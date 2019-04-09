#include <Windows.h>
#include <vector>
#include <iostream>
#include <sstream>
#pragma comment(lib, "Winmm")

using namespace std;

#define df_STRING_MAX_LENGTH 1000

/*-------------STANDARD-------------*/
void StringDivide(__in const WCHAR* pInStr, __out vector<wstring>& pOutTokens);

/*-----------STRINGSTREAM-----------*/
// External Function
void StringDivide_SS(__in const wstring& pInStr, __out vector<wstring>& pOutTokens);
// Internal Function 
// Conversion szFrom to szTo
void ReplaceWstring(__in const wstring& szSource, __out wstring& szDest, const wstring& strFrom, const wstring& strTo);
// Tokenizing using Stringstream
void wTokenize(__in const wstring& pInStr, __out vector<wstring>& pOutTokens);

__int64 GetQPTick();
void PrintResult(wstring szSubject, vector<wstring>& vPrintTokens);

void main()
{
	WCHAR wszInput[df_STRING_MAX_LENGTH];
	wstring wstrBuf;
	vector<wstring> vTokens;
	__int64 iBegin, iEnd;		// time check

	_wsetlocale(LC_ALL, L"kor");
	timeBeginPeriod(1);

	while (1)
	{
		wcout << "Input String (Max Length 1000) : ";
		// TODO : fgetws�� �Է¹��� ���ڿ��� wstring�� ���� �����ϴ� ����
		// 1. getline(cin, wszBuff);�� �ʹ� ����
		// 2. cin >> wszBuff;�� ' ', '\r\n', '\0'�� ������ �������� �Է¹����Ƿ� ' '�� �Է¹��� �� ����
		fgetws(wszInput, df_STRING_MAX_LENGTH, stdin);
		wstrBuf = wszInput;

		/*-------------STANDARD-------------*/
		iBegin = GetQPTick();
		StringDivide(wszInput, vTokens);
		iEnd = GetQPTick();

		PrintResult(L" - case 1", vTokens);
		wcout << endl << " (Elapsed Time : " << iEnd - iBegin << "ms)" << endl;
		vTokens.clear();

		/*-----------STRINGSTREAM-----------*/
		iBegin = GetQPTick();
		StringDivide_SS(wstrBuf, vTokens);
		iEnd = GetQPTick();

		PrintResult(L" - case 2", vTokens);
		wcout << endl << " (Elapsed Time : " << iEnd - iBegin << "ms)" << endl;
		vTokens.clear();
	}

	timeEndPeriod(1);
}

void StringDivide(const WCHAR* pInStr, vector<wstring>& pOutTokens)
{
	WCHAR wstrToken[df_STRING_MAX_LENGTH];
	int iPrePos = 0;
	int iCurPos = 0;

	// ó������ �����ڰ� �Էµ��� ���
	if (pInStr[0] == L' ' || pInStr[0] == L',' || pInStr[0] == L'.')
		iCurPos = 1;

	for (; iCurPos < df_STRING_MAX_LENGTH; ++iCurPos)
	{

		if (pInStr[iCurPos] == L' ' || pInStr[iCurPos] == L',' || pInStr[iCurPos] == L'.')
		{
			// �����ڰ� ���������� �Էµ��� ���
			if (pInStr[iCurPos - 1] == L' ' || pInStr[iCurPos - 1] == L',' || pInStr[iCurPos - 1] == L'.')
			{
				iPrePos = iCurPos + 1;
				continue;
			}

			wcsncpy_s(wstrToken, pInStr + iPrePos, iCurPos - iPrePos);
			pOutTokens.push_back(wstrToken);

			iPrePos = iCurPos + 1;
		}

		// NULL ���ڸ� ������ break
		if (pInStr[iCurPos] == L'\0')
		{
			wcsncpy_s(wstrToken, pInStr + iPrePos, (iCurPos - 1) - iPrePos);
			pOutTokens.push_back(wstrToken);
			break;
		}
	}
}

void StringDivide_SS(const wstring& pInStr, vector<wstring>& pOutTokens)
{
	wstring wstrOut = pInStr;
	ReplaceWstring(wstrOut, wstrOut, L",", L" "); // stringstream�� ' '�� �����ڷ� token�� ������ ������ ','�� ��ȯ ������ �ʿ�
	ReplaceWstring(wstrOut, wstrOut, L".", L" ");
	wTokenize(wstrOut, pOutTokens);
}

void ReplaceWstring(const wstring& szSource, wstring& szDest, const wstring& strFrom, const wstring& strTo)
{
	szDest = szSource;
	int iStart = 0;
	int iGap = strFrom.length() - strTo.length();
	while ((iStart = szDest.find(strFrom, iStart)) != string::npos) // find() ã�� ���ڿ��� ���� ��� string::npos ��ȯ
	{
		szDest.replace(iStart, strFrom.length(), strTo);
		iStart += strTo.length();
	}
}

void wTokenize(const wstring & pInStr, vector<wstring>& pOutTokens)
{
	wstringstream ss(pInStr);
	wstring wstrToken;
	while (ss >> wstrToken)
		pOutTokens.push_back(wstrToken);
}

__int64 GetQPTick()
{
	LARGE_INTEGER liTime;
	QueryPerformanceCounter(&liTime);
	return static_cast<__int64>(liTime.QuadPart);
}

void PrintResult(wstring szSubject, vector<wstring>& vPrintTokens)
{
	wcout << szSubject << ": ";
	for (auto it = vPrintTokens.begin(); it != vPrintTokens.end(); ++it)
		wcout << *it << " ";
}