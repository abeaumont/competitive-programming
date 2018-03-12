// https://abc043.contest.atcoder.jp/tasks/arc059_b
#include <iostream>

using namespace std;

int main() {
	int c[26];
	for (int i = 0; i < 26; i++) c[i] = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i] == s[i + 1]) {
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
		if (s[i] == s[i + 2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	if (s[s.size() - 2] == s[s.size() - 1]) {
		cout << s.size() - 1 << " " << s.size() << endl;
	} else {
		cout << "-1 -1\n";
	}
}
