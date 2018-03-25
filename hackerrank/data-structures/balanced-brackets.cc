// https://www.hackerrank.com/challenges/balanced-brackets
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		stack<char> st;
		cin >> s;
		bool ok = true;
		for (auto c : s) {
			if (c == '{' || c == '(' || c == '[') {
				switch (c) {
				case '{': st.push('}'); break;
				case '(': st.push(')'); break;
				default: st.push(']');
				}
			} else if (!st.empty() && c == st.top()) {
				st.pop();
			} else {
				ok = false;
				break;
			}
		}
		if (ok && st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}
