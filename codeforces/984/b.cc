// http://codeforces.com/contest/984/problem/B
#include <bits/stdc++.h>

using namespace std;

int a[101][101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			char c = s[j];
			switch (c) {
			case '*':
				a[i][j] = -1;
				break;
			case '.':
				a[i][j] = 0;
				break;
			default:
				a[i][j] = c - '0';
			}
		}
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) continue;
			int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
			int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
			int c = 0;
			for (int k = 0; k < 8; k++) {
				int yy = i + y[k];
				int xx = j + x[k];
				if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
				c += a[yy][xx] == -1;
			}
			if (c != a[i][j]) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	cout << (ok ? "YES\n": "NO\n");
}
