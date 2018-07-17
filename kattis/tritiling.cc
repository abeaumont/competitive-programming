// https://open.kattis.com/problems/tritiling
#include <iostream>

using namespace std;

const int N = 31;
int a[N];
int c[N];
int d[N];

void f() {
	d[0] = 1;
	a[1] = d[0] + c[0];
	for (int i = 2; i < N; i++) {
		a[i] = d[i - 1] + c[i - 1];
		c[i] = c[i - 2] + d[i - 2];
		d[i] = d[i - 2] + 2 * a[i - 1];
	}
}

int main() {
	int n;
	f();
	while (true) {
		cin >> n;
		if (n == -1) break;
		cout << d[n] << endl;
	}
}
