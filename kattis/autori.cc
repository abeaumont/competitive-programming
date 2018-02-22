// https://open.kattis.com/problems/autori
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	string r;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z') r.push_back(s[i]);
	cout << r << endl;
}
