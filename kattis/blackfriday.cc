// https://open.kattis.com/problems/blackfriday
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int d[6];
	for (int i = 0; i < 6; i++) d[i] = 0;
	vector<int> v(n);;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[i] = x;
		d[x-1]++;
	}
	int best = -1;
	for (int i = 5; i >= 0; i--) {
		if (d[i] == 1) {
			best = i + 1;
			break;
		}
	}
	if (best > 0) {
		for (int i = 0; i < n; i++) {
			if (v[i] == best) {
				cout << i + 1 << endl;
				break;
			}
		}
	} else cout << "none\n";
}
