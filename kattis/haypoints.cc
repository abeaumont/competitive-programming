// https://open.kattis.com/problems/haypoints
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> msi;

int main() {
	int m, n;
	cin >> m >> n;
	msi a;
	for (int i = 0; i < m; i++) {
		string s;
		int x;
		cin >> s >> x;
		a[s] = x;
	}
	for (int i = 0; i < n; i++) {
		int c = 0;
		while (true) {
			string s;
			cin >> s;
			if (s == ".") {
				cout << c << endl;
				break;
			}
			if (a.count(s)) c+= a[s];
		}
	}
}
