// https://open.kattis.com/problems/phonelist
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void s() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int j = 0; j < n; j++) {
		cin >> v[j];
	}
	sort(v.begin(), v.end());
	for (int j = 0; j < n - 1; j++) {
		if (v[j].size() > v[j+1].size()) continue;
		bool consistent = false;
		for (int k = 0; k < v[j].size(); k++) {
			if (v[j][k] != v[j+1][k]) {
				consistent = true;
				break;
			}
		}
		if (!consistent) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		s();
	}
}
