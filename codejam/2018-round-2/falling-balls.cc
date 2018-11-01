// https://codejam.withgoogle.com/2018/challenges/0000000000007706/dashboard
#include <bits/stdc++.h>

using namespace std;

int a[101];
int b[101];
char e[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		int n;
		cin >> n;
		int c = 0;
		int m = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c += a[i];
			m = max(m, abs(c - (i + 1)));
			b[i] = 1;
		}
		m++;
		cout << "Case #" << T << ": ";
		if (c != n || a[0] == 0 || a[n - 1] == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << m << endl;
		for (int i = 0; i < m; i++) {
			c = 0;
			int d = 0;
			for (int j = 0; j < n; j++) e[j] = '.';
			for (int j = 0; j < n; j++) {
				c += b[j];
				d += a[j];
				if (c < d) {
					e[j + 1] = '/';
					b[j + 1]--;
					b[j]++;
					c++;
				}
				else if (c > d) {
					e[j] = '\\';
					b[j]--;
					b[j + 1]++;
					c--;
				}
			}
			for (int j = 0; j < n; j++) cout << e[j];
			cout << endl;
		}
	}
}
