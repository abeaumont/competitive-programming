// https://open.kattis.com/problems/peragrams
#include <iostream>

using namespace std;

int main() {
	int x[26];
	for (int i = 0; i < 26; i++) x[i] = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		x[s[i]-'a']++;
	}
	int c = 0;
	for (int i = 0; i < 26; i++)
		if (x[i] % 2) c++;
	cout << max(0, c - 1) << endl;
}
