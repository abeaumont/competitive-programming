// https://www.codechef.com/JAN18/problems/PRTITION
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
	int t; cin >> t;
	while (t--) {
		int x, n; cin >> x >> n;
		ll sum = ll(n) * ll(n + 1) / 2 - x;
		if (n <= 3 || sum % 2) {
			cout << "impossible\n";
			continue;
		}
		sum /= 2;
		vi v(n + 1, 0);
		v[x] = 2;
		ll s2 = 0;
		int i = n;
		for (; i >= 0; i--) {
			if (i == x) continue;
			if (s2 + i > sum) break;
			s2 += i;
			v[i] = 1;
		}
		ll d = sum - s2;
		if (d != x) v[d] = 1;
		else if (d > 2) {
			v[d - 1] = 1;
			v[1] = 1;
		} else {
			v[i + 1] = 0;
			v[i] = 1;
			v[d + 1] = 1;
		}
		for (int i = 1; i <= n; i++) {
			cout << v[i];
		}
		cout << endl;
	}
}
