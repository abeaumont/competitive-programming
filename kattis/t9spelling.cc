// https://open.kattis.com/problems/t9spelling
#include <iostream>

using namespace std;

typedef unsigned char u8;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	int a[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
	int b[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	for (int i = 0; i < t; i++) {
		cout << "Case #" << (i + 1) << ": ";
		getline(cin, s);
		u8 prev = 0;
		for (u8 c : s) {
			if (c == ' ') {
				if (prev == 0) cout << " ";
				prev = 0;
				cout << 0;
			} else {
				int d = a[c - 'a'];
				if (prev == d) cout << " ";
				prev = d;
				for (int j = 0; j < b[c - 'a']; j++) {
					cout << d;
				}
			}
		}
		cout << endl;
	}
}
