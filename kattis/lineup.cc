// https://open.kattis.com/problems/lineup
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	bool decreasing = true;
	bool increasing = true;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			increasing = false;
		} else {
			decreasing = false;
		}
		if (!increasing && !decreasing) break;
	}
	if (increasing) {
		cout << "INCREASING\n";
	} else if (decreasing) {
		cout << "DECREASING\n";
	} else {
		cout << "NEITHER\n";
	}
}
