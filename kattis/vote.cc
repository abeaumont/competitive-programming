// https://open.kattis.com/problems/vote
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int s = 0;
		int m = 0;
		int c = 0;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			s += x;
			if (x > m) {
				m = x;
				c = j + 1;
			} else if (x == m) {
				c = 0;
			}
		}
		if (!c) cout << "no winner\n";
		else if (m * 2 > s) cout << "majority winner " << c << endl;
		else cout << "minority winner " << c << endl;
	}
}
