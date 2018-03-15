// https://open.kattis.com/problems/timebomb
#include <iostream>

using namespace std;

int main() {
	string s[5];
	int a = 0;
	for (int i = 0; i < 5; i++) getline(cin, s[i]);
	for (int i = 0; i < s[0].size(); i += 4) {
		if (s[0].substr(i, 3) == "***" &&
				s[1].substr(i, 3) == "* *" &&
				s[2].substr(i, 3) == "* *" &&
				s[3].substr(i, 3) == "* *" &&
				s[4].substr(i, 3) == "***")
			a *= 10;
		else if (s[0].substr(i, 3) == "  *" &&
						 s[1].substr(i, 3) == "  *" &&
						 s[2].substr(i, 3) == "  *" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "  *")
			a = a * 10 + 1;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "  *" &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "*  " &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 2;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "  *" &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 3;
		else if (s[0].substr(i, 3) == "* *" &&
						 s[1].substr(i, 3) == "* *" &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "  *")
			a = a * 10 + 4;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "*  " &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 5;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "*  " &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "* *" &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 6;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "  *" &&
						 s[2].substr(i, 3) == "  *" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "  *")
			a = a * 10 + 7;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "* *" &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "* *" &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 8;
		else if (s[0].substr(i, 3) == "***" &&
						 s[1].substr(i, 3) == "* *" &&
						 s[2].substr(i, 3) == "***" &&
						 s[3].substr(i, 3) == "  *" &&
						 s[4].substr(i, 3) == "***")
			a = a * 10 + 9;
		else {
			a = -1;
		}
	}
	if (a < 0 || a % 6) cout << "BOOM!!\n";
	else cout << "BEER!!\n";
}

