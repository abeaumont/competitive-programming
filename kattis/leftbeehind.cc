// https://open.kattis.com/problems/leftbeehind
#include <iostream>

using namespace std;

int main() {
	while (true) {
		int x, y;
		cin >> x >> y;
		if (!x && !y) break;
		if (x + y == 13) cout << "Never speak again.\n";
		else if (x == y) cout << "Undecided.\n";
		else if (x > y) cout << "To the convention.\n";
		else cout << "Left beehind.\n";
	}
}
