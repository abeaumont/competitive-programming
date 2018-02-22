// https://open.kattis.com/problems/quickbrownfox
#include <cctype>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int i = 0; i < t; i++) {
		bool xs[26];
		for (int j = 0; j < 26; j++) xs[j] = false;
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			char c = tolower(s[j]);
			if (c >= 'a' && c <= 'z') {
				xs[c - 'a'] = true;
			}
		}
		bool missing = false;
		for (int j = 0; j < 26; j++) {
			if (!xs[j]) {
				missing = true;
				break;
			}
		}
		if (missing) {
			cout << "missing ";
			for (int j = 0; j < 26; j++) {
				if (!xs[j]) {
					cout << char('a' + j);
				}
			}
			cout << endl;
		} else {
			cout << "pangram\n";
		}
	}
}
