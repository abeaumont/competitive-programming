#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> iii;

iii a[100001];
iii b[100001];
ll d[100001];

int main() {
	int c;
	cin >> c;
	for (int t = 1; t <= c; t++) {
		ll n, x, l, s, p;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> l >> s >> p;
			a[i] = {x / s, (x + l) / s, p};
		}
		sort(a, a + n);
		b[0] = a[0];
		int j = 0;
		for (int i = 1; i < n; i++) {
			ll si, ei, pi, sj, ej, pj;
			tie(si, ei, pi) = a[i];
			tie(sj, ej, pj) = b[j];
			if (si == sj && ei == ej) b[j] = {sj, ej, pi + pj};
			else b[++j] = {si, ei, pi};
		}
		n = j + 1;
		d[n - 1] = get<2>(b[n - 1]);
		for (int i = n - 2; i >= 0; i--) {
			ll si, ei, pi;
			tie(si, ei, pi) = b[i];
			j = i + 1;
			for (; j < n; j++)
				if (get<0>(b[j]) > ei) break;
			if (j < n) d[i] = max(pi + d[j], d[i + 1]);
			else d[i] = max(pi, d[i + 1]);
		}
		cout << "Case #" << t << ": " << d[0] << endl;
	}
}
