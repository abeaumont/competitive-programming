// https://open.kattis.com/problems/babelfish
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, string> m;
	while (true) {
		string s;
		getline(cin, s);
		if (!s.size()) break;
		istringstream in(s);
		string s1, s2;
		in >> s1 >> s2;
		m[s2] = s1;
	}
	string s;
	while (true) {
		getline(cin, s);
		if (cin.eof()) break;
		if (m.count(s)) {
			cout << m.find(s)->second << endl;
		} else {
			cout << "eh\n";
		}
	}
}
