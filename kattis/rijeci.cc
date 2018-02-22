// https://open.kattis.com/problems/rijeci
#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	int a = 1;
	int b = 0;
	for (int i = 0; i < k; i++) {
		int t = a;
		a = b;
		b += t;
	}
	cout << a << " " << b << endl;
}
