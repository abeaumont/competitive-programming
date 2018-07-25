// https://www.codechef.com/MARCH09/problems/A1
#include <iostream>

using namespace std;

int t, m, n, a[20];

bool f(int s, int i) {
	if (i == n) return s == m;
	return f(s, i + 1) || f(s + a[i], i + 1);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << (f(0, 0) ? "Yes\n" : "No\n");
	}
}
