// https://open.kattis.com/problems/racingalphabet
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	int a[128];
	a[' '] = 0;
	a['\''] = 1;
	for (int i = 0; i < 26; i++) a['A' + i] = i + 2;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		int c = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			int d = (a[s[i]] - a[s[i + 1]]) % 28;
			if (d < 0) d += 28;
			if (d > 14) d = 28 - d;
			c += d;
		}
		cout << setprecision(10) << s.size() + (c * 4 * M_PI / 28) << endl;
	}
}
