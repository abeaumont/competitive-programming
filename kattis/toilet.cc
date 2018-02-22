// https://open.kattis.com/problems/toilet
#include <iostream>

using namespace std;

typedef unsigned char u8;

int main() {
	string s;
	cin >> s;
	int c = 0;
	u8 status = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (status != s[i]) {
			c++;
		}
		if (s[i] != 'U') {
			c++;
		}
		status = 'U';
	}
	cout << c << endl;
	c = 0;
	status = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (status != s[i]) {
			c++;
		}
		if (s[i] != 'D') {
			c++;
		}
		status = 'D';
	}
	cout << c << endl;
	c = 0;
	status = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (status != s[i]) {
			c++;
		}
		status = s[i];
	}
	cout << c << endl;
}
