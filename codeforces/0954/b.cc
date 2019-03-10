// http://codeforces.com/contest/954/problem/B
#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int l = n / 2;
	for (int i = l; i >= 2; i--) {
		bool ok = true;
		for (int z = 0; z < i; z++) {
			if (s[z] != s[i + z]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << n - i + 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
}
