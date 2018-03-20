// https://www.codechef.com/JAN18/problems/KCON
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll maxsum(const vi& v, int i, int j) {
	if (i == j) return v[i] ;
	int k = (i + j - 1) / 2;
	ll a = maxsum(v, i, k);
	ll b = maxsum(v, k + 1, j);
	ll l = -10000000;
	ll r = -10000000;
	ll s = 0;
	for (int m = k; m >= i; m--) {
		s += v[m];
		l = max(l, s); 
	}
	s = 0;
	for (int m = k + 1; m <= j; m++) {
		s += v[m];
		r = max(r, s); 
	}
	return max(max(a, b), l + r);
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		vi v(n);
		ll s = 0;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			s += v[j];
		}
		ll s2 = maxsum(v, 0, n - 1);
		if (k == 1) {
			cout << s2 << endl;
			continue;
		}
		ll l = -10000000;
		ll r = -10000000;
		s = 0;
		for (int j = n - 1; j >= 0; j--) {
			s += v[j];
			l = max(l, s); 
		}
		s = 0;
		for (int j = 0; j < n; j++) {
			s += v[j];
			r = max(r, s); 
		}
		ll s3 = l + r;
		cout << max(max(s2, s * (k - 2) + s3), s3) << endl;
	}
}
