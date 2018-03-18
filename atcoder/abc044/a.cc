// https://abc044.contest.atcoder.jp/tasks/abc044_a
#include <iostream>

using namespace std;

int main() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	if (n <= k) cout << n * x << endl;
	else cout << k * x + (n - k) * y << endl;
}
