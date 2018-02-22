// https://open.kattis.com/problems/raggedright
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int m = 0;
	while (true) {
		string s;
		getline(cin, s);
		int k = s.size();
		if (!k) break;
		m = max(m, k);
		v.push_back(k);
	}
	int r = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		r += (m - v[i]) * (m - v[i]);
	}
	cout << r << endl;
}
