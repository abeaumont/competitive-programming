// https://open.kattis.com/problems/scrollingsign
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int k, w;
		cin >> k >> w;
		string s, t;
		cin >> s;
		int c = k;
		while (--w) {
			string t;
			cin >> t;
			int r = 0;
			for (int i = 0; i < k; i++) {
				bool ok = true;
				for (int j = 0; j < k - i; j++) {
					if (s[i + j] != t[j]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					r = k - i;
					break;
				}
			}
			c += k - r;
			swap(s, t);
		}
		cout << c << endl;
	}
}
