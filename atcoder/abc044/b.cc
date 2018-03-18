// https://abc044.contest.atcoder.jp/tasks/abc044_b
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a[26];
	for (int i = 0; i < 26; i++) a[i] = 0;
	for (auto c : s) a[c - 'a']++;
	bool ok = true;
	for (int i = 0; i < 26; i++)
		if (a[i] % 2) ok = false;
	cout << (ok ? "Yes\n" : "No\n");
}
