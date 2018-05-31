// https://open.kattis.com/problems/applesack
#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int c = 0;
	while (n >= k) {
		int d = (n - 1) / k + 1;
		int e = (d - 1) * k;
		int f = (n - e - 1) / k + 1;
		n -= f * d;
		c += f;
	}
	c += n + 1;
	cout << c << endl;
}
