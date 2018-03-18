// https://open.kattis.com/problems/guessinggame
#include <iostream>

using namespace std;

int main() {
	while (true) {
		int x;
		string s;
		cin >> x;
		getline(cin, s);
		if (!x) break;
		int m = 1, M = 10;
		while (true) {
			getline(cin, s);
			if (s == "right on") break;
			if (s == "too low") m = max(m, x + 1);
			else M = min(M, x - 1);
			cin >> x;
			getline(cin, s);
		}
		cout << (x >= m && x <= M ? "Stan may be honest\n" : "Stan is dishonest\n");
	}
}
