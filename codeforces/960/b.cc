// http://codeforces.com/contest/960/problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1001];

int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(abs(a[i] - x));
	}
	for (int i = 0; i < k1 + k2; i++) {
		int k = q.top();
		q.pop();
		if (k > 0) q.push(k - 1);
		else q.push(1);
	}
	ll s = 0;
	while (!q.empty()) {
		ll k = q.top();
		q.pop();
		s += k * k;
	}
	cout << s << endl;
}
