// https://open.kattis.com/problems/dicegame
#include <iostream>

using namespace std;

int main() {
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int s1 = a1 + b1 + a2 + b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int s2 = a1 + b1 + a2 + b2;
	if (s1 == s2) {
		cout << "Tie\n";
	} else if (s1 < s2) {
		cout << "Emma\n";
	} else {
		cout << "Gunnar\n";
	}
}
