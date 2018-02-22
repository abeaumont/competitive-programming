// https://open.kattis.com/problems/mirror
#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int r, c;
		cin >> r >> c;
		vvc v(r);
		for (int j = 0; j < r; j++) {
			v[j] = vc(c);
			for (int k = 0; k < c; k++) {
				cin >> v[j][k];
			}
		}
		cout << "Test " << i + 1 << endl;
		for (int j = r - 1; j >= 0; j--) {
			for (int k = c - 1; k >= 0; k--) {
				cout << v[j][k];
			}
			cout << endl;
		}
	}
}
