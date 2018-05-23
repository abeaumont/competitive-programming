// https://www.hackerrank.com/challenges/stockmax
#include <iostream>

using namespace std;

typedef long long ll;

ll t, n, a[50000];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ll c = 0, p = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
			if (a[i] > p) p = a[i];
			else c += p - a[i];
		cout << c << endl;
	}
}
