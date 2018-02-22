// https://open.kattis.com/problems/volim
#include <iostream>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	int s = 0;
	k--;
	for (int i = 0; i < n; i++) {
		int t;
		char z;
		cin >> t >> z;
		s += t;
		if (s > 210) break;
		if (z == 'T') k = (k + 1) % 8;
	}
	cout << k + 1 << endl;
}
