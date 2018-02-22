// https://open.kattis.com/problems/engineeringenglish
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<string> set;
	while (true) {
		string l;
		getline(cin, l);
		if (l.empty()) break;
		istringstream in(l);
		bool first = true;
		while (true) {
			string s;
			in >> s;
			if (s.empty()) break;
			string t = s;
			transform(t.begin(), t.end(), t.begin(), ::tolower);
			if (first) first = false;
			else cout << " ";
			if (set.count(t)) cout << ".";
			else {
				set.insert(t);
				cout << s;
			}
		}
		cout << endl;
	}
}
