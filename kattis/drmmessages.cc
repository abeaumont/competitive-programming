// https://open.kattis.com/problems/drmmessages
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	cin >> s;
	int n = s.size() / 2;
	vi a(n), b(n);
	int c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - 'A';
		b[i] = s[i + n] - 'A';
		c += a[i];
		d += b[i];
	}
	for (int i = 0; i < n; i++) cout << char('A' + (a[i] + b[i] + c + d) % 26);
	cout << endl;
}
