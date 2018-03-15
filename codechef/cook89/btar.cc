// https://www.codechef.com/COOK89/problems/BTAR
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ll x1 = 0;
		ll x2 = 0;
		ll x3 = 0;
		ll c = 0;
		for (int j = 0; j < n; j++) {
			ll x;
			cin >> x;
			switch (x % 4) {
			case 1:
				x1++;
				break;
			case 2:
				x2++;
				break;
			case 3:
				x3++;
				break;
			}
		}
		c += x2 / 2;
		c += min(x1, x3);
		x3 = x1 > x3 ? x1 - x3 : x3 - x1;
		if (x2 % 2) {
			c += 2;
			x3 -= 2;
		}
		if (x3 < 0 || x3 % 4) {
			cout << -1 << endl;
			continue;
		}
		c += (x3 / 4) * 3;
		cout << c << endl;
	}
}
