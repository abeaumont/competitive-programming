// https://open.kattis.com/problems/backspace
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	string s2;
	for (auto c : s) {
		if (c == '<') {
			if (!s.empty()) s2.pop_back();
		} else s2.push_back(c);
	}
	cout << s2 << endl;
}
