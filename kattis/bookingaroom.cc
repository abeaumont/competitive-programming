// https://open.kattis.com/problems/bookingaroom
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int r, n;
	cin >> r >> n;
	vector<bool> v(r, false);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[x - 1] = true;
	}
	for (int i = 0; i < r; i++) {
		if (!v[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "too late\n";
}
