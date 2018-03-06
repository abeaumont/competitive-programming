// https://www.codechef.com/MARCH18A/problems/MINVOTE
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vll a(n + 1, 0);
		vi s(n);
		vi e(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i + 1];
			a[i + 1] += a[i];
		}
		for (int i = 1; i <= n; i++) {
			int v = a[i] - a[i - 1];
			s[i-1] = lower_bound(a.begin(), a.end(), a[i - 1] - v) - a.begin() - 1;
			e[i-1] = upper_bound(a.begin(), a.end(), a[i] + v) - a.begin();
		}
		sort(s.begin(), s.end());
		sort(e.begin(), e.end());
		int c = 0;
		int i = 0;
		int j = 0;
		while (i < n && s[i] <= 0) {
			c++;
			i++;
		}
		for (int k = 0; k < n; k++) {
			while (i < n && s[i] == k) { c++; i++; }
			while (j < n && e[j] == k) { c--; j++; }
			cout << c - 1;
			if (k < n - 1) cout << " ";
		}
		cout << endl;
	}
}
