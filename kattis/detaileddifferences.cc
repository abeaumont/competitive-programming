// https://open.kattis.com/problems/detaileddifferences
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		cout << s1 << endl << s2 << endl;
		for (int j = 0; j < s1.size(); j++) {
			cout << (s1[j] == s2[j] ? '.' : '*');
		}
		cout << endl;
		if (i < n - 1) cout << endl;
	}
}
