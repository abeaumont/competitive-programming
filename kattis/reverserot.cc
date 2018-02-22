// https://open.kattis.com/problems/reverserot
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	while (true) {
		int r;
		string s;
		cin >> r;
		if (!r) break;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			int x;
			switch(s[i]) {
			case '.':
				x = 27;
				break;
			case '_':
				x = 26;
				break;
			default:
				x = s[i] - 'A';
			}
			x = (x + r) % 28;
			switch(x) {
			case 27:
				s[i] = '.';
				break;
			case 26:
				s[i] = '_';
				break;
			default:
				s[i] = char('A' + x);
			}
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}
