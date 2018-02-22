// https://open.kattis.com/problems/easiest
#include <iostream>

using namespace std;

int sum(int x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int minp(int x) {
	int sx = sum(x);
	for (int p = 11;;p++)
		if (sx == sum(p * x)) return p;
}


int main() {
	while(true) {
		int x;
		cin >> x;
		if (!x) break;
		cout << minp(x) << endl;
	}
}
