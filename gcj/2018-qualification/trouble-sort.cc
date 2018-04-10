// https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
#include <algorithm>
#include <iostream>

using namespace std;

int a[50001];
int b[50001];

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			if (i % 2) cin >> b[i / 2];
			else cin >> a[i / 2];
		}
		int an = (n - 1) / 2 + 1;
		int bn = n - an;
		sort(a, a + an);
		sort(b, b + bn);
		bool ok = true;
		int k = n;
		for (int i = 0; i < n - 1; i++) {
			if (i % 2) {
				if (b[i / 2] > a[i / 2 + 1]) {
					ok = false;
					k = i;
					break;
				}
			} else if (a[i / 2] > b[i / 2]) {
				ok = false;
				k = i;
				break;
			}
		}
		cout << "Case #" << t << ": ";
		if (ok) cout << "OK\n";
		else cout << k << endl;
	}
}
