// https://open.kattis.com/problems/fridge
#include <iostream>

using namespace std;

int d[10];

int main() {
	string s;
	cin >> s;
	for (auto c : s) d[c - '0']++;
	int m = d[0] + 1;
	int k = 0;
	for (int i = 1; i < 10; i++) {
		if (d[i] < m) {
			m = d[i];
			k = i;
		}
	}
	if (k == 0) {
		cout << 1;
		m--;
	}
	for (int i = 0; i <= m; i++) cout << k;
	cout << endl;
}
