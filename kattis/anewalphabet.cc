// https://open.kattis.com/problems/anewalphabet
#include <cctype>
#include <iostream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	string r;
	for (int i = 0; i < s.size(); i++) {
		char c = tolower(s[i]);
		if (c >= 'a' && c <= 'z') {
			string map[26] = {
				"@",
				"8",
				"(",
				"|)",
				"3",
				"#",
				"6",
				"[-]",
				"|",
				"_|",
				"|<",
				"1",
				"[]\\/[]",
				"[]\\[]",
				"0",
				"|D",
				"(,)",
				"|Z",
				"$",
				"']['",
				"|_|",
				"\\/",
				"\\/\\/",
				"}{",
				"`/",
				"2"
			};
			r.insert(r.size(), map[c - 'a']);
		} else {
			r.push_back(c);
		}
	}
	cout << r << endl;
}
