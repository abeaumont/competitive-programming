// https://arc098.contest.atcoder.jp/tasks/arc098_b
#include <bits/stdc++.h>

using namespace std;

int a[200001];
typedef long long ll;

int main() {
	ll n, k = 0, l = 1;
	ll s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll c = a[0];
	while (l < n) {
		if ((c + a[l]) == (c ^ a[l])) {
			c += a[l];
			l++;
		} else {
			s += l - k;
			c -= a[k];
			k++;
		}
	}
	ll z = l - k;
	s += z * (z + 1) / 2;
	cout << s << endl;
}
