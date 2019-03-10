// http://codeforces.com/contest/935/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int c = 0;
	int x = 0;
	int y = 0;
	bool up = s[0] == 'U';
	if (up) y++;
	else x++;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'U') y++;
		else x++;
		if (up && x > y) {
			up = false;
			c++;
		} else if (!up && y > x) {
			up = true;
			c++;
		}
	}
	cout << c << endl;
}
