// https://open.kattis.com/problems/kemija08
#include <iostream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	string r;
	int i = 0;
	while (i < s.size()) {
		switch (s[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			i += 2;
		default:
			r.push_back(s[i++]);
		}
	}
	cout << r << endl;
}
