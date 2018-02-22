// https://open.kattis.com/problems/settlers2
#include <iostream>

using namespace std;

const int SIZE = 200;
const int N = 20000;
int value[SIZE*2][SIZE*2];
int count[6] = {0, 0, 0, 0, 0, 0};
int cachev[N];

int smallest(int y, int x) {
	bool used[6];
	for (int i = 0; i < 6; i++) used[i] = false;
	used[value[y][x + 1]] = true;
	used[value[y + 1][x]] = true;
	used[value[y + 1][x - 1]] = true;
	used[value[y][x - 1]] = true;
	used[value[y - 1][x]] = true;
	used[value[y - 1][x + 1]] = true;
	int r = 0;
	int m = SIZE * SIZE;
	for (int i = 1; i < 6; i++) {
		if (!used[i] && count[i] < m) {
			r = i;
			m = count[i];
		}
	}
	count[r]++;
	return r;
}

int main() {
	for (int i = 0; i < SIZE*2; i++) for (int j = 0; j < SIZE*2; j++) value[i][j] = 0;
	for (int i = 0; i < N; i++) cachev[i] = 0;
	int c;
	cin >> c;
	int i = 0;
	int t = 0;
	int y = SIZE;
	int x = SIZE;
	value[y][x] = smallest(y, x);;
	cachev[t] = value[y][x];
	t++;
	for (int k = 0; k < c; k++) {
		int n;
		cin >> n;
		while (t < n) {
			for (int j = 1; j < i; j++) {
				y++;
				value[y][x] = smallest(y, x);
				cachev[t] = value[y][x];
				t++;
			}
			for (int j = 0; j < i; j++) {
				y++;
				x--;
				value[y][x] = smallest(y, x);;
				cachev[t] = value[y][x];
				t++;
			}
			for (int j = 0; j < i; j++) {
				x--;
				value[y][x] = smallest(y, x);;
				cachev[t] = value[y][x];
				t++;
			}
			for (int j = 0; j < i; j++) {
				y--;
				value[y][x] = smallest(y, x);;
				cachev[t] = value[y][x];
				t++;
			}
			for (int j = 0; j < i; j++) {
				y--;
				x++;
				value[y][x] = smallest(y, x);;
				cachev[t] = value[y][x];
				t++;
			}
			for (int j = 0; j <= i; j++) {
				x++;
				value[y][x] = smallest(y, x);;
				cachev[t] = value[y][x];
				t++;
			}
			i++;
		}
		cout << cachev[n - 1] << endl;
	}
}
