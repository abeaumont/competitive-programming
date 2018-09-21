// https://www.codechef.com/OCT17/problems/CHEFCOUN/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		ll x = 4294967296LL / (n + 1);
		int mod = 4294967296LL % (n + 1);
		if (mod == 0) {
			for (int j = 0; j < n; j++) {
				if (j % 2 == 0) {
					cout << x - 1;
				} else {
					cout << x + 1;
				}
				if (j != n - 1) cout << " ";
			}
			return 0;
		}
		for (int j = 0; j < n; j++) {
			if (j < mod - 1) {
				cout << x + 1;
			} else {
				cout << x;
			}
			if (j != n - 1) cout << " ";
		}
		cout << endl;
	}
}
