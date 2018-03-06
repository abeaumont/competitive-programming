// https://www.codechef.com/MARCH18A/problems/MIXCOLOR
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int x = a[0];
		int d = 0;
		for (int i = 1; i < n; i++) {
			if (x == a[i]) d++;
			else x = a[i];
		}
		cout << d << endl;
	}
}
