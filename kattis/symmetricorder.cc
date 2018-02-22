// https://open.kattis.com/problems/symmetricorder
#include <iostream>
#include <vector>

using namespace std;

int main() {
	for (int i = 1;; i++) {
		int n;
		cin >> n;
		if (!n) break;
		vector<string> v(n);
		for (int j = 0; j < n; j++) cin >> v[j];
		cout << "SET " << i << endl;;
		for (int j = 0; j < n; j += 2) cout << v[j] << endl;
		int end = n - 1;
		if (end % 2 == 0) end--;
		for (int j = end; j > 0; j -= 2) cout << v[j] << endl;
	}
}
