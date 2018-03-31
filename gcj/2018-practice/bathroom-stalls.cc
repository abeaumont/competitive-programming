// https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000652
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;

ii s(int n, int k) {
	if (k == 1) return make_tuple(n / 2, (n - 1) / 2);
	if (n % 2 || k % 2 == 0) return s(n / 2, k / 2);
	return s((n - 1) / 2, k / 2);
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, k, l, r;
		cin >> n >> k;
		tie(l, r) = s(n, k);
		cout << "Case #" << i << ": " << l << " " << r << endl;
	}
}
