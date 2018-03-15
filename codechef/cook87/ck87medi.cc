// https://www.codechef.com/COOK87/problems/CK87MEDI
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int j = 0; j < n; j++) cin >> v[j];
		sort(v.begin(), v.end());
		cout << v[(n + k)/2] << endl;
	}
}
