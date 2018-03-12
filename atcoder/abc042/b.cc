// https://abc042.contest.atcoder.jp/tasks/abc042_b
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;

int main() {
	int n, l;
	cin >> n >> l;
	vs v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (auto s : v) cout << s;
	cout << endl;
}
