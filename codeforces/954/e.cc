// http://codeforces.com/contest/954/problem/E
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef tuple<ll, ll> ii;
typedef vector<ii> vii;

int main() {
	int n, t;
	cin >> n >> t;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vi b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	vii c(n);
	for (int i = 0; i < n; i++) c[i] = make_tuple(b[i], a[i]);
	sort(c.begin(), c.end());
	if (get<0>(c.front()) > t || get<0>(c.back()) < t) {
		cout << 0 << endl;
		return 0;
	}
	ll s1 = 0, t1 = 0, s2 = 0, t2 = 0, s3 = 0, t3 = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		tie(a, b) = c[i];
		if (b == t) {
			s3 += a * b;
			t3 += b;
		} else if (b < t) {
			s1 += a * b;
			t1 += b;
		} else {
			s2 += a * b;
			t2 += b;
		}
	}
	double x = s1 + s2 + s3;
	double y = t1 + t2 + t3;
	double tt = x / y;
	if (tt < t) {
		int i = 0;
		double x2 = x;
		double y2 = y;
		ll a, b;
		while (i < n) {
			tie(a, b) = c[i++];
			double tt2 = (x2 - a * b) / (y2 - b);
			if (tt2 >= t) break;
			x2 -= a * b;
			y2 -= b;
		}
		double z = (t * y2 - x2) / (t - a);
		y = y2 - z;
	} else if (tt > t) {
		int i = n - 1;
		double x2 = x;
		double y2 = y;
		ll a, b;
		while (i >= 0) {
			tie(a, b) = c[i--];
			double tt2 = (x2 - a * b) / (y2 - b);
			if (tt2 <= t) break;
			x2 -= a * b;
			y2 -= b;
		}
		double z = (t * y2 - x2) / (t - a);
		y = y2 - z;
	}
	cout << setprecision(10) << y << endl;
}
