#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<set>
#include<Windows.h>
#include<queue>
#include<clocale>
#include<deque>

using namespace std;
using ll = long long;
const char* curr_locale = setlocale(LC_ALL, NULL);

void help() {
	setlocale(LC_ALL, "ru");
	system("cls");

	cout << "\n  1. ���� ����� ����� ������� ��� ����� �������, �� ��� ������� �� ���������������� (� ���� ������ ��������� �����)\n";
	cout << "\n  2. ���� ����� �� ����� ������� ��� ����� ����� ������ ������, �� ��� ������� �� �������� �������\n";
	cout << "\n  3. ���� ������ ��� ����� ����� ����� ���� �������, �� � ��� ���������� �������� (�� ������ �������� �����)\n";
	cout << "\n  4. ���� �� ��������� �� ���� �� ������������� ���� �������, ��������� ������ �� ����������\n";

	cout << "\n\n  ����� ��������� � ���� ������ ������� ���� ������� �� ������� P";
	setlocale(LC_ALL, "C");
	char c = _getch();
	if (c == 'P') {
		return;
	}
}

int main() {

	HMODULE hDLLGameVer1		= LoadLibraryA("GameVer1.dll");
	HMODULE hDllGameVer2		= LoadLibraryA("GameVer2.dll");
	HMODULE hDllGameVerStandart = LoadLibraryA("GameVerStandart.dll");

	if (hDLLGameVer1 == NULL || hDllGameVer2 == NULL || hDllGameVerStandart == NULL) return -1;

	void(*GameVer1)()			= NULL;
	void(*GameVer2)()			= NULL;
	void(*GameVerStandart)()	= NULL;

	(FARPROC&)GameVer1			= GetProcAddress(hDLLGameVer1, "GameVer1");
	(FARPROC&)GameVer2			= GetProcAddress(hDllGameVer2, "GameVer2");
	(FARPROC&)GameVerStandart	= GetProcAddress(hDllGameVerStandart, "GameVerStandart");

	while (1) {
		system("cls");
		setlocale(LC_ALL, "ru");
		cout << "�������� ����� ����\n1. ����������� �����\n2. ������\n3. �����������\n\n4.�������";
		char c = _getch();
		setlocale(LC_ALL, curr_locale);
		system("cls");

		switch (c) {
		case '1':
			GameVerStandart();
			break;
		case '2':
			GameVer1();
			break;
		case '3':
			GameVer2();
			break;
		case '4':
			help();
			break;
		}
	}
	return 0;
}