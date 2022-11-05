#include <Windows.h>
#include <vector>
#include <iostream>
#include <clocale>
#include <conio.h>
#define EXPORT __declspec(dllexport)

using namespace std;
using ll = long long;
const char* curr_locale = setlocale(LC_ALL, NULL);

int x, y;
bool f = true;
vector <vector <pair <bool, int>>> a(100, vector<pair <bool, int>>(100, { false, 0 }));


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
				if (a[i][j].first == true) {
					cout << " # ";
				}
				else {
					cout << " . ";
				}
			}
			else {
				if (a[i][j].first == true) {
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
			if (a[x2][y2].first == true) {
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
			if (a[i][j].second == 0) {
				int tmp4 = count(i, j);
				if (a[i][j].first == false) {
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
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (a[i][j].second == 0) {
				a[i][j].first = temp[i][j];
			}
		}
	}
};

void step2(int i, int j) {

	if (a[i][j].second == 0) {
		int tmp4 = count(i, j);
		if (a[i][j].first == false) {
			if (tmp4 == 3) {
				a[i][j].first = true;
			}
			else {
				a[i][j].first = false;
			}
		}
		else {
			if (tmp4 < 2 || tmp4 > 3) {
				a[i][j].first = false;
			}
			else {
				a[i][j].first = true;
			}
		}
	}
};

void state2(int cnt3, int i1, int j1) {

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
				if (a[i][j].first == true) {
					if (i == i1 && j == j1) {
						cout << " @ ";
					}
					else {
						cout << " # ";
					}
				}
				else {
					cout << " . ";
				}
			}
			else {
				if (a[i][j].first == true) {
					if (i == i1 && j == j1) {
						cout << " @";
					}
					else {
						cout << " #";
					}
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

void sleep(int cnt3) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (a[i][j].first && a[i][j].second == 0) {
				state2(cnt3, i, j);

				setlocale(LC_ALL, "ru");
				cout << "Введите, через сколько шагов выделенная клетка разморозится: ";
				setlocale(LC_ALL, "C");

				int delay;
				cin >> delay;
				a[i][j].second = delay;
			}
		}
	}
}

void Delay() {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (a[i][j].second != 0) {
				a[i][j].second--;
				step2(i, j);
			}
		}
	}
}

void EXPORT mainGame() {
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
		a[11][12].first = true;
		a[11][15].first = true;
		a[12][12].first = true;
		a[12][13].first = true;
		a[12][14].first = true;
		a[12][15].first = true;
		a[13][11].first = true;
		a[13][16].first = true;
		a[14][11].first = true;
		a[14][13].first = true;
		a[14][14].first = true;
		a[14][16].first = true;
		a[15][11].first = true;
		a[15][16].first = true;
		a[16][12].first = true;
		a[16][13].first = true;
		a[16][14].first = true;
		a[16][15].first = true;
		break;
	case '2':
		x = 25;
		y = 25;
		a[10][9].first = true;
		a[10][10].first = true;
		a[10][11].first = true;
		a[9][10].first = true;
		break;
	case '3':
		system("cls");
		cout << "Введите размеры поля\n";
		cin >> x >> y;
		system("cls");

		cout << "Введите начальное расположение живых клеток в формате x y\nКогда введёте, нажмите Ctrl+Z и Enter\n";
		int t1, t2;
		while (cin >> t1 >> t2) {
			a[t1 - 1][t2 - 1].first = true;
		}
		cin.clear();
		break;
	}

	setlocale(LC_ALL, "C");

	string tmp2;
	int cnt3 = 0;
	while (true) {
		system("cls");
		cnt3++;
		sleep(cnt3);
		system("cls");
		state(cnt3);
		step();


		Sleep(1000);
		Delay();
	}
}




BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

