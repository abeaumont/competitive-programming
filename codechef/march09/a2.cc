// https://www.codechef.com/MARCH09/problems/A2
#include <iostream>

using namespace std;

typedef long long ll;

ll n, t, a[1000001];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ll k = 1;
		for (int i = 0; i < n; i++) {
			if (k < 0 || k > 1000000LL * (n - i)) break;
			k -= a[i];
			k *= 2;
		}
		cout << (k ? "No\n" : "Yes\n");
	}
}
