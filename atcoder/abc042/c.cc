// https://abc042.contest.atcoder.jp/tasks/arc058_a
#include <iostream>

using namespace std;

int main() {
	int n, d;
	bool ds[10];
	cin >> n >> d;
	for (int i = 0; i < 10; i++) ds[i] = false;
	for (int i = 0; i < d; i++) {
		int x;
		cin >> x;
		ds[x] = true;
	}
	while (true) {
		int x = n;
		bool ok = true;
		while (x > 0) {
			if (ds[x % 10]) {
				ok = false;
				break;
			}
			x /= 10;
		}
		if (ok) break;
		n++;
	}
	cout << n << endl;
}
