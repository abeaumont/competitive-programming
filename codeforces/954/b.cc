// http://codeforces.com/contest/954/problem/B
#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int l = n / 2;
	int m = 1;
	for (int i = l; i < n; i++) {
		int j = 0;
		while (j < l && s[i+j] == s[j]) j++;
		m = max(m, j);
	}
	cout << n - m + 1 << endl;
}
