// https://open.kattis.com/problems/railroad2
#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	cout << (y % 2 ? "impossible\n" : "possible\n");
}
