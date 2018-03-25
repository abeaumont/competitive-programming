// https://www.hackerrank.com/challenges/simple-text-editor
#include <iostream>
#include <stack>

using namespace std;

typedef stack<string> s;

int main() {
	int q;
	cin >> q;
	s st;
	string s;
	while (q--) {
		int t, k;
		string w;
		cin >> t;
		switch (t) {
		case 1:
			cin >> w;
			st.push(s);
			s.append(w);
			break;
		case 2:
			cin >> k;
			st.push(s);
			s = s.substr(0, s.size() - k);
			break;
		case 3:
			cin >> k;
			cout << s[k - 1] << endl;
			break;
		default:
			s = st.top();
			st.pop();
		}
	}
}
