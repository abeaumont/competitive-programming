// https://open.kattis.com/problems/icpcawards
#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<string> ss;

int main() {
	int n;
	cin >> n;
	string w[12];
	int i = 0;
	ss s;
	while (n-- && i < 12) {
		string c, t;
		cin >> c >> t;
		if (s.count(c)) continue;
		s.insert(c);
		w[i] = c + " " + t;
		i++;
	}
	for (int i = 0; i < 12; i++) cout << w[i] << endl;
}
