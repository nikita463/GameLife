#include <Windows.h>
#include <vector>
#include <conio.h>
#include <iostream>
#include <clocale>
#define EXPORT _declspec(dllexport)

using namespace std;
using ll = long long;
const char* curr_locale = setlocale(LC_ALL, NULL);

int x, y;
bool f = true;
vector <vector <bool>> a(100, vector<bool>(100, false));


void state(int cnt3) {

	cout << "step " << cnt3 << '\n';

	cout << char(218);
	for (int i = 0; i < y * 2 + 1; ++i) {
		cout << char(196);
	}
	cout << char(191) << '\n';

	for (int i = 0; i < x; ++i) {
		cout << char(179);
		for (int j = 0; j < y; ++j) {
			if (j == y - 1) {
				if (a[i][j] == true) {
					cout << " # ";
				}
				else {
					cout << " . ";
				}
			}
			else {
				if (a[i][j] == true) {
					cout << " #";
				}
				else {
					cout << " .";
				}
			}
		}
		cout << char(179) << '\n';
	}

	cout << char(192);
	for (int i = 0; i < y * 2 + 1; ++i) {
		cout << char(196);
	}
	cout << char(217);

	cout << "\n\n";
};

int count(int i, int j) {
	int cnt = 0;
	for (int x2 = i - 1; x2 <= i + 1; ++x2) {
		if (x2 < 0 || x2 >= x) {
			continue;
		}
		for (int y2 = j - 1; y2 <= j + 1; ++y2) {
			if (y2 < 0 || y2 >= y) {
				continue;
			}
			if (x2 == i && y2 == j) {
				continue;
			}
			if (a[x2][y2] == true) {
				cnt++;
			}
		}
	}
	return cnt;
};


void step() {
	vector <vector <bool>> temp(x, vector<bool>(y, false));

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			int tmp4 = count(i, j);
			if (a[i][j] == false) {
				if (tmp4 == 3) {
					temp[i][j] = true;
				}
				else {
					temp[i][j] = false;
				}
			}
			else {
				if (tmp4 < 2 || tmp4 > 3) {
					temp[i][j] = false;
				}
				else {
					temp[i][j] = true;
				}
			}
		}
	}
	a = temp;
};

int EXPORT main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setlocale(LC_ALL, "ru");

	cout << "Выберите стандартную конфигурацию, или создайте свою\n1. Чеширский кот\n2. Тетрамино\n3. Своя конфигурация\nНапишите номер конфигурации: ";
	char c = _getch();
	switch (c) {
	case '1':
		x = 25;
		y = 25;
		a[11][12] = true;
		a[11][15] = true;
		a[12][12] = true;
		a[12][13] = true;
		a[12][14] = true;
		a[12][15] = true;
		a[13][11] = true;
		a[13][16] = true;
		a[14][11] = true;
		a[14][13] = true;
		a[14][14] = true;
		a[14][16] = true;
		a[15][11] = true;
		a[15][16] = true;
		a[16][12] = true;
		a[16][13] = true;
		a[16][14] = true;
		a[16][15] = true;
		break;
	case '2':
		x = 25;
		y = 25;
		a[10][9] = true;
		a[10][10] = true;
		a[10][11] = true;
		a[9][10] = true;
		break;
	case '3':
		system("cls");
		cout << "Введите размеры поля\n";
		cin >> x >> y;
		system("cls");

		cout << "Введите начальное расположение живых клеток в формате x y\nКогда введёте, нажмите Ctrl+Z и Enter\n";
		int t1, t2;
		while (cin >> t1 >> t2) {
			a[t1 - 1][t2 - 1] = true;
		}
		cin.clear();
		break;
	}

	system("cls");

	setlocale(LC_ALL, "C");

	string tmp2;
	int cnt3 = 0;
	while (true) {
		system("cls");
		cnt3++;
		state(cnt3);
		step();


		Sleep(500);
	}
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

