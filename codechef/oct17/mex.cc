// https://www.codechef.com/OCT17/problems/MEX/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vb v(200001, false);
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			v[s] = true;
		}
		int j = 0;
		while (k >= 0 && j <= 200000) {
			if (!v[j]) k--;
			if (k < 0) break;
			j++;
		}
		if (k > 0) {
			cout << 200000 + k << endl;
		} else {
			cout << j << endl;
		}
	}
}
