// http://codeforces.com/contest/954/problem/A
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0;
	int i = 0;
	while (i < n - 1)
		if (s[i] == 'U' && s[i + 1] == 'R' || s[i] == 'R' && s[i + 1] == 'U') {
			i += 2;
			c++;
		} else i++;
	cout << n - c << endl;
}
