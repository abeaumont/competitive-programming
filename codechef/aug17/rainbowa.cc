// https://www.codechef.com/AUG17/problems/RAINBOWA
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vi xs(n);
		for (int j = 0; j < n; j++) {
			cin >> xs[j];
		};
		bool ok = true;
		int current = 0;
		int j = 0;
		int k = n - 1;
		while (j < k) {
			if (xs[j] != xs[k]) {
				ok = false;
				break;
			}
			if (xs[j] < 1 || xs[j] > 7) {
				ok = false;
				break;
			}
			if (xs[j] != current && xs[j] != current + 1) {
				ok = false;
				break;
			}
			current = xs[j];
			j++;
			k--;
		}
		if (xs[n/2] != 7) ok = false;
		cout << (ok ? "yes" : "no") << endl;
	}
}
