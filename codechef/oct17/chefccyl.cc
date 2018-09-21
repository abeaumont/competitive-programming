// https://www.codechef.com/OCT17/problems/CHEFCCYL/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, q;
		cin >> n >> q;
		vvi c(n);
		for (int j = 0; j < n; j++) {
			int l;
			cin >> l;
			c[j] = vi(l+1, 0);
			for (int k = 1; k < l+1; k++) {
				int m;
				cin >> m;
				c[j][k] = m;
				if (k > 0) c[j][k] += c[j][k - 1];
			}
		}
		vi s(n);
		vi d(n);
		vi w(n);
		vll prefix(n, 0);
		for (int j = 0; j < n; j++) {
			cin >> s[j] >> d[(j + 1) % n] >> w[j];
			d[(j + 1) % n]--;
			s[j]--;
			if (j > 0) {
				int a = min(s[j], d[j]);
				int b = max(s[j], d[j]);
				int d1 = c[j][b] - c[j][a];
				int d2 = c[j][c[j].size() - 1] - d1;
				prefix[j] = prefix[j - 1] + w[j - 1] + min(d1, d2);
			}
		}
		int a = min(s[0], d[0]);
		int b = max(s[0], d[0]);
		int d1 = c[0][b] - c[0][a];
		int d2 = c[0][c[0].size() - 1] - d1;
		prefix[0] = w[n - 1] + min(d1, d2);
		for (int j = 1; j < n; j++) prefix[j] += prefix[0];
		for (int j = 0; j < q; j++) {
			int v1, c1, v2, c2, a, b, va, vb;
			cin >> v1 >> c1 >> v2 >> c2;
			v1--; c1--; v2--; c2--;
			if (c1 < c2) {
				a = c1;
				b = c2;
				va = v1;
				vb = v2;
			} else {
				a = c2;
				b = c1;
				va = v2;
				vb = v1;
			}
			int a1 = min(s[a], va);
			int b1 = max(s[a], va);
			d1 = c[a][b1] - c[a][a1];
			d2 = c[a][c[a].size() - 1] - d1;
			int ds = min(d1, d2);
			int a2 = min(d[b], vb);
			int b2 = max(d[b], vb);
			d1 = c[b][b2] - c[b][a2];
			d2 = c[b][c[b].size() - 1] - d1;
			int dd = min(d1, d2);
			ll p = prefix[b - 1] - prefix[a];
			ll r1 = p + w[b - 1] + ds + dd;

			a1 = min(s[b], vb);
			b1 = max(s[b], vb);
			d1 = c[b][b1] - c[b][a1];
			d2 = c[b][c[b].size() - 1] - d1;
			ds = min(d1, d2);
			a2 = min(d[a], va);
			b2 = max(d[a], va);
			d1 = c[a][b2] - c[a][a2];
			d2 = c[a][c[a].size() - 1] - d1;
			dd = min(d1, d2);
			p = prefix[n - 1] - prefix[b];
			if (a > 0) p += prefix[a - 1];
			int wi = a - 1;
			if (wi < 0) wi += n;
			ll r2 = p + w[wi] + ds + dd;
			cout << min(r1, r2) << endl;
		}
	}	
}
