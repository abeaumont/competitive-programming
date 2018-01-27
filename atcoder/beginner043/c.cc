// https://abc043.contest.atcoder.jp/tasks/arc059_a
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	cin >> n;
	vi v(n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s += v[i];
	}
	int m = round(double(s) / double(n));
	s = 0;
	for (int i = 0; i < n; i++) {
		int d = v[i] - m;
		s += d * d;
	}
	cout << s << endl;
}
