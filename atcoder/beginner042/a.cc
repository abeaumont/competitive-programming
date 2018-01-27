// https://abc042.contest.atcoder.jp/tasks/abc042_a
#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		if (x == 5) a++;
		else if (x == 7) b++;
	}
	if (a == 2 && b == 1) cout << "YES\n";
	else cout << "NO\n";
}
