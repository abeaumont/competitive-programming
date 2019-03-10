// http://codeforces.com/contest/935/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int c = 0;
	for (int i = 1; i <= n/2; i++)
		if ((n - i) % i == 0) c++;
	cout << c << endl;
}
