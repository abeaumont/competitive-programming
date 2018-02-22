// https://open.kattis.com/problems/sevenwonders
#include <iostream>

using namespace std;

int main() {
	int t, g, c;
	t = g = c = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'T': t++; break;
		case 'C': c++; break;
		case 'G': g++; break;
		}
	}
	int m = min(min(t, g), c);
	cout << t * t + g * g + c * c + m * 7 << endl;
}
