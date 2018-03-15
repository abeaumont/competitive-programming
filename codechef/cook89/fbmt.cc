// https://www.codechef.com/COOK89/problems/FBMT
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s, s1, s2;
		int c1 = 0;
		int c2 = 0;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s;
			if (!c1) {
				s1 = s;
				c1++;
			} else if (s == s1) c1++;
			else if (!c2) {
				s2 = s;
				c2++;
			} else c2++;
		}
		if (c1 == c2) cout << "Draw\n";
		else if (c1 < c2) cout << s2 << endl;
		else cout << s1 << endl;
	}
}
