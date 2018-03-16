// https://open.kattis.com/problems/doorman
#include <iostream>

using namespace std;

int main() {
	int n, w = 0, m = 0;
	string s;
	cin >> n >> s;
	int i = 0;
	while (i < s.size()) {
		if (s[i] == 'M') {
			if (m - w == n) {
				if (i < s.size() - 1 && s[i] != s[i + 1]) swap(s[i], s[i + 1]);
				else break;
			} else {
				m++;
				i++;
			}
		} else {
			if (w - m == n) {
				if (i < s.size() - 1 && s[i] != s[i + 1]) swap(s[i], s[i + 1]);
				else break;
			} else {
				w++;
				i++;
			}
		}
	}
	cout << m + w << endl;
}
