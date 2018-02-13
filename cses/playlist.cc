// https://cses.fi/problemset/task/1141/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int i = 0;
	int j = 0;
	int m = 1;
	unordered_set<int> s;
	while (j < n) {
		if (s.count(a[j])) {
			m = max(m, j - i);
			while (a[i] != a[j]) {
				s.erase(a[i++]);
			}
			i++;
		} else s.insert(a[j]);
		j++;
	}
	m = max(m, j - i);
	cout << m << endl;
}
