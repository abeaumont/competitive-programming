// https://uva.onlinejudge.org/external/1/100.pdf
#include <iostream>

using namespace std;

int collatz(int n) {
	int i = 1;
	while (n > 1) {
		if (n % 2) n = n * 3 + 1;
		else n >>= 1;
		i++;
	}
	return i;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		int m = 0;
		for (int i = min(a, b); i <= max(a, b); i++) m = max(m, collatz(i));
		cout << a << " " << b << " " << m << endl;
	}
}
