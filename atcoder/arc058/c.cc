// https://arc058.contest.atcoder.jp/tasks/arc058_a
#include <iostream>

using namespace std;

int n, k, x, a[10];

bool f(int n) {
	while (n > 0) {
		if (a[n % 10]) return true;
		n /= 10;
	}
	return false;
}

int main() {
	cin >> n >> k;
	while (k--) {
		cin >> x;
		a[x] = true;
	}
	while (f(n)) n++;
	cout << n << endl;
}
