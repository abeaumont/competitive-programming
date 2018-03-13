// https://abc074.contest.atcoder.jp/tasks/abc074_b
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int a = min(k - x, x);
		sum += a * 2;
	}
	cout << sum << endl;
}
