// https://open.kattis.com/problems/deathknight
#include <iostream>

using namespace std;

bool s() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'C' && s[i+1] == 'D') {
			return false;
		}
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	int c = 0;
	for (int i = 0; i < k; i++) {
		if (s()) c++;
	}
	cout << c << endl;
}
