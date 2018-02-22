// https://open.kattis.com/problems/plantingtrees
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] + i > m) m = v[i] + i;
	}
	cout << m + 2 << endl;
}
