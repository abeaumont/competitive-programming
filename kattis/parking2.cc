// https://open.kattis.com/problems/parking2
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m = 100;
		int M = -1;
		while (n--) {
			int x;
			cin >> x;
			m = min(m, x);
			M = max(M, x);
		}
		cout << (M - m) * 2 << endl;
	}
}
