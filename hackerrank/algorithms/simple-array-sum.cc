// https://www.hackerrank.com/challenges/simple-array-sum
#include <iostream>

using namespace std;

int main() {
	int n, x, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
	}
	cout << s << endl;
}
