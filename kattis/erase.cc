// https://open.kattis.com/problems/erase
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[i] && n % 2) {
			cout << "Deletion failed\n";
			return 0;
		}
		if (s[i] != t[i] && !(n % 2)) {
			cout << "Deletion failed\n";
			return 0;
		}
	}
	cout << "Deletion succeeded\n";
}
