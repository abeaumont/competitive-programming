// https://www.codechef.com/JAN18/problems/MAXSC
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vvi v(n);
		ll sum = 0;
		for (int j = 0; j < n; j++) {
			v[j] = vi(n);
			for (int k = 0; k < n; k++) cin >> v[j][k];
		}
		int p = 1000000001;
		for (int j = n - 1; j >= 0; j--) {
			int m = 0; 
			for (int k = 0; k < n; k++) if (v[j][k] > m && v[j][k] < p) m = v[j][k];
			sum += m;
			p = m;
		}
		cout << (p ? sum : -1) << endl;
	}
}
