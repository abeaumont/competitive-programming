// https://open.kattis.com/problems/numbertree
#include <iostream>

using namespace std;

int main() {
	int h;
	string s;
	cin >> h >> s;
	int x = 2;
	for (int i = 0; i < h; i++) {
		x *= 2;
	}
	x--;
	int p = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') {
			x -= p;
			p *= 2;
		} else {
			x -= p + 1;
			p *= 2;
			p++;
		}
	}
	cout << x << endl;
}
