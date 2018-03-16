// https://open.kattis.com/problems/progressivescramble
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

string encrypt(const string &s) {
	vi a(s.size());
	string t(s.size(), ' ');
	for (int i = 0; i < s.size(); i++) a[i] = s[i] == ' ' ? 0 : s[i] - 'a' + 1;
	for (int i = 1; i < s.size(); i++) a[i] = (a[i] + a[i - 1]) % 27;
	for (int i = 0; i < s.size(); i++) t[i] = a[i] ? 'a' + a[i] - 1 : ' ';
	return t;
}

string decrypt (const string &s) {
	vi a(s.size());
	string t(s.size(), ' ');
	for (int i = 0; i < s.size(); i++) a[i] = s[i] == ' ' ? 0 : s[i] - 'a' + 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		a[i] -= a[i - 1];
		if (a[i] < 0) a[i] += 27;
	}
	for (int i = 0; i < s.size(); i++) t[i] = a[i] ? 'a' + a[i] - 1 : ' ';
	return t;
}

int main() {
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		if (s[0] == 'e') cout << encrypt(s.substr(2, s.size() - 2)) << endl;
		else cout << decrypt(s.substr(2, s.size() - 2)) << endl;
	}
}
