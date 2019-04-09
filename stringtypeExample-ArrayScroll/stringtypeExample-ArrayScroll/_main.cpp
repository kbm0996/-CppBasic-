#include <Windows.h>
#include <iostream>
#include <clocale>
#include <string>
#include <list>

using namespace std;

#define df_CHATLINE_COUNT 10
#define df_CHATLEN_MAX 128

void InputChatline(const wstring strChat, list<wstring>& pChatLine);
void PrintChatline(list<wstring>& pChatLine);

void main()
{
	_wsetlocale(LC_ALL, L"kor");

	WCHAR szChat[df_CHATLEN_MAX];
	wstring strChat;
	list<wstring> pChatLine;

	while (1)
	{
		wcout << "\nCHAT :: ";
		fgetws(szChat, df_CHATLEN_MAX, stdin);
		strChat = szChat;

		system("cls");

		if (strChat.size() == 1)
		{
			PrintChatline(pChatLine);
			continue;
		}
		else if (strChat == L"exit\n")
			break;

		InputChatline(strChat, pChatLine);
		PrintChatline(pChatLine);

	}

	pChatLine.clear();
}

void InputChatline(const wstring strChat, list<wstring>& pChatLine)
{
	pChatLine.push_back(strChat);
	if (pChatLine.size() > df_CHATLINE_COUNT)
	{
		pChatLine.pop_front();
	}
}

void PrintChatline(list<wstring>& pChatLine)
{
	int i = 0;
	for (list<wstring>::iterator iter = pChatLine.begin(); iter != pChatLine.end(); ++iter)
	{
		wcout.width(2);
		wcout.fill('0');
		wcout << i++ << " # " << *iter;
		//wprintf(L"%02d # %s", i++, *iter);
	}

}