// https://open.kattis.com/problems/pripreme
#include <iostream>

using namespace std;

int main() {
	long long n, x, m = 0, s = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		m = max(m, x);
		s += x;
	}
	cout << max(2 * m, s) << endl;
}
