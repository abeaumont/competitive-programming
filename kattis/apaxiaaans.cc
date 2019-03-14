// https://open.kattis.com/problems/apaxiaaans
#include <iostream>

using namespace std;

int main () {
	string s;
	cin >> s;
	string r;
	unsigned char ch = 0;
	for (int i = 0; i < s.size(); i++) {
		if (ch && s[i] == ch) continue;
		ch = s[i];
		r.push_back(ch);
	}
	cout << r << endl;
}
