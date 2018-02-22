// https://open.kattis.com/problems/soylent
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int x = n / 400;
		if (n % 400) x++;
		cout << x << endl;
	}
}
