// https://abc043.contest.atcoder.jp/tasks/abc043_b
#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;

int main() {
	string s;
	cin >> s;
	vc v;
	for (auto c : s) {
		if (c == 'B') {
			if (!v.empty()) v.pop_back();
		} else v.push_back(c);
	}
	for (auto c : v) cout << c;
	cout << endl;
}
